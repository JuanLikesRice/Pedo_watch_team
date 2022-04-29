/*
 * pedo.h
 *
 *  Created on: Apr 29, 2022
 *      Author: phuso
 */

#ifndef PEDO_H_
#define PEDO_H_
#include <msp430.h>
#include <stdint.h>
//#include <display.h>

//Define some Registers.
#define PED_STP_L 0x0E  // 16-bit pedometor counter register - p.35
#define PED_STP_H 0x0F  // 16-bit pedometor counter register - p.35
#define CNTL1 0x1A      // Control Register 1. Controls the main feature set - p.40
#define CNTL2 0x1B      // Control Register 2. Controls tilt position state enabling - p.41
#define INC1 0x20       // Interrupt Control 1. Controls the settings for INT1
#define INC5 0x24       // Interrupt Control 5. Controls the settings for INT2 - p.51
#define INC6 0x25       // Interrupt Control 6. Controls the routing for INT2 - p.52
#define INC7 0x26       // Interrupt Control 7. Pedometer Interrupt control - p.53
#define LP_CNTL 0x37    // Low Power Control - p.61
#define PED_STPWM_L 0x41// Pedometer Step Counter Watermark register - p.63
#define PED_STPWM_H 0x42// Pedometer Step Counter Watermark register - p.63
#define PED_CNTL1 0x43  // Pedometer Control register 1 - p.63
#define PED_CNTL2 0x44  // Pedometer Control register 2 - p.64
#define PED_CNTL3 0x45  // Pedometer Control register 3 - p.65
#define PED_CNTL4 0x46  // Pedometer Control register 4 - p.65
#define PED_CNTL5 0x47  // Pedometer Control register 5 - p.66
#define PED_CNTL6 0x48  // Pedometer Control register 6 - p.66
#define PED_CNTL7 0x49  // Pedometer Control register 7 - p.67
#define PED_CNTL8 0x4A  // Pedometer Control register 8 - p.67
#define PED_CNTL9 0x4B  // Pedometer Control register 9 - p.67
#define PED_CNTL10 0x4C // Pedometer Control register 10 - p.65

void pedo_spi_setup();
void init_pedo_interrupt();
void write1byte( uint8_t address_in, uint8_t value_in);
uint8_t read1byte( uint8_t address_in);
void pedo_init();

#endif /* PEDO_H_ */
