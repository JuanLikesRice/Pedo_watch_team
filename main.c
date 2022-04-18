#include <msp430.h>
#include <stdint.h>

/*
void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      //                           // P1.0 output
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode
}

void delay(unsigned int time){
    CCR0 += time;
    __bis_SR_register(LPM0_bits + GIE);
   CCR0 += time;}//}
*/

void spi_setup(void)
{   WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    UCA0CTL1 |= UCSWRST;                          // Enable SPI software rezet
    UCA0CTL1 |= UCSSEL_2; // SMCLK clock
    UCA0CTL0 |= UCCKPH;//phase
    UCA0CTL0 |= UCSYNC; // spi
    UCA0CTL0 |= UCMST; //master
    UCA0CTL0 |= UCMSB; //MSB
    UCA0BR0  |= 0x02; // /2 --> 500 khz OD THE SPI CLOCK
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    P1SEL  |= BIT1;                               // Just setup for the pins (1.1 is the SOMI)
    P1SEL2 |= BIT1;
    P1SEL  |= BIT2;                               // Just setup for the pins (1.2 is the SIMO data line)
    P1SEL2 |= BIT2;
    P1SEL  |= BIT4;                               // Just setup for the pins (1.4 is the USCI clock)
    P1SEL2 |= BIT4;
    P1DIR |= 0x01;
    P1DIR |= BIT0;// chip select
    P1OUT |= (BIT0);// VDD - on
}



void init_buttons(void) {
    //  WDTCTL = WDTPW + WDTHOLD;
    /*
        P2DIR &= ~(BIT2); // set to input
        //P2REN |= BIT2; // enable pullup/down resistors
        //P2OUT |= BIT2; // set resistors to pull up
        P2IES |= BIT2; // listen for high to low transitions
        P2IFG &=  ~(BIT2); // clear any pending interrupts
        P2IE |= BIT2; // enable interrupts for these pins
*/

        P2DIR |= 0x00;
         P2OUT =  0x04;
         P2REN |= 0x04;
         P2IE |= 0x04;
         P2IES |= 0x04;
         //P2IFG &= ~0x04;

    /*P2DIR &= ~(BIT2); // set to input
    P2REN |= BIT2; // enable pullup/down resistors
    P2OUT |= BIT2; // set resistors to pull up
    P2IES |= BIT2; // listen for high to low transitions
    P2IFG &=  ~(BIT2); // clear any pending interrupts
    P2IE |= BIT2; // enable interrupts for these pins

    P2DIR = 0x00;
        P2OUT =  0x04;
        P2REN |= 0x04;
        P2IE |= 0x04;
        P2IES |= 0x04;
        P2IFG &= ~0x04;


    P2SEL &= (~BIT2); // Set P2.1 SEL as GPIO
    P2DIR &= (~BIT2); // Set P2.1 SEL as Input
    P2IES |= (BIT2); // Falling Edge 1 -> 0
    P2IFG &= (~BIT1); // Clear interrupt flag for P2.1
    P2IE |= (BIT2); // Enable interrupt for P2.1
   // __enable_interrupt(); // Enable Global Interrupts
*/



}



void write1byte( unsigned int address_in, unsigned int value_in){
    P1OUT |= (BIT0);// VDD - on

    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT0); //Off nCs
    UCA0TXBUF= address_in; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  value_in; //value
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT0);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));

}


volatile  unsigned int value;
volatile unsigned int value1;
volatile unsigned int value2;
volatile unsigned int value3;
volatile unsigned int value4;

unsigned int read1byte( unsigned int address_in){
  unsigned int value;
    //volatile
    unsigned int address;
    P1OUT |= (BIT0);// VDD - on
    address = address_in;
    address += 0x80; // write flag
    P1OUT &= (~BIT0); //Off nCs
    __delay_cycles(4);
    UCA0TXBUF= address; ///address
    value1 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  address; //value
    value2 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    value3 = UCA0RXBUF;
    __delay_cycles(4);
    P1OUT |= (BIT0);// VDD - on nCS high
    __delay_cycles(100);


    return value3;               }








unsigned int low;
unsigned int high;
unsigned int steps;


void main(void)
  {spi_setup();
//delay_setup();
 __delay_cycles(10);

write1byte(0x1B,0x80); //CNTL2);
__delay_cycles(100);

write1byte(0x1A,0x00);//CNTL1

write1byte(0x44,0x2C);//CNTL2
write1byte(0x37,0x7B);//CNTL

write1byte(0x41,0x06); //THSHOLD low
write1byte(0x42,0x00); // ths high steps

write1byte(0x24,0x20);//INC5 INT2 Enabled, active low
write1byte(0x25,0x20);//INC6
write1byte(0x26,0x20);//INC7 //step wm enabled INT 2
// high =  read1byte(0x26);

write1byte(0x20,0x00);//INC1 x20

write1byte(0x43,0x66);//PED_CENTL1);
write1byte(0x44,0x2C);//PED_CENTL2);
write1byte(0x45,0x17);//PED_CENTL3);
write1byte(0x46,0x1F);//PED_CENTL4);
write1byte(0x47,0x24);//PED_CENTL5);
write1byte(0x48,0x13);//PED_CENTL6);
write1byte(0x49,0x0B);//PED_CENTL7);
write1byte(0x4A,0x08);//PED_CENTL8);
write1byte(0x4B,0x19);//PED_CENTL9);
write1byte(0x4C,0x1C);//PED_CENTL10);

write1byte(0x1A,0xC2);//CNTL1
__delay_cycles(100);
//delay(100);

init_buttons();

while(1)
{

    if ((P2IN & BIT2) == 0) {
        __delay_cycles(100000);
            low =  read1byte(0x0E);//KX126_PED_STEP_L);
             high = read1byte(0x0F);
             steps += low;
    }

    //__bis_SR_register(LPM3_bits + GIE);
    __delay_cycles(10000);


}
}


/*
//#pragma vector=PORT2_VECTOR
//__interrupt void Port_2(void)

// Port 2 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT2_VECTOR
__interrupt void button(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT2_VECTOR))) button (void)
#else
#error Compiler not supported!
#endif
{   //buttons are used for changing between states
   // P2IFG &= ~(BIT2) ;
    __delay_cycles(100000);

    //if ((P2IN & BIT2) == 0) {
        low =  read1byte(0x0E);//KX126_PED_STEP_L);
         high = read1byte(0x0F);
         steps += low;

         P2IFG &= ~0x04;
//         __bis_SR_register(LPM4_bits);
         //__bic_SR_register_on_exit(LPM4_bits);

   // }

    __bic_SR_register_on_exit(LPM3_bits);
}


/*

__interrupt void Port_2(void)
{
    P2IFG &= ~0x04;

    if ((P2IN & 0x04) == 0) {//red
        low =  read1byte(0x0E);//KX126_PED_STEP_L);

            high = read1byte(0x0F);

            steps += low;


    }
//    P2IFG &= ~(BIT2);




    __bic_SR_register_on_exit(LPM3_bits);



//flag = 1;
P2IFG &= (~BIT2); // P2.1 IFG clear
}







/*
// Timer A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  __bic_SR_register_on_exit(LPM0_bits);
}
*/
