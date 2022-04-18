#include <msp430.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

//Define some common commands.
#define SWRESET 0x01; //Software Reset - 163
#define SLPIN 0x10;   //Sleep in - 182
#define SLPOUT 0x11;  //Sleep out - 184
#define PTLON 0x12;   //Partial Display Mode On - 186
#define NORON 0x13;   //Normal Display Mode On - 187
#define INVOFF 0x20;   //Display Inversion Off  - 188
#define DISPOFF 0x28;   //Display Off  - 194
#define DISPON 0x29;   //Display On  - 196
#define CASET 0x2A; //Column Address Set - 198
#define RASET 0x2B; //Row Address Set - 200
#define MADCTL 0x36; //Memory Data Access Control  - 215
#define COLMOD 0x3A; //Interface Pixel Format - 224
#define WRDISBV 0x51; //Write Display Brightness - 233

/**
 * This set up the delay using CCTL.
 */
void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      CCR0 = 31250;                             // first time when interupts turns off
      TACTL = TASSEL_2 + MC_2 + ID_3;           // SMCLK, contmode
}

/**
 * This delays the operation by time amount;
 */
void delay(unsigned int time){
    //unsigned int timer;
    //for (timer=0;timer<time; timer++){
    CCTL0 |= CCIE;                             // CCR0 enable
    CCR0 += time;
    __bis_SR_register(LPM0_bits + GIE);
    CCR0 += time;
    CCTL0 &= ~CCIE;                             // CCR0 disable
}

void spi_setup(void)
{
    //Set up SPI_B0 - 445
    UCB0CTL1 |= UCSWRST;      // Put B into software reset
    UCB0CTL1 |= UCSSEL_2;     // SMCLK clock = 1MGHz
    UCB0BR0  = 0;               // Set prescalar to 1 to get 1MGhz
    UCB0BR1 = 0;

    UCB0CTL0 |= UCMSB;        //Most Significant Bit first
    UCB0CTL0 |= UCMST;        //Master mode selected
    UCB0CTL0 |= UCCKPH;       //Phase mode.
    UCB0CTL0 |= UCMODE_1;     //4 pin SPI with UCxSTE active high; slave enabled when STE = 1;
    UCB0CTL0 |= UCSYNC;       //Synchronous mode enabled

    //--Configuring the ports
    //MOSI Configured
    P1SEL  |= BIT7;
    P1SEL2 |= BIT7;
    //D_CLOCK Configured
    P1SEL  |= BIT5;
    P1SEL2 |= BIT5;
    //Chip select for the display
//    P1SEL  |= BIT4;
//    P1SEL2 |= BIT4;
    P1DIR  |= BIT4;
    P1OUT |= BIT4; //chip select high (disable chip)

    UCB0CTL1 &= ~UCSWRST; // Take out of Software Reset

    //--Enable IRQs;
//    UC0IE |= UCB0TXIE;    //USCI_B0 transmit interupt enable
//    UC0IFG &= ~UCB0TXIFG; //clear USCI_B0 Transmit interrupt flag

    //COMMAND OR DATA GPIO
    P2DIR  |= BIT5;
    P2OUT  &= ~(BIT5); //Set to Command Initially

    //Reset Display
    P1DIR |= BIT0;
    P1OUT |= BIT0;

    //LED Indicator
    P2DIR  |= BIT1;
    P2OUT  &= ~(BIT1);

    //BUTTON SWITCHES;
    P2DIR &= ~(BIT3 | BIT4 ); // set to input
    P2REN = BIT3 | BIT4 ;     // enable pullup/down resistors
    P2OUT = BIT3 | BIT4 ;     // set resistors to pull up

    /* Uncomment the following code if you want to use interrupts to detect button presses */
    P2IES = BIT3 | BIT4; // listen for high to low transitions
    P2IFG &=  ~(BIT3 | BIT4);
    P2IE = BIT3 | BIT4; // enable interrupts for these pins
}

/**
 * dc: data is 1; command is 0
 * spiBytes: the spi bytes we want to send
 * num_bytes: number of bytes in spiBytes
 */
void sendBytes(uint8_t dc, uint8_t *spiBytes, int num_bytes){
    P1OUT &= ~BIT4; // chip select low
    //Turn on Data or command;
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    int byte1;
    for (byte1=0;byte1<num_bytes;byte1++){//send 32 bit frame in 8 bit chunks
        UCB0TXBUF=spiBytes[byte1];
//        while (!(IFG2 & UCB0TXIFG));  // USCI_A0 TX buffer ready?
    }
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT4; // chip select high
}

/**
 * dc: Data (1) or Command (0)
 * col: 5 bits R + 6 bits G + 5 bits B = 16 bits/ pixel
 * num_pix: number of pixels being sent.
 */
void sendColor(uint8_t dc, uint16_t col, int num_pix){
    P1OUT &= ~BIT4; // chip select low
    //Turn on Data or command;
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    int byte1;
    for (byte1=0;byte1<num_pix;byte1++){//send 32 bit frame in 8 bit chunks
        UCB0TXBUF= col;
//        while (!(IFG2 & UCB0TXIFG));  // USCI_A0 TX buffer ready?
    }
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT4; // chip select high
}

/**
 * Send 1 byte ( typically used for command --> setting dc =0);
 * dc: data is 1; command is 0
 * spiBytes: the spi bytes we want to send
 */
void send1Byte(uint8_t dc, uint8_t spiByte){
    //Turn on Data or command;
    P1OUT &= ~BIT4; // chip select low
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    UCB0TXBUF=spiByte;
    while (!(IFG2 & UCB0TXIFG));  // USCI_A0 TX buffer ready?
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT4; // chip select high
}

/**
 * CASET command.
 */
void caset(uint8_t a, uint8_t b, uint8_t c, uint8_t d){
    send1Byte(0, 0x2A);
    send1Byte(1, a);
    send1Byte(1, b);
    send1Byte(1, c);
    send1Byte(1, d);
    delay(3200);
}
/**
 * RASET command.
 */
void raset(uint8_t a, uint8_t b, uint8_t c, uint8_t d){
    send1Byte(0, 0x2B);
    send1Byte(1, a);
    send1Byte(1, b);
    send1Byte(1, c);
    send1Byte(1, d);
    delay(3200);
}

/**
 * Initialized the Display. Must be called to set up everything for the display
 */
void initDisplay(){
    //HW reset
    P1OUT &= ~BIT0;
    delay(32000);
    P1OUT |= BIT0;
    delay(32000);

    //SW Reset
    send1Byte(0, 0x01);
    delay(3200);


    //COLMOD
    send1Byte(0, 0x3A);
    send1Byte(1, 0x55); //RGB 65K and 16bit/pixel
    delay(3200);

    //-------------
    //MADCTL
    send1Byte(0, 0x36);
    send1Byte(1, 0x08);//Line Address Order - from bottom to top

    //CASET
//    caset(0x00, 0x00, 0x00, 0xF0);// Recheck
//    caset(0x00, 0x00, 0x00, 0x86);
    caset(0x00, 0x34, 0x00, 0xBA);

    //RASET
//    raset(0x00, 0x00, 0x01, 0x40);//
//    raset(0x00, 0x00, 0x00, 0xEF);//
    raset(0x00, 0x28, 0x01, 0x17);

    //Sleep Out
    send1Byte(0, 0x11);
    delay(3200);
    //--------------

    //DISPON
    send1Byte(0, 0x29);
    delay(3200);

    //NORON
    send1Byte(0, 0x13);
    delay(3200);
}

int main(void)
{
    spi_setup();
    delay_setup();
    _enable_interrupts();
    P1OUT &= ~BIT4; // chip select low
    initDisplay();
    delay(50);

    uint16_t a = 0x00;
    while(1)
    {
        //initDisplay();
        delay(50);
        send1Byte(0, 0x2C); //RAMWR
        int i=0;
        while (i<241){ //Send 241 rows
            sendColor(1, a, 270);
            a+=3;i++;
            if (a== 0xFFFF) a=0x00;
        }
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

#pragma vector=PORT2_VECTOR
__interrupt void button(void)
{
    P2IFG &= ~(BIT3);//Clear the button press.
    while(!(P2IN & BIT3));
    P2OUT  |= (BIT1);
    send1Byte(0, 0x01);
    P2OUT  &= ~(BIT1);
}

//#pragma vector=USCIAB0TX_VECTOR
//__interrupt void ISR_B0(void)
//{
//    i++;
//    if(i<6){
//        UCB0TXBUF= color[i];
//    }
//    else {
//        i=0;
//        UC0IFG &= ~UCB0TXIFG; // clear USCIAB0TX_VECTOR
//    }
//}



