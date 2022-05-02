#include <msp430.h> 
#include "display.h"
#include "pedo.h"
/**
 * main.c
 *
 *This code is ssplit into two main parts: The pedometer and the display
 *
 *  Both Modules work based on SPI
 *
 * 
 *  Pedometer 
 *  This sends and recives 8 bytes of data to the KX126 1063 sensor
 *   pedo_spi_setup() 
 *      - sets up configureation for the MSP430 to talk to the pedometer, 
 *      - This sets SPI clock, rate, phase, pins used etc
 *
 *  init_pedo_interrupt()
 *      - Sets up the confirgatuion for sensing when the pedometer intereupt pins, 
 *      this pin will go low and let the MSP430 its ready to read steps 
 *
 *  write1byte( uint8_t address_in, uint8_t value_in)
 *       - sends two bytes to kx126 sensor, it sends nCs low and then sends two bytes, after which nCs goes high
 *       - The first byte - address_in will be address the sensor is writting to, the sensor will need this to go into read steps mode   
 *       - The second byte - Value in - will be what the value the address will be sent to
 *
 *  read1byte( uint8_t address_in)
 *      - sends two bytes to kx126 sensor, it sends nCs low and then sends two bytes, after which nCs goes high, 
 *  after the second byte is sent, the buffer is read on the RX buff
 *      - Address_in will be what is sent out, note that for the kx126 to recongnize that the Master wants to read, the MSB byte of the 
 *   byte will be 1, henxe why 0x80 will be added to the adress vlue sent out, 
 *      - The second Byte sent on TX buffer the will give a clock signal for the sensor and its value will not matter, during this clock cycle  
 *  the sensor will send out the value for the adress and will be recived on the RX buffer 
 *
 *  pedo_init()
 *      - This will use the read1byte, and write1byte to configure the sensor to read steps instead of just act as acceleroneter
 *      - The Data sheet of the Kx236 gave values to send out, these values would configure to read normal walking steps on pedometer

 *
 *
 *
 *  pins used
 * 1.1 MISO 
 * 1.2 MOSI
 * 1.4 ClK
 * 2.7 nCs 
 * 2.2 Int 1 Pin
 * 2.3 Int 2 Pin
 *
 *  Display 
 *  The display will be in charge of what communivateing with the SPI screen
 *
 *
 *
 *
 *
 */
int main(void)
{
    _enable_interrupts();
    pedo_spi_setup();
    __delay_cycles(6000);
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


