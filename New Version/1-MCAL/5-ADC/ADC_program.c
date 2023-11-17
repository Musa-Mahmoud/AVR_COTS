/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    ADC                 ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"


void ADC_voidInit(void) 
{
    /* Check reference selection */
#if (VOLTAGE_REFERENCE > INTERNAL_2_56V) || (VOLTAGE_REFERENCE < AREF)
#error "Wrong VOLTAGE_REFERENCE configuration option"
#else
    /* Clear the REFS bits in ADMUX register */
    ADMUX &= REFERENCE_SELECTION_MASK;
    /* Set reference selection to configured voltage reference */
    ADMUX |= VOLTAGE_REFERENCE;
#endif

    /* ADC Left Adjust Result: left adjust(activated) */
    SET_BIT(ADMUX, ADMUX_ADLAR);

    /* Check ADC prescaler selection */
#if (PRESCALER_DIV_FACTOR > DIV_BY_128) || (PRESCALER_DIV_FACTOR < DIV_BY_2)
#error "Wrong PRESCALER_DIV_FACTOR_MASK configuration option"
#else
    /* Clear the ADPS bits in ADCSRA register */
    ADCSRA &= PRESCALER_DIV_FACTOR_MASK;
    /* Set prescaler division factor to the configured one */
    ADCSRA |= PRESCALER_DIV_FACTOR;
#endif

    /* ADC enable: enable */
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
    /* Ensure that the channel in the allowed range */
    Copy_u8Channel &= CHANNEL_RANGE_MASK;
    /* Clear the MUX bits in ADMUX register */
    ADMUX &= ANALOG_CHANNEL_MASK;
    /* Set the required channel into the MUX bits */
    ADMUX |= Copy_u8Channel;
    /* Start conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
    /* Polling(busy waiting) util the conversion complete flag is set */
    while (INTERRUPT_FLAG_DOWN == GET_BIT(ADCSRA, ADCSRA_ADIF));
    /* Clear the conversion complete flag */
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    /* Return the reading */
    return ADCH;
}
