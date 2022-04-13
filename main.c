#include <msp430.h>
#include <stdint.h>



uint8_t CNTL2[] =       {0x1B,0x80};//,0x00,0x00};
uint8_t INC7[] =        {0x27,0x00};//,0x00,0x00};
uint8_t INC1[] =        {0x20,0x00};//,0x00,0x00};
uint8_t INC5[] =        {0x24,0x00};//,0x00,0x00};
uint8_t LPCNTL =        {0x37,0x20};

uint8_t PED_CENTL1[] =    {0x43,0x10};
uint8_t PED_CENTL2[] =    {0x44,0x2C};
uint8_t PED_CENTL3[] =    {0x45,0x17};
uint8_t PED_CENTL4[] =    {0x46,0x1F};
uint8_t PED_CENTL5[] =    {0x47,0x0A};
uint8_t PED_CENTL6[] =    {0x48,0x13};
uint8_t PED_CENTL7[] =    {0x49,0x0B};
uint8_t PED_CENTL8[] =    {0x4A,0x08};
uint8_t PED_CENTL9[] =    {0x4B,0x19};
uint8_t PED_CENTL10[]=    {0x4C,0x1C};

uint8_t ODCNTL[] =        {0x4C,0x1C};
uint8_t CNTL1[] =         {0x4C,0x1C};



//uint8_t CNTL1[] =       {0x1A,0x00};//,0x00,0x00};
uint8_t PED_STPWM_L[] = {0x41,0x10};//,0x00,0x00};
//uint8_t PED_STPWM_H[] = {0x42,0x27};//,0x00,0x00};
uint8_t PED_CNTL2[] =   {0x44,0x2C};//,0x00,0x00};
uint8_t LP_CNTL[] =     {0x37,0x7B};//,0x00,0x00};


void spi_setup(void)
{   WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    UCA0CTL1 |= UCSWRST;                          // Enable SPI software rezet
    UCA0CTL1 |= UCSSEL_2; // SMCLK clock
    UCA0CTL0 |= UCSYNC; // spi
    UCA0CTL0 |= UCMST; //master
    UCA0CTL0 |= UCMSB; //MSB
    UCA0CTL0 |= UCMODE_1; //master

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


    P1DIR |= BIT5;
    P1OUT |= (BIT5);// VDD - on
}


void write2sen( uint8_t *message){
    /*
    P1OUT |= (BIT5);// VDD - on
    message[0] |= 0x80;
    UCA0TXBUF= 0x00;
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= message[0];
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF=  message[1];
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on
    */
/*
    unsigned int byte1;
     //P1OUT &= (~BIT5); // Gnd - off
     message[0] |= 0x80;
     for (byte1=0;byte1<2; byte1++){//send 32 bit frame in 8 bit chunks
         if (byte1 == 0){P1OUT &= (~BIT5);}// VDD - on}
         while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
         UCA0TXBUF=message[byte1];
         //if (byte1 == 2){P1OUT |= (BIT5);}// VDD - on}
         //while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
     }
      // Gnd - off
     //if (wait_focompletion)r_
     P1OUT |= (BIT5);// VDD - on
     */

    P1OUT |= (BIT5);// VDD - on
    message[0] |= 0x80; // write flag
    //UCA0TXBUF= 0x00; //us3ed to be dummy var

    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= message[0]; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  message[1]; //value
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));

//     __delay_cycles(100);
}



uint8_t read( uint8_t *message){
    /*
    P1OUT |= (BIT5);// VDD - on
    message[0] |= 0x80;
    UCA0TXBUF= 0x00;
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= message[0];
    while (!(IFG2 & UCA0TXIFG));
    UCA0TXBUF=  message[1];
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on
    */
/*
    unsigned int byte1;
     //P1OUT &= (~BIT5); // Gnd - off
     message[0] |= 0x80;
     for (byte1=0;byte1<2; byte1++){//send 32 bit frame in 8 bit chunks
         if (byte1 == 0){P1OUT &= (~BIT5);}// VDD - on}
         while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
         UCA0TXBUF=message[byte1];
         //if (byte1 == 2){P1OUT |= (BIT5);}// VDD - on}
         //while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
     }
      // Gnd - off
     //if (wait_focompletion)r_
     P1OUT |= (BIT5);// VDD - on
     */
    volatile uint8_t received_ch;
    P1OUT |= (BIT5);// VDD - on
    //message[0] |= 0x80; // write flag
    //UCA0TXBUF= 0x00; //us3ed to be dummy var

    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= message[0]; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  0x00; //value
    received_ch = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
return received_ch;
//     __delay_cycles(100);
}






//uint8_t
void write2sen2( uint8_t *message){
    volatile uint8_t received_ch;
    unsigned int byte1;
    for (byte1=0;byte1<2; byte1++){//send 32 bit frame in 8 bit chunks
        //if (byte1 == 0){//P1OUT &= (~BIT5);
        //UCA0TXBUF=0x00; }
        if (byte1 == 0){
            P1OUT &= (~BIT5);
        UCA0TXBUF=message[byte1];
        }
        else{
        UCA0TXBUF=0x00;
        received_ch = UCA0RXBUF;
}
        //UCA0TXBUF=message[byte1];
        if (byte1 == 2){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0TXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on
    __delay_cycles(10);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
}







uint8_t hello;
//volatile char received_ch;
uint8_t PED_STPWM_H[] = {0x42,0x27};//,0x00,0x00};

void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      P1DIR |= 0x01;                            // P1.0 output
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode
}
void delay(unsigned int time){
    unsigned int timer;
    for (timer=0;timer<time; timer++){
        __bis_SR_register(LPM0_bits + GIE);
        CCR0 += 100;}}

int main(void)
 {spi_setup();
 delay_setup();

write2sen(PED_STPWM_H);

while(1)
{

 //   write2sen(PED_STPWM_H);
   hello = read(PED_STPWM_H);

    //write2sen2(PED_STPWM_H);

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









///*










/*
void write2sen2( uint8_t *message){
    volatile char received_ch;

    unsigned int byte1;

    for (byte1=0;byte1<4; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);
        UCA0TXBUF=message[byte1];
        }
        else{


        UCA0TXBUF=0x00;
        received_ch = UCA0RXBUF;
}
        //UCA0TXBUF=message[byte1];
        if (byte1 == 4){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0RXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    //__delay_cycles(10000);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
    //return received_ch;
}




uint8_t read2sen(uint8_t *message){
    volatile char received_ch;
    unsigned int byte1;

    UCA0TXBUF=message[0];
    while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    P1OUT &= (~BIT5);
    UCA0TXBUF= message[0];
    //if (byte1 == 3){
    // while (!(IFG2 & UCA0RXIFG)); // USCI_A0 RX Received?
    //received_ch = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    UCA0TXBUF= 0x13;
    received_ch = UCA0RXBUF;
    //P1OUT |= (BIT5);// VDD - on
    while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
    P1OUT |= (BIT5);// VDD - on


    /*
    P1OUT &= (~BIT5);
    UCA0TXBUF=message[0]; //start spi read for one byte
    while (!(IFG2 & UCA0RXIFG)); // USCI_A0 TX buffer ready?
    received_ch = UCA0RXBUF;
    P1OUT |= (BIT5);// VDD - on
    // *//*/__delay_cycles(1000);
return received_ch;
}






uint8_t write2sen22( uint8_t *message){
    volatile char received_ch = 0;

    unsigned int byte1;

    for (byte1=0;byte1<4; byte1++){//send 32 bit frame in 8 bit chunks
        if (byte1 == 0){P1OUT &= (~BIT5);
        UCA0TXBUF=message[byte1];
        }
        else{
            while (!(IFG2 & UCA0TXIFG)); // USCI_A0 TX buffer ready?
            UCA0TXBUF=0x00;
            received_ch = UCA0RXBUF;
        }
        //UCA0TXBUF=message[byte1];
        if (byte1 == 4){P1OUT |= (BIT5);}// VDD - on}
        while (!(IFG2 & UCA0RXIFG));  // USCI_A0 TX buffer ready?
    }
     // Gnd - off
    //if (wait_focompletion)r_
    P1OUT |= (BIT5);// VDD - on

    __delay_cycles(10000);
    //while (!(IFG2 & UCA0RXIFG));  // USCI_A0 RX buffer ready? (indicates transfer complete)
    //P1OUT &= (~BIT5);
    return received_ch;
}


*/




