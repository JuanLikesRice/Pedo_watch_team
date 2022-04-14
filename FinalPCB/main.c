#include <msp430.h>
#include <stdint.h>
#include <stdio.h>


void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      P1DIR |= 0x01;                            // P1.0 output
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode
}
void delay(unsigned int time){
    //unsigned int timer;
    //for (timer=0;timer<time; timer++){
    CCR0 += time;
    __bis_SR_register(LPM0_bits + GIE);
    CCR0 += time;
}

void spi_setup(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    UCB0CTL1 |= UCSWRST;      // Enable SPI software rezet
    UCB0CTL1 |= UCSSEL_2;     // SMCLK clock
    UCB0CTL0 |= UCSYNC;       //spi mode
    UCB0CTL0 |= UCMODE_1;     //master
    UCB0CTL0 |= UCMST;        //master
    UCB0CTL0 |= UCMSB;        //MSB


    UCB0BR0  |= 0x01; // /2 --> 1MGhz OD THE SPI CLOCK
   //UCA0CTL0 |= UCCKPH + UCMSB + UCMODE_1; // 4-pin, 8-bit SPI master
   //UCA0CTL0 |= UCCKPH + UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master
    //UCA0BR1 = 0; //
    //UCA0MCTL = 0; // No modulation
    UCB0CTL1 &= ~UCSWRST; // **Initialize USCI state machine**

    P1SEL  |= BIT7;                                 // Just setup for the pins (1.7 is the D_SIMO)
    P1SEL2 |= BIT7;
//    P1SEL  |= BIT2;                               // Just setup for the pins (1.2 is the SIMO data line)
//    P1SEL2 |= BIT2;
    P1SEL  |= BIT5;                                 //Just setup for the pins (1.5 is the D_CLK)
    P1SEL2 |= BIT5;
    P1DIR  |= BIT4;                                 // chip select for display
    P1OUT  |= (BIT4);                               // VDD - on

    P2DIR  |= BIT5;                                 // chip select for display
    P2OUT  &= ~(BIT5);                              //Set Command

    P1DIR |= BIT0; //ReSet Pin
}

//4-line serial interface II
void write1byte( uint8_t *message){
//    P1OUT &= ~(BIT4);
//    UCB0TXBUF= message[0]; ///address
//    P1OUT |= (BIT4);
//    while (!(IFG2 & UCB0TXIFG));
//    P1OUT &= ~(BIT4);
////    while (!(IFG2 & UCB0TXIFG));
//    UCB0TXBUF=  message[1]; //value
//    P1OUT |= (BIT4);
//    while (!(IFG2 & UCB0TXIFG));
//    P1OUT &= ~(BIT4);
////    while (!(IFG2 & UCB0TXIFG));
//    P1OUT |= (BIT4); //Turn on
    int i = 0, o =0;
    for(;o<135;o++){
        for(;i<180; i++){
            UCB0TXBUF= message[0]; ///address
            UCB0TXBUF= message[1]; ///address
        };
    };
}

void commandSetup(int8_t *message){
    int i=0;
    while(message[i] != NULL){
        UCB0TXBUF= message[0];
        i++;
    }
}

uint8_t color[] = {0xF1,0xF2}; // 1111 001 1111 0010
uint8_t color2[] = {0x00,0x00};
uint8_t SPI2EN[] = {0x00,0xE7};
uint8_t SPI2ENCON[] = {0x00,0x00};

uint8_t SWRESET[] = {0x00,0x01,NULL}; //Software Reset - 163
uint8_t SLPIN[] = {0x00,0x10,NULL};   //Sleep in - 182
uint8_t SLPOUT[] = {0x00,0x11,NULL};  //Sleep out - 184

uint8_t COLMOD[] = {0x00,0x3A,0x00,0x03,NULL}; //COLMOD


int main(void)
{
    spi_setup();
    delay_setup();

    P1OUT &= (~BIT0); //Reseting
    delay(10000);
    P1OUT |= BIT0; //Set Reset to high

    P1OUT &= (~BIT4);                //Turn off Chip select to enable transmission.
    P2OUT  &= ~(BIT5);               //Set COMMAND
    write1byte(SPI2EN);
    P2OUT  |= (BIT5);                //Set DATA
    write1byte(SPI2ENCON);
    P1OUT |= (BIT4);                // Turn on chip select to disable transmission.

    P1OUT &= (~BIT4);                //Turn off Chip select to enable transmission.
    P2OUT  &= ~(BIT5);               //Set COMMAND
    write1byte(SPI2EN);
    P2OUT  |= (BIT5);                //Set DATA
    write1byte(SPI2ENCON);
    P1OUT |= (BIT4);                // Turn on chip select to disable transmission.


    while(1)
    {

        P2OUT  |= (BIT5);                              //Set DATA
        int i = 0, o =0;
        P1OUT &= (~BIT4);                               //Turn off Chip select to enable transmission.
        write1byte(color);
        P1OUT |= (BIT4);                                // Turn chip select on.
        for(i=0;i<10;i++)
            delay(10000);
    }
}




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



