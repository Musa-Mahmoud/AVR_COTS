/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    ADC                 ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* Functions' Prototypes */
void ADC_voidInit(void);

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);

/* Analog Channel and Gain Selection Options */
#define ADC_u8SINGLE_ENDED_ADC0           0
#define ADC_u8SINGLE_ENDED_ADC1           1
#define ADC_u8SINGLE_ENDED_ADC2           2
#define ADC_u8SINGLE_ENDED_ADC3           3
#define ADC_u8SINGLE_ENDED_ADC4           4
#define ADC_u8SINGLE_ENDED_ADC5           5
#define ADC_u8SINGLE_ENDED_ADC6           6
#define ADC_u8SINGLE_ENDED_ADC7           7

#define ADC_u8DIFFERENTIAL_ADC0_ADC0_X10  8
#define ADC_u8DIFFERENTIAL_ADC1_ADC0_X10  9  
#define ADC_u8DIFFERENTIAL_ADC0_ADC0_X200 10  
#define ADC_u8DIFFERENTIAL_ADC1_ADC0_X200 11
#define ADC_u8DIFFERENTIAL_ADC2_ADC2_X10  12  
#define ADC_u8DIFFERENTIAL_ADC3_ADC2_X10  13  
#define ADC_u8DIFFERENTIAL_ADC2_ADC2_X200 14  
#define ADC_u8DIFFERENTIAL_ADC3_ADC2_X200 15  
#define ADC_u8DIFFERENTIAL_ADC0_ADC1_X1   16
#define ADC_u8DIFFERENTIAL_ADC1_ADC1_X1   17
#define ADC_u8DIFFERENTIAL_ADC2_ADC1_X1   18
#define ADC_u8DIFFERENTIAL_ADC3_ADC1_X1   19
#define ADC_u8DIFFERENTIAL_ADC4_ADC1_X1   20
#define ADC_u8DIFFERENTIAL_ADC5_ADC1_X1   21
#define ADC_u8DIFFERENTIAL_ADC6_ADC1_X1   22
#define ADC_u8DIFFERENTIAL_ADC7_ADC1_X1   23
#define ADC_u8DIFFERENTIAL_ADC0_ADC2_X1   24
#define ADC_u8DIFFERENTIAL_ADC1_ADC2_X1   25
#define ADC_u8DIFFERENTIAL_ADC2_ADC2_X1   26
#define ADC_u8DIFFERENTIAL_ADC3_ADC2_X1   27
#define ADC_u8DIFFERENTIAL_ADC4_ADC2_X1   28
#define ADC_u8DIFFERENTIAL_ADC5_ADC2_X1   29
#define ADC_u8SINGLE_ENDED_1_22V          30
#define ADC_u8SINGLE_ENDED_0V             31

/* ADC Auto Trigger Source */
#define ADC_FREE_RUNNING_MODE             0
#define ADC_ANALOG_COMPARATOR             1
#define ADC_EXTERNAL_INTERRUPT_REQUEST    2
#define ADC_COUNTER0_COMPARE_MATCH        3
#define ADC_COUNTER0_OVERFLOW             4
#define ADC_COUNTER_COMPARE_MATCHB        5
#define ADC_COUNTER1_OVERFLOW             6
#define ADC_COUNTER1_CAPTURE_EVENT        7

#endif /* ADC_INTERFACE_H_ End */
