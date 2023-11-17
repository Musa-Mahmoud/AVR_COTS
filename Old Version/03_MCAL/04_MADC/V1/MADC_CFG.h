
#ifndef _MADC_CFG_H_
#define _MADC_CFG_H_

/* To  select Voltage Reference Selection write:
	- 0 to AREF
	- 1 to AVCC
	- 2 is reserved
	- 3 to Internal 2.56V */
#define REFS_VALUE 1

/* Write: 
	- 0 to select single conversion mode
	- 1 to select free running mode */
#define CONVERSION_MODE 0

/* Write: 
	- 0 to disable interrupt
	- 1 to enable interrupt */
#define ADC_INT 0

/* Write: 
	- 0 to select to division factor of the MCU clock to 2
	- 1 to select to division factor of the MCU clock to 2
	- 2 to select to division factor of the MCU clock to 4
	- 3 to select to division factor of the MCU clock to 8
	- 4 to select to division factor of the MCU clock to 16
	- 5 to select to division factor of the MCU clock to 32
	- 6 to select to division factor of the MCU clock to 64
	- 7 to select to division factor of the MCU clock to 128	*/
#define PRESCALER_DIVISION_FACTOR 7

#endif