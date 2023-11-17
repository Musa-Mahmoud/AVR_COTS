/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    ADC                 ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define REFERENCE_SELECTION_POS     6
#define REFERENCE_SELECTION_MASK    0b00111111
#define AREF                        (0 << REFERENCE_SELECTION_POS)
#define AVCC                        (1 << REFERENCE_SELECTION_POS)
#define INTERNAL_2_56V              (3 << REFERENCE_SELECTION_POS)

#define PRESCALER_DIV_FACTOR_MASK   0b11111000
#define DIV_BY_2                    1
#define DIV_BY_4                    2
#define DIV_BY_8                    3
#define DIV_BY_16                   4
#define DIV_BY_32                   5
#define DIV_BY_64                   6
#define DIV_BY_128                  7

#define TEN_BIT                     10
#define EIGHT_BIT                   8

#define CHANNEL_RANGE_MASK          0b00011111

#define ANALOG_CHANNEL_MASK         0b11100000

#define INTERRUPT_FLAG_DOWN         0

#endif /* ADC_PRIVATE_H_ End */
