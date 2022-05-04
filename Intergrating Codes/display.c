/*
 * display.c
 *
 *  Created on: Apr 29, 2022
 *      Author: phuso
 */
#include <display.h>
uint8_t low=0, high=0, steps=0;

const unsigned char font[96][6] = {
    {0x00,0x00,0x00,0x00,0x00,0x00}, //
    {0x2f,0x00,0x00,0x00,0x00,0x00}, // !
    {0x03,0x00,0x03,0x00,0x00,0x00}, // "
    {0x12,0x3f,0x12,0x12,0x3f,0x12}, // #
    {0x2e,0x2a,0x7f,0x2a,0x3a,0x00}, // $
    {0x23,0x13,0x08,0x04,0x32,0x31}, // %
    {0x10,0x2a,0x25,0x2a,0x10,0x20}, // &
    {0x02,0x01,0x00,0x00,0x00,0x00}, // '
    {0x1e,0x21,0x00,0x00,0x00,0x00}, // (
    {0x21,0x1e,0x00,0x00,0x00,0x00}, // )
    {0x08,0x2a,0x1c,0x2a,0x08,0x08}, // *
    {0x08,0x08,0x3e,0x08,0x08,0x08}, // +
    {0x80,0x60,0x00,0x00,0x00,0x00}, // ,
    {0x08,0x08,0x08,0x08,0x08,0x00}, // -
    {0x30,0x30,0x00,0x00,0x00,0x00}, // .
    {0x20,0x10,0x08,0x04,0x02,0x00}, // /
    {0x1e,0x31,0x29,0x25,0x23,0x1e}, // 0
    {0x22,0x21,0x3f,0x20,0x20,0x20}, // 1
    {0x32,0x29,0x29,0x29,0x29,0x26}, // 2
    {0x12,0x21,0x21,0x25,0x25,0x1a}, // 3
    {0x18,0x14,0x12,0x3f,0x10,0x10}, // 4
    {0x17,0x25,0x25,0x25,0x25,0x19}, // 5
    {0x1e,0x25,0x25,0x25,0x25,0x18}, // 6
    {0x01,0x01,0x31,0x09,0x05,0x03}, // 7
    {0x1a,0x25,0x25,0x25,0x25,0x1a}, // 8
    {0x06,0x29,0x29,0x29,0x29,0x1e}, // 9
    {0x24,0x00,0x00,0x00,0x00,0x00}, // :
    {0x80,0x64,0x00,0x00,0x00,0x00}, // ;
    {0x08,0x14,0x22,0x00,0x00,0x00}, // <
    {0x14,0x14,0x14,0x14,0x14,0x00}, // =
    {0x22,0x14,0x08,0x00,0x00,0x00}, // >
    {0x02,0x01,0x01,0x29,0x05,0x02}, // ?
    {0x1e,0x21,0x2d,0x2b,0x2d,0x0e}, // @
    {0x3e,0x09,0x09,0x09,0x09,0x3e}, // A
    {0x3f,0x25,0x25,0x25,0x25,0x1a}, // B
    {0x1e,0x21,0x21,0x21,0x21,0x12}, // C
    {0x3f,0x21,0x21,0x21,0x12,0x0c}, // D
    {0x3f,0x25,0x25,0x25,0x25,0x21}, // E
    {0x3f,0x05,0x05,0x05,0x05,0x01}, // F
    {0x1e,0x21,0x21,0x21,0x29,0x1a}, // G
    {0x3f,0x04,0x04,0x04,0x04,0x3f}, // H
    {0x21,0x21,0x3f,0x21,0x21,0x21}, // I
    {0x10,0x20,0x20,0x20,0x20,0x1f}, // J
    {0x3f,0x04,0x0c,0x0a,0x11,0x20}, // K
    {0x3f,0x20,0x20,0x20,0x20,0x20}, // L
    {0x3f,0x02,0x04,0x04,0x02,0x3f}, // M
    {0x3f,0x02,0x04,0x08,0x10,0x3f}, // N
    {0x1e,0x21,0x21,0x21,0x21,0x1e}, // O
    {0x3f,0x09,0x09,0x09,0x09,0x06}, // P
    {0x1e,0x21,0x29,0x31,0x21,0x1e}, // Q
    {0x3f,0x09,0x09,0x09,0x19,0x26}, // R
    {0x12,0x25,0x25,0x25,0x25,0x18}, // S
    {0x01,0x01,0x01,0x3f,0x01,0x01}, // T
    {0x1f,0x20,0x20,0x20,0x20,0x1f}, // U
    {0x0f,0x10,0x20,0x20,0x10,0x0f}, // V
    {0x1f,0x20,0x10,0x10,0x20,0x1f}, // W
    {0x21,0x12,0x0c,0x0c,0x12,0x21}, // X
    {0x01,0x02,0x0c,0x38,0x04,0x02}, // Y
    {0x21,0x31,0x29,0x25,0x23,0x21}, // Z
    {0x3f,0x21,0x00,0x00,0x00,0x00}, // [
    {0x02,0x04,0x08,0x10,0x20,0x00}, // "\"
    {0x21,0x3f,0x00,0x00,0x00,0x00}, // ]
    {0x04,0x02,0x3f,0x02,0x04,0x00}, // ^
    {0x40,0x40,0x40,0x40,0x40,0x40}, // _
    {0x01,0x02,0x00,0x00,0x00,0x00}, // `
    {0x10,0x30,0x2a,0x2a,0x3c,0x00}, // a
    {0x3f,0x24,0x24,0x24,0x18,0x00}, // b
    {0x0c,0x14,0x22,0x22,0x00,0x00}, // c
    {0x18,0x24,0x24,0x24,0x3f,0x00}, // d
    {0x1c,0x2c,0x2a,0x2a,0x24,0x00}, // e
    {0x3e,0x05,0x01,0x00,0x00,0x00}, // f
    {0x18,0x28,0xa4,0xa4,0x7c,0x00}, // g
    {0x3f,0x04,0x04,0x0c,0x30,0x00}, // h
    {0x24,0x3d,0x20,0x00,0x00,0x00}, // i
    {0x20,0x40,0x40,0x3d,0x00,0x00}, // j
    {0x3f,0x0c,0x12,0x20,0x00,0x00}, // k
    {0x1f,0x20,0x20,0x00,0x00,0x00}, // l
    {0x3e,0x02,0x3c,0x02,0x3c,0x00}, // m
    {0x3e,0x02,0x02,0x02,0x3c,0x00}, // n
    {0x0c,0x14,0x22,0x32,0x0c,0x00}, // o
    {0xfc,0x24,0x24,0x24,0x18,0x00}, // p
    {0x18,0x24,0x24,0x24,0xfc,0x80}, // q
    {0x3c,0x04,0x02,0x02,0x00,0x00}, // r
    {0x24,0x2c,0x2a,0x2a,0x10,0x00}, // s
    {0x02,0x1f,0x22,0x20,0x00,0x00}, // t
    {0x1e,0x20,0x20,0x20,0x1e,0x00}, // u
    {0x06,0x18,0x20,0x18,0x06,0x00}, // v
    {0x1e,0x30,0x1c,0x30,0x0e,0x00}, // w
    {0x22,0x14,0x08,0x14,0x22,0x00}, // x
    {0x0c,0x10,0xa0,0xa0,0x7c,0x00}, // y
    {0x22,0x32,0x2a,0x26,0x22,0x22}, // z
    {0x0c,0x3f,0x21,0x00,0x00,0x00}, // {
    {0x3f,0x00,0x00,0x00,0x00,0x00}, // |
    {0x21,0x3f,0x0c,0x00,0x00,0x00}, // }
    {0x02,0x01,0x02,0x01,0x00,0x00}, // ~
    {0x00,0x00,0x00,0x00,0x00,0x00}
};

/**
 * This set up the delay using CCTL.
 */
void delay_setup(){
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      BCSCTL1 |= CALBC1_8MHZ;
      DCOCTL  |= CALDCO_8MHZ;
      BCSCTL3 |= LFXT1S_2;                      // ACLK = VLO
      CCTL0 = CCIE;                             // CCR0 interrupt enabled
      TACTL = TASSEL_1 + MC_2;                  // ACLK, Continuous mode => 12kHz
      CCR0 = 1;                                 // first time when interupts turns off
      CCTL0 &= ~CCIE;                           // CCR0 disable
}

/**
 * This delays the operation by time amount;
 * 12000kHz is 1 second
 */
void delay(unsigned int time){
    CCTL0 |= CCIE;                             // CCR0 enable
    CCR0 = TA0R+ time;
    __bis_SR_register(LPM3_bits + GIE);
    CCTL0 &= ~CCIE;                             // CCR0 disable
}

void display_spi_setup(void)
{
    //Set up SPI_B0 - 445
    UCB0CTL1 |= UCSWRST;      // Put B into software reset
    UCB0CTL1 |= UCSSEL_2;     // SMCLK clock
    UCB0BR0  = 0;             // Set prescalar to 1 to get 1MGhz
    UCB0BR1 = 0;

    UCB0CTL0 |= UCMSB;        // Most Significant Bit first
    UCB0CTL0 |= UCMST;        // Master mode selected
    UCB0CTL0 |= UCCKPH;       // Phase mode.
    UCB0CTL0 |= UCMODE_0;     // 3 pin SPI;
    UCB0CTL0 |= UCSYNC;       // Synchronous mode enabled

    //--Configuring the ports
    //MOSI_B Configured
    P1SEL  |= BIT7;
    P1SEL2 |= BIT7;
    //USCB0CLK - D_CLOCK Configured
    P1SEL  |= BIT5;
    P1SEL2 |= BIT5;
    //Chip select for the display
//    P1SEL  |= BIT4;
//    P1SEL2 |= BIT4;
    P1DIR  |= BIT6;
    P1OUT |= BIT6; //chip select high (disable chip)

    UCB0CTL1 &= ~UCSWRST;   // Take out of Software Reset

    //--Enable IRQs;
//    UC0IE |= UCB0TXIE;    //USCI_B0 transmit interupt enable
//    UC0IFG &= ~UCB0TXIFG; //clear USCI_B0 Transmit interrupt flag

    //COMMAND OR DATA GPIO
    P2DIR  |= BIT5;
    P2OUT  &= ~(BIT5); //Set to Command Initially

    //Reset Display
    P1DIR |= BIT3;
    P1OUT |= BIT3;

    //LED Indicator
    P2DIR  |= BIT1;
    P2OUT  &= ~(BIT1);

    //BUTTON SWITCHES;
    P2DIR &= ~(BIT3 | BIT4 ); // set to input
    P2REN |= BIT3 | BIT4 ;     // enable pullup/down resistors
    P2OUT |= BIT3 | BIT4 ;     // set resistors to pull up

    /* Uncomment the following code if you want to use interrupts to detect button presses */
    P2IES = BIT3 | BIT4; // listen for high to low transitions
    P2IFG &=  ~(BIT3 | BIT4);
    P2IE |= BIT3 | BIT4; // enable interrupts for these pins
}

/**
 * dc: data is 1; command is 0
 * spiBytes: the spi bytes we want to send
 * num_bytes: number of bytes in spiBytes
 */
void sendBytes(uint8_t dc, uint8_t *spiBytes, int num_bytes){
    P1OUT &= ~BIT6; // chip select low
    //Turn on Data or command;
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    int byte1;
    for (byte1=0;byte1<num_bytes;byte1++){//send 32 bit frame in 8 bit chunks
        while (!(IFG2 & UCB0TXIFG));  // USCI_B0 TX buffer ready?
        UCB0TXBUF=spiBytes[byte1];
    }
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT6; // chip select high
}

/**
 * dc: Data (1) or Command (0)
 * col: 5 bits R + 6 bits G + 5 bits B = 16 bits/ pixel
 * num_pix: number of pixels being sent.
 */
void sendColor(uint8_t dc, uint16_t col, int num_pix){
    P1OUT &= ~BIT6; // chip select low
    //Turn on Data or command;
    uint8_t upper = col >> 8;
    uint8_t lower = col;
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    int byte1;
    for (byte1=0;byte1<num_pix;byte1++){
        while (!(IFG2 & UCB0TXIFG));  // USCI_A0 TX buffer ready?
        UCB0TXBUF = upper;
//        while (!(IFG2 & UCB0TXIFG));  // USCI_A0 TX buffer ready?
       UCB0TXBUF = lower;
    }
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT6; // chip select high
}

/**
 * Send 1 byte ( typically used for command --> setting dc =0);
 * dc: data is 1; command is 0
 * spiBytes: the spi bytes we want to send
 */
void send1Byte(uint8_t dc, uint8_t spiByte){
    //Turn on Data or command;
    P1OUT &= ~BIT6; // chip select low
    if (dc) P2OUT  |= (BIT5);
    else P2OUT  &= ~(BIT5);
    while (!(IFG2 & UCB0TXIFG));  // USCI_B0 TX buffer ready?
    UCB0TXBUF=spiByte;
    //Turn off Data or command;
    while(UCB0STAT & UCBUSY);
    if (dc) P2OUT  &= ~(BIT5);
        else  P2OUT  |= (BIT5);
    P1OUT |= BIT6; // chip select high
}

/**
 * CASET command.
 */
void caset(uint8_t a, uint8_t b, uint8_t c, uint8_t d){
    send1Byte(0, CASET);
    send1Byte(1, a);
    send1Byte(1, b);
    send1Byte(1, c);
    send1Byte(1, d);
}
/**
 * RASET command.
 */
void raset(uint8_t a, uint8_t b, uint8_t c, uint8_t d){
    send1Byte(0, RASET);
    send1Byte(1, a);
    send1Byte(1, b);
    send1Byte(1, c);
    send1Byte(1, d);
}

/**
 * Initialized the Display. Must be called to set up everything for the display
 */
void initDisplay(){
    //HW reset
    P1OUT &= ~BIT3;
    delay(1);
    P1OUT |= BIT3;
    delay(10);
    //SW Reset
    send1Byte(0, SWRESET);
    delay(10);
    //COLMOD
    send1Byte(0, COLMOD);
    send1Byte(1, 0x55); //RGB 65K and 16bit/pixel
    //-------------
    send1Byte(0, MADCTL);
    send1Byte(1, 0x40);//MY|MX|MV|ML | RGB|MH|X|X
    caset(0x00, 0x34, 0x00, 0xBA); // 135 H
    raset(0x00, 0x28, 0x01, 0x17); // 240 W
    send1Byte(0, SLPOUT);
    //--------------
    send1Byte(0, DISPON);
    send1Byte(0, NORON);
    send1Byte(0, INVON);

    send1Byte(0, WRCTRLD);
    send1Byte(1, 0x2C); //0|0|BCTRL|0 DD|BL|0|0
    delay(9000);
    send1Byte(0, WRDISBV);
    send1Byte(1, 0xFF);
    delay(9000);
//
//    send1Byte(0, WRCACE);
//    send1Byte(1, 0xB3);
//    delay(7000);
//
//    send1Byte(0, WRCABCMB);
//    send1Byte(1, 0xFF); //0|0|BCTRL|0 DD|BL|0|0
//    delay(7000);
}

/*
 * col: 5 bits R + 6 bits G + 5 bits B = 16 bits/ pixel
 */
void sendScreenColor(uint16_t color){
    caset(0x00, 0x34, 0x00, 0xBA);
    raset(0x00, 0x28, 0x01, 0x17);
    send1Byte(0, RAMWR); //RAMWR
    sendColor(1, color, 32400); // 130 x 240 = 32400
}

void drawPixel(uint8_t xStartIndex, uint8_t yStartIndex) {
    caset((0x34+xStartIndex*2) >> 8, 0x34+xStartIndex*2, (0x34+xStartIndex*2 +0x02) >> 8, 0x34+xStartIndex*2 +0x02);
    raset((0x28+yStartIndex*2) >> 8, 0x28+yStartIndex*2, (0x28+yStartIndex*2 +0x02) >> 8, 0x28+yStartIndex*2 +0x02);
    send1Byte(0, RAMWR); //RAMWR
    sendColor(1, YELLOW, 9);
}

void drawCharacter(char character, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness) {
    character &= 0x7F;
    if (character >= ' ') {
        character -= ' ';
    } else {
        character = 0;
    }
    const uint8_t* characterFont = font[character];
    uint8_t x_index, y_index;
    for (y_index = 0; y_index < CHAR_WIDTH; y_index++) {
        for (x_index = 0; x_index < CHAR_HEIGHT; x_index++) {
            if ((1 << x_index) & characterFont[y_index]) {
                drawPixel((xStartIndex + x_index), (yStartIndex + y_index));
            }
        }
    }
}

void drawString(char* string, uint8_t xStartIndex, uint8_t yStartIndex, uint8_t brightness) {
    while (*string) {
        drawCharacter(*string, xStartIndex, yStartIndex, brightness);
        yStartIndex += CHAR_WIDTH+1;
        string++;
    }
}

// Implementation of itoa() //integer into string
char* itoa(int num, char* str, int count)
{
    int i=count-1;
    for(;i>=0;i--){
        int a = num%10;
        num/=10;
        str[i] = a+48;
    }
    str[count]=0;
    return str;
}
int time_count = 0;

enum state_enum{displaying, changetime} state;

unsigned int state_flag = 0;


void update_screen(){

    sendScreenColor(BLACK);
    int h = time_count/(60*60), m = (time_count/60)%60, s = time_count%60;
    char buffer[2];
    char display[15] = "Time: ";
    itoa(h,buffer,2);
    strcat(display,buffer);
    strcat(display,":");
    itoa(m,buffer,2);
    strcat(display,buffer);
    strcat(display,":");
    itoa(s,buffer,2);
    strcat(display,buffer);
    drawString(display, 0x05, 0x05, 0x05);

    char s_buffer[6];
    char s_display[14] = "Steps: ";
    itoa(steps,s_buffer,5);
    strcat(s_display,s_buffer);
    drawString(s_display, 0x1F, 0x0F, 0x05);

    if (state ==changetime){

        //char r_buffer[6];
        char r_display[14] = "Change time";
        //itoa(0,r_buffer,5);
        //strcat(r_display,r_buffer);
        drawString(r_display, 0x0F, 0x0F, 0x05);
    }

}


void displayClock(){

    while(1) {

        update_screen();

       /* if (state == displaying){
            char r_buffer[6];
            char r_display[14] = "RESET M";
            itoa(steps,r_buffer,5);
            strcat(r_display,r_buffer);
            drawString(s_display, 0x1F, 0x0F, 0x05);
        }*/

        delay(10900); //increment every second
        time_count = (time_count + 1) ;
        if  (time_count > 86400){
            time_count -= 86400;  }

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
  LPM3_EXIT;
}


uint8_t id;
int button_press;
int change_flag = 0;

#pragma vector=PORT2_VECTOR
__interrupt void button(void)
{
    P2IFG &= ~(BIT2 + BIT3 + BIT4) ;
    change_flag = 0;
   int button_press = 0b000;

   if ((!(P2IN & BIT3)) && (!(P2IN & BIT4))){
       button_press |= BIT3 + BIT4;
       //time_count = 42;
       //state_flag = 1;
       //change_flag = 1;
       //state = changetime;
       // && (change_flag == 1)

   }
   else{
    if  (!(P2IN & BIT2)) {
        button_press |= BIT2;}

    if  (!(P2IN & BIT3)) {//top_botton
        button_press |= BIT3;}

    if  (!(P2IN & BIT4)) { //bottom button
        button_press |= BIT4;    }
   }

    //button, interupt conditions
    if (button_press == BIT2){
        low =  read1byte(PED_STP_L);//KX126_PED_STEP_L);
        high = read1byte(PED_STP_H);
        steps += low;
        delay(100);
        time_count += 2;
    }

   //state machine for
   //if displaying and you want to read steps
   if ((state == displaying) && (change_flag == 0)){
   if (button_press == BIT3 ){ //top button

        low =  read1byte(PED_STP_L);//KX126_PED_STEP_L);
        high = read1byte(PED_STP_H);
        steps += low;
        delay(100);

    }
    else if (button_press == BIT4 ){
        steps = 0;

    }
    else if (button_press ==(BIT3+BIT4)){
        state_flag = 1;
        state = changetime;
        change_flag = 1;
    } }

   if ((state == changetime) && (change_flag == 0)){
   if (button_press == BIT3 ){ //top button
       time_count += 3600;
    }
    else if (button_press == BIT4 ){//bottom button
        time_count += 60;

    }
    else if (button_press ==(BIT3+BIT4)){
        state_flag = 0;
        state = displaying;
        change_flag = 1;

    }



    }
 LPM3_EXIT;



}
