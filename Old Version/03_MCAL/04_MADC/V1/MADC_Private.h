
#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_


/*** Macros ***/

/** ADMUX Macros **/
/* Reference Selection Bits: value 0 0 for AREF, value 0 1 for AVCC, value 1 0 Reserved, value 1 1 for internal 2.56V */
#define REFS1 7
#define REFS0 6
/* ADC Left Adjust Result: value 1 for left adjust, value 0 for right adjust */
#define ADLAR 5
/* Analog Channel and Gain Selection Bits. The value of these bits 
   selects which combination of analog inputs are connected to the ADC.
   These bits also select the gain for the differential channels */
#define MUX4 4 
#define MUX3 3 
#define MUX2 2 
#define MUX1 1 
#define MUX0 0 



/** ADCSRA Macros **/

/* ADC Enable: 1 to enable, 0 to disable */
#define ADEN   7

/* ADC Start Conversion: 
   - In Single Conversion mode, write this bit to one to start each conversion. 
   - In Free RunningMode, write this bit to one to start the first conversion. */
#define ADSC   6

/* ADC Auto Trigger Enable: When this bit is written to one, Auto Triggering of the ADC is enabled. */
#define ADATE  5

/* ADC Interrupt Flag: This bit is set when an ADC conversion completes and the Data Registers are updated */
#define ADIF   4

/* ADC Interrupt Enable: 
   - When this bit is written to one 
   - and the I-bit in SREG is set 
   - , the ADC Conversion Complete
   - Interrupt is activated. */
#define ADIE   3

/* ADC Prescaler Select Bits: 
   - These bits determine the division factor between the XTAL frequency (System Clock) and the input clock to the ADC.
   - Takes the values from 0 to 7 to represented in binary determine the division factor value from 2 to 128  */
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0


/** Trigger Mode **/
#define SINGLE_CONVERSION 0
#define FREE_RUNNING 1


/** State **/
#define ENABLE 1
#define DISABLE 0
#define STILL_CONVERSIONNING 0



/*** ADC Registers' Addresses ***/
#define ADMUX    *((volatile u8*) 0x27)
#define ADCSRA   *((volatile u8*) 0x26)
#define ADCH     *((volatile u8*) 0x25)
#define ADCL     *((volatile u8*) 0x24)
#define ADC_DATA *((volatile u16*)0x24)
#define SFIOR    *((volatile u8*) 0x50)

#endif