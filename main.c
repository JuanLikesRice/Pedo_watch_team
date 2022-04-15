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


void write1byte( uint8_t address_in, uint8_t value_in){
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
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));


}

uint8_t read1byte( uint8_t address_in){
    //volatile
    uint8_t value;
    P1OUT |= (BIT5);// VDD - on
    uint8_t address;
    address = address_in;
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
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
/*
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
    while (!(IFG2 & UCA0TXIFG));
*/
    return value;
}


uint8_t who_asked[] = {0x11, 0x11};
unsigned int allsteps;
unsigned int somesteps;

unsigned int var1;
unsigned int var2;
unsigned int var3;
unsigned int var4;

unsigned int read1;
unsigned int read2;
unsigned int read3;
unsigned int read4;
unsigned int read5;
unsigned int read6;
unsigned int read7;



unsigned int read_steps(void){
volatile uint8_t low = 0;
volatile uint8_t high = 0;
volatile uint16_t steps = 0;
low =  read1byte(0x0E);//KX126_PED_STEP_L);
high = (read1byte(0x00F)<<8);//KX126_PED_STEP_H);
steps = high+low;
//steps += low;
return high;
}


int main(void)
 {spi_setup();
 delay_setup();
 delay(10000);

 /*
 //software reset:
 read5 = read1byte(0x1B);
 read1 = 0X80 + read1byte(0x1B);//CNTL2);
 write1byte(0x1B,read1); //CNTL2);
 //read1 = read1byte(0x11);
// read1 = read1byte(0x1B);
 delay(1000); //delay >=2 ms

 write1byte(0x1A,0x00);//CNTL1); //{0x1A,0x00}; // reset control 1
 //disable interupt pins
 write1byte(0x20,0x00);//INC1); //{0x20,0x00};
 write1byte(0x24,0x00);//INC5); //{0x24,0x00};

 //setup pedometer
 read2  = 0x20 + read1byte(0x37);//LPCNTL); //A0x37
 write1byte(0x37,0x20 + read1byte(0x37)); //{0x24,0x00};
// read2  = read1byte(0x37);//LPCNTL); //A0x37

//read3 = read1byte(PED_CENTL1); //A0x43
write1byte(0x43,0x10 +read1byte(0x43));
read4 = read1byte(0x44);//,0x2C);//PED_CENTL2);
write1byte(0x44,0x2C);


write1byte(0x45,0x17);//PED_CENTL3); //HPF
 write1byte(0x46,0x1F);//PED_CENTL4); //HPF
 write1byte(0x47,0x0A);//PED_CENTL5); //HPF
 write1byte(0x48,0x13);//PED_CENTL6); //HPF
 write1byte(0x49,0x0B);//PED_CENTL7); //HPF
 write1byte(0x4A,0x08);//PED_CENTL8); //HPF
 write1byte(0x4B,0x19);//PED_CENTL9); //HPF
 write1byte(0x4C,0x1C);//PED_CENTL10); //HPF

 read5 = read1byte(0x1F);//ODCNTL); //
 write1byte(0x1F,0x03); //0x1F
read6 = read1byte(0x1A);//,0x40);//CNTL1_2)
write1byte(0x1A,0xC2);//0x40);

 /*
 write1byte(0x1F,0x03); //0x1F
 var6 = read1byte(CNTL1_2);
CNTL1_2[1] |= var6;
write1byte(CNTL1_2);

 var7 = read1byte(CNTL1_3);
CNTL1_3[1] += var7;
write1byte(CNTL1_3);
// val8 = read1byte(CNTL1_4);
//CNTL1_4[1] |= val8;
//write1byte(CNTL1_4);
*/
 //

 write1byte(0x1B,0x80); //CNTL2);
delay(1000);

write1byte(0x1A,0x00);//CNTL1
write1byte(0x41,0x10); //THSHOLD
write1byte(0x42,0x27);

read1 = read1byte(0x1A);

write1byte(0x44,0x2C);//CNTL2
write1byte(0x37,0x7B);//CNTL
write1byte(0x26,0x00);//INC7
write1byte(0x20,0x00);//INC1 x20
write1byte(0x24,0x00);//INC5 x20

read2 = read1byte(0x1A);


write1byte(0x43,0x66);//PED_CENTL1);
write1byte(0x44,0x2C);//PED_CENTL2);
write1byte(0x45,0x17);//PED_CENTL3);
write1byte(0x46,0x1F);//PED_CENTL4);
write1byte(0x47,0x3C);//PED_CENTL5);
write1byte(0x48,0x14);//PED_CENTL6);
write1byte(0x49,0x0F);//PED_CENTL7);
write1byte(0x4A,0x08);//PED_CENTL8);
write1byte(0x4B,0x19);//PED_CENTL9);
write1byte(0x4C,0x1C);//PED_CENTL10);

read3 = read1byte(0x1A);


write1byte(0x1A,0xC2);//CNTL1

read4 = read1byte(0x1A);


read6 = 0;
while(1)
{
    //delay(100000);
//   var1 = read1byte(CNTL1_4);
    //read3 = read1byte(0x37);

   var2 = read1byte(0x11);//who_asked);
   read2 = read1byte(0x1A);

  // var1 = read1byte(0x1B);
  // read1 = read1byte(0x1B);
   //write1byte(0x43,0x10 +read1byte(0x43));
   delay(10);


   //   read7 = read_steps();
  // if ( read7 != 128) {
   //read6+= read7;
  // }


   //var3 = read_steps();
   //var6 = read1byte(CNTL1_2);
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
