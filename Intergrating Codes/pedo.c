/*
 * pedo.c
 *
 *  Created on: Apr 29, 2022
 *      Author: phuso
 */
#include <pedo.h>


void pedo_spi_setup()
{
    WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    //Set up SPI for Pedometer
    UCA0CTL1 |= UCSWRST;    // Put A into software reset
    UCA0CTL1 |= UCSSEL_2;   // SMCLK clock
    UCA0BR0  |= 0x02;       // /2 --> 500 khz OD THE SPI CLOCK

    UCA0CTL0 |= UCMSB;      // Most Significant Bit first
    UCA0CTL0 |= UCMST;      // Master mode selected
    UCA0CTL0 |= UCCKPH;     // Phase mode.
    UCA0CTL0 |= UCMODE_0;   // 3 pin SPI;
    UCA0CTL0 |= UCSYNC;     // Synchronous mode enabled

    //--Configuring the ports
    // MOSI Configured
    P1SEL  |= BIT2;
    P1SEL2 |= BIT2;
    // MISO Configured
    P1SEL  |= BIT1;
    P1SEL2 |= BIT1;
    // USCA0CLK - P_CLOCK
    P1SEL  |= BIT4;
    P1SEL2 |= BIT4;
    // Chip select for the Pedo meter
    P2SEL2 &= ~BIT7;
    P2SEL &= ~BIT7;
    P2DIR |= BIT7;
    P2OUT |= BIT7;//chip select high (disable chip)

    UCA0CTL1 &= ~UCSWRST;   // Take out of Software Reset
}

void init_pedo_interrupt(){
    //Pedo Interrupt;
    P2DIR &= ~(BIT2|BIT3); // set to input
    P2REN |= BIT2|BIT3 ;     // enable pullup/down resistors
    P2OUT |= BIT2|BIT3 ;     // set resistors to pull up

    /* Uncomment the following code if you want to use interrupts to detect button presses */
    P2IES |= BIT2|BIT3; // listen for high to low transitions
    P2IFG &=  ~(BIT2|BIT3);
    P2IE |= BIT2|BIT3; // enable interrupts for these pins
}


/*
 * First most significant bit must be 0;
 */

void write1byte( uint8_t address_in, uint8_t value_in){
    P2OUT |= BIT7;// VDD - on
    while (!(IFG2 & UCA0TXIFG));
    P2OUT &= ~BIT7; //Off nCs
    UCA0TXBUF= address_in; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  value_in; //value
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P2OUT |= (BIT7);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));

}


volatile  uint8_t value;
volatile uint8_t value1;
volatile uint8_t value2;
volatile uint8_t value3;
volatile uint8_t value4;

uint8_t read1byte( uint8_t address_in){
      uint8_t value;
    //volatile
    uint8_t address;
    P2OUT |= (BIT7);// VDD - on
    address = address_in;
    address += 0x80; // write flag
    P2OUT &= (~BIT7); //Off nCs
    __delay_cycles(4);
    UCA0TXBUF= address; ///address
    value1 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  address; //value
    value2 = UCA0RXBUF;
    while (!(IFG2 & UCA0RXIFG));
    value3 = UCA0RXBUF;
    __delay_cycles(4);
    P2OUT|= (BIT7);// VDD - on nCS high
    __delay_cycles(100);
    return value3;
}



void pedo_init(){
//    write1byte(CNTL2,BIT7);//0x80
//    __delay_cycles(100);
//
//    write1byte(CNTL1,0x00);//CNTL1
//
//    write1byte(PED_CNTL2, BIT5|BIT3|BIT2);//0x2C
//    write1byte(LP_CNTL, BIT6|BIT5|BIT4|BIT3|BIT1|BIT0);//0x7B
//
//    write1byte(PED_STPWM_L, BIT1|BIT0); //0x03 - THSHOLD low
//    write1byte(PED_STPWM_H, 0x00); // ths high steps
//
//    write1byte(INC5, BIT5);//INC5 INT2 Enabled, active low
//    write1byte(INC6, BIT5);//INC6
//    write1byte(INC7, BIT5);//0x20 step wm enabled INT 2
//    // high =  read1byte(0x26);
//
//    write1byte(INC1,0x00);//INC1 x20
//
//    write1byte(PED_CNTL1, BIT6|BIT5|BIT2|BIT1);//0x66
//    write1byte(PED_CNTL2, BIT5|BIT3|BIT2);//0x2C
//    write1byte(PED_CNTL3, BIT4|BIT2|BIT1|BIT0);//0x17
//    write1byte(PED_CNTL4, BIT4|BIT3|BIT2|BIT1|BIT0);//0x1F
//    write1byte(PED_CNTL5, BIT5|BIT2);//0x24
//    write1byte(PED_CNTL6, BIT4|BIT1|BIT0);//0x13
//    write1byte(PED_CNTL7, BIT3|BIT1|BIT0);//0x0B
//    write1byte(PED_CNTL8, BIT3);//0x08
//    write1byte(PED_CNTL9, BIT4|BIT3|BIT0);//0x19
//    write1byte(PED_CNTL10, BIT4|BIT3|BIT2);//0x1C
//    write1byte(CNTL1, BIT7|BIT6|BIT1);//0xC2
//    __delay_cycles(100);

    write1byte(CNTL1,0x00);             //a) Standby mode, disable the pedometer.
     //Set to every 10 steps.
     write1byte(PED_STPWM_L, BIT3|BIsT1); //b) 0x0A - THSHOLD low
     write1byte(PED_STPWM_H, 0x00);      // ths high steps

     write1byte(PED_CNTL2, BIT5|BIT3|BIT2);//c) 0x2C - Set 100 Hz output data rate (ODR) for the engine

     write1byte(LP_CNTL, BIT6|BIT5|BIT4|BIT3|BIT1|BIT0);//d) 0x7B - Set Low Power Control

     write1byte(INC7, BIT6|BIT5);             //e) 0x20 step wm enabled INT 2

     write1byte(INC1,0x00);              //f) INC1 --> Interrupt Control 1

     write1byte(INC5, BIT5|BIT3);             //g) x20 INC5 INT2 Enabled, active low, unlatched

 //    write1byte(INC6, BIT5);//INC6

     // high =  read1byte(0x26);
     //h) x20 INC5 INT2 Enabled, active low, latched
     write1byte(PED_CNTL1, BIT6|BIT5|BIT2|BIT1);//0x66
     write1byte(PED_CNTL2, BIT5|BIT3|BIT2);//0x2C - Set 100 Hz output data rate (ODR) for the engine
     write1byte(PED_CNTL3, BIT4|BIT2|BIT1|BIT0);//0x17
     write1byte(PED_CNTL4, BIT4|BIT3|BIT2|BIT1|BIT0);//0x1F
     write1byte(PED_CNTL5, BIT5|BIT2);//0x24
     write1byte(PED_CNTL6, BIT4|BIT1|BIT0);//0x13
     write1byte(PED_CNTL7, BIT3|BIT1|BIT0);//0x0B
     write1byte(PED_CNTL8, BIT3);//0x08
     write1byte(PED_CNTL9, BIT4|BIT3|BIT0);//0x19
     write1byte(PED_CNTL10, BIT4|BIT3|BIT2);//0x1C

     write1byte(CNTL1, BIT7|BIT6|BIT1);      //i) 0xC2
     __delay_cycles(100);
}

