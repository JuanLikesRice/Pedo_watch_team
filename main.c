#include <msp430.h>
#include <stdint.h>


void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      P1DIR |= 0x01;                            // P1.0 output
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode
}
/*
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
    //UCA0CTL0 |= UCMODE_1; //master
    UCA0BR0  |= 0x02; // /2 --> 500 khz OD THE SPI CLOCK
   //UCA0CTL0 |= UCCKPH + UCMSB + UCMODE_1; // 4-pin, 8-bit SPI master
   //UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
    //UCA0BR1 = 0; //
    //UCA0MCTL = 0; // No modulation
    UCA0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**
    P1SEL  |= BIT1;                               // Just setup for the pins (1.1 is the SOMI)
    P1SEL2 |= BIT1;
    P1SEL  |= BIT2;                               // Just setup for the pins (1.2 is the SIMO data line)
    P1SEL2 |= BIT2;
    P1SEL  |= BIT4;                               // Just setup for the pins (1.4 is the USCI clock)
    P1SEL2 |= BIT4;
    P1DIR |= BIT5;// chip select
    P1OUT |= (BIT5);// VDD - on
}



unsigned int read1step(void){
    unsigned int value1;
    P1OUT |= (BIT5);// VDD - on
    //address = address_in;
    //address += 0x80; // write flag
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= 0x8E; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  0x00; //value
    value1 = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));

    P1OUT |= (BIT5);// VDD - on
    //address = address_in;
    //address += 0x80; // write flag
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= 0x8F; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  0x00; //value
    //value1 = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));


    return value1;               }



void write1byte( unsigned int address_in, unsigned int value_in){
    P1OUT |= (BIT5);// VDD - on
    //message[0] |= 0x80; // write flag
    //UCA0TXBUF= 0x00; //us3ed to be dummy var
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= address_in; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  value_in; //value
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));

}
/*
if (address_in == 0x0E){
    spi_setup();
    P1OUT |= (BIT5);// VDD - on
    address = address_in+0x01;
    //address += 0x80; // write flag
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= address; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  address; //value
    //value = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
} */


volatile  unsigned int value;
volatile unsigned int value1;
volatile unsigned int value2;
volatile unsigned int value3;
volatile unsigned int value4;
unsigned int read1byte( unsigned int address_in){
  unsigned int value;





    //volatile
    unsigned int address;
    P1OUT |= (BIT5);// VDD - on
    address = address_in;
    address += 0x80; // write flag
//    while (!(IFG2 & UCA0TXIFG));

    P1OUT &= (~BIT5); //Off nCs
    __delay_cycles(4);
    UCA0TXBUF= address; ///address
    value1 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  address; //value
    value2 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    //UCA0TXBUF=  address; //value
    value3 = UCA0RXBUF;
    //while (!(IFG2 & UCA0RXIFG));
    //value4 = UCA0RXBUF;

 //   UCA0TXBUF=  0x00; //value
   // value = UCA0RXBUF;
    //while (!(IFG2 & UCA0RXIFG));
    //value2 = UCA0RXBUF;
    __delay_cycles(4);
    P1OUT |= (BIT5);// VDD - on nCS high
    __delay_cycles(100);


    return value3;               }








unsigned int low;
unsigned int high;
unsigned int steps;


void main(void)
  {spi_setup();
delay_setup();
 __delay_cycles(10);
// delay(10000);

write1byte(0x1B,0x80); //CNTL2);
//delay(1000);
__delay_cycles(100);

write1byte(0x1A,0x00);//CNTL1
write1byte(0x41,0x10); //THSHOLD
write1byte(0x42,0x27);

write1byte(0x44,0x2C);//CNTL2
write1byte(0x37,0x7B);//CNTL
write1byte(0x26,0x00);//INC7
write1byte(0x20,0x00);//INC1 x20
write1byte(0x24,0x00);//INC5 x20


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

high =  read1byte(0x11);



while(1)
{

    //delay(10);
//    delay(1000);
    //read5 = read1byte(0x1A);
  //  delay(10);
9    __delay_cycles(10000);

    //low +=  read1step();//KX126_PED_STEP_L);
// 0f -
    low =  read1byte(0x0E);//KX126_PED_STEP_L);
    high = read1byte(0x0F);

    steps += low;
    //low =  read1byte(0x0E);//KX126_PED_STEP_L);
    //low =  read1byte(0x0E);//KX126_PED_STEP_L);
//    low =  read1byte(0x0E);//KX126_PED_STEP_L);

    //__delay_cycles(1000000);

    //high =  read1byte(0x0F);//KX126_PED_STEP_L);
   // __delay_cycles(1000000);

//    high =  read1byte(0x0E);
  //  high =  read1byte(0x0E);
    //high =  read1byte(0x0E);
    // if (high > low) {
   //steps +=low;

     //}//
//    low =  read1byte(0x0E);//KX126_PED_STEP_L);
    //high = read1byte(0x0F);//KX126_PED_STEP_H);
    //high = (read1byte(0x00F)<<8);//KX126_PED_STEP_H);
//    if(low > 194){
      //  low-=194;
    //high_rs();
    //steps+= low;


 //    high = read1byte(0x0F);
    //}

  //  read6 = high+low;
    //if ( read6 != 0) {
     //read7+= read6;
     //}

    //read6 = read_steps() ;
//   var1 = read1byte(CNTL1_4);
    //read3 = read1byte(0x37);

  // var2 = read1byte(0x11);//who_asked);
  // var1 = read1byte(0x1B);
  // read1 = read1byte(0x1B);
   //write1byte(0x43,0x10 +read1byte(0x43));
   //   read7 = read_steps();

   //var3 = read_steps();
   //var6 = read1byte(CNTL1_2);
   //read1byte(CNTL1_4);//read_steps();//read1byte(who_asked);
  // if (allsteps != 0){
    //   somesteps += allsteps;

   //}
}
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
