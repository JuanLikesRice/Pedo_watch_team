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


