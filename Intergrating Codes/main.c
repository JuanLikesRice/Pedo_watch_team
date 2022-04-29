#include <msp430.h> 
#include "display.h"
#include "pedo.h"
/**
 * main.c
 */
int main(void)
{
    _enable_interrupts();
    pedo_spi_setup();
    __delay_cycles(10);
    pedo_init();

//    while(1);
    //Display Set up and show clock
    display_spi_setup();
    delay_setup();
    P1OUT &= ~BIT6; // chip select low
    initDisplay();
    sendScreenColor(BLACK);
    init_pedo_interrupt();
    displayClock();
}
//uint8_t low;
//uint8_t high;
//uint8_t steps;
//#pragma vector=PORT2_VECTOR
//__interrupt void button(void)
//{
//    P2IFG &= ~(BIT2);//Clear the button press.
//    while(!(P2IN & BIT2)){
//        __delay_cycles(100000);
//        low =  read1byte(0x0E);//KX126_PED_STEP_L);
//        high = read1byte(0x0F);
//        steps += low;
//    }
//    char buffer[6];
//    char display[14] = "Steps: ";
//    itoa(steps,buffer,5);
//    strcat(display,buffer);
//    drawString(display, 0x0F, 0x0F, 0x05);
//    delay(10900);
//    sendScreenColor(BLACK);
//    LPM3_EXIT;
//}
