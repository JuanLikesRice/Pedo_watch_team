#include <msp430.h>
#include <stdint.h>



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
    CCR0 += time;}//}

void spi_setup(void)
{   WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    UCA0CTL1 |= UCSWRST;                          // Enable SPI software rezet
    UCA0CTL1 |= UCSSEL_2; // SMCLK clock
    UCA0CTL0 |= UCCKPH;
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






void write1byte( uint8_t *message){
    P1OUT |= (BIT5);// VDD - on
    //message[0] |= 0x80; // write flag
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
}

uint8_t read1byte( uint8_t *message){
    //volatile
    uint8_t value;
    P1OUT |= (BIT5);// VDD - on
    uint8_t address;
    address = message[0];
    address += 0x80; // write flag
    //message[0] |= 0x80; // write flag
    //UCA0TXBUF= 0x00; //us3ed to be dummy var
    while (!(IFG2 & UCA0TXIFG));
    P1OUT &= (~BIT5); //Off nCs
    UCA0TXBUF= address; ///address
    while (!(IFG2 & UCA0RXIFG));
    UCA0TXBUF=  address; //value
    value = UCA0RXBUF;
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    P1OUT |= (BIT5);// VDD - on nCS high
    while (!(IFG2 & UCA0TXIFG));
return value;
}

uint8_t CNTL2[] =       {0x1B,0x80};//,0x00,0x00};
uint8_t CNTL1[] =       {0x1A,0x00};

uint8_t INC7[] =        {0x27,0x00};//,0x00,0x00};
uint8_t INC1[] =        {0x20,0x00};//,0x00,0x00};
uint8_t INC5[] =        {0x24,0x00};//,0x00,0x00};
uint8_t LPCNTL[] =        {0x37,0x20};

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

uint8_t ODCNTL[] =        {0x1F,0x03};

uint8_t CNTL1_2[] =         {0x1A,0x40};
uint8_t CNTL1_3[] =         {0x1A,0x02};
uint8_t CNTL1_4[] =         {0x1A,0x80};


//uint8_t CNTL1[] =       {0x1A,0x00};//,0x00,0x00};
uint8_t PED_STPWM_L[] = {0x41,0x10};//,0x00,0x00};
uint8_t PED_STPWM_H[] = {0x42,0x27};//,0x00,0x00};
uint8_t PED_CNTL2[] =   {0x44,0x2C};//,0x00,0x00};
uint8_t LP_CNTL[] =     {0x37,0x7B};//,0x00,0x00};

uint8_t KX126_PED_STEP_L[] = {0x0E,0x00};//,0x00,0x00};
uint8_t KX126_PED_STEP_H[] = {0x0F,0x00};//,0x00,0x00};
uint8_t who_asked[] = {0x11, 0x11};
unsigned int allsteps;
unsigned int somesteps;

unsigned int var1;
unsigned int var2;
unsigned int var3;
unsigned int var4;



unsigned int read_steps(void){
volatile uint8_t low = 0;
volatile uint8_t high = 0;
volatile uint8_t steps = 0;
low =  read1byte(KX126_PED_STEP_L);
high = read1byte(KX126_PED_STEP_H);
steps = low;
//steps += low;
//#print(steps)
return steps;
}


int main(void)
 {spi_setup();
 delay_setup();

 //software reset:
 uint8_t val1 = read1byte(CNTL2);
 CNTL2[1] |= val1;
 write1byte(CNTL2);
 delay(1000); //delay >=2 ms
 write1byte(CNTL1); //{0x1A,0x00}; // reset control 1
 //disable interupt pins
 write1byte(INC1); //{0x20,0x00};
 write1byte(INC5); //{0x24,0x00};
 //setup pedometer
 uint8_t val2 = read1byte(LPCNTL); //A0x37
 write1byte(LPCNTL); //{0x24,0x00};
 uint8_t val3 = read1byte(PED_CENTL1); //A0x43
 PED_CENTL1[1] |= val3;
 write1byte(PED_CENTL1);
 uint8_t val4 = read1byte(PED_CENTL2); //A0x44
 PED_CENTL2[1] |= val4;
 write1byte(PED_CENTL3); //HPF
 write1byte(PED_CENTL4); //HPF
 write1byte(PED_CENTL5); //HPF
 write1byte(PED_CENTL6); //HPF
 write1byte(PED_CENTL7); //HPF
 write1byte(PED_CENTL8); //HPF
 write1byte(PED_CENTL9); //HPF
 write1byte(PED_CENTL10); //HPF

 uint8_t val5 = read1byte(ODCNTL); //A0x44
 ODCNTL[1] |= val5;
 write1byte(ODCNTL); //0x1F

uint8_t val6 = read1byte(CNTL1_2);
CNTL1_2[1] |= val6;
write1byte(CNTL1_2);

uint8_t val7 = read1byte(CNTL1_3);
CNTL1_3[1] |= val7;
write1byte(CNTL1_3);

//uint8_t val8 = read1byte(CNTL1_4);
//CNTL1_4[1] |= val8;
//write1byte(CNTL1_4);



while(1)
{
    //delay(100000);
   var1 = read1byte(CNTL1_4);
   var2 = read1byte(who_asked);
   var3 = read_steps();
   //read1byte(CNTL1_4);//read_steps();//read1byte(who_asked);
  // if (allsteps != 0){
    //   somesteps += allsteps;

   //}
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
