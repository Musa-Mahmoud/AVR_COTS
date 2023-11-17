#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_CFG.h"
#include "MADC_Private.h"


void MADC_VoidInit(void)
{
	/* Enable ADC enable bit */
	SET_BIT(ADCSRA, ADEN);
	
	/* Trigger Mode */
	#if CONVERSION_MODE == SINGLE_CONVERSION
		/* Enable the Single Conversion mode */
		CLR_BIT(ADCSRA, ADATE);
	#elif CONVERSION_MODE == FREE_RUNNING
		/* Enable the Free Running mode */
		SET_BIT(ADCSRA, ADATE);
		/* Strtting the first conversion */
		SET_BIT(ADCSRA, ADSC);
	#endif
	
	/* Selecting the voltage reference for the ADC */
	ADMUX = (ADMUX & 0b00111111) | (REFS_VALUE << 6);
	
	/* Enabling or Disabling the interrupt */
	#if ADC_INT == ENABLE
		SET_BIT(ADCSRA, ADIE);
	#elif ADC_INT == DISABLE
		CLR_BIT(ADCSRA, ADIE);
	#endif
	
	/* Prescaler Select Bits */
	ADCSRA = (ADCSRA & 0b11111000) | PRESCALER_DIVISION_FACTOR;
	
	/* Setting ADC Left Adjust Result(ADLAR) to right adgusted */
	CLR_BIT(ADMUX, ADLAR);
	
	
}


u16 MADC_U8ReadData(u8 Copy_U8ChannelNumber)
{
	/* Forceing the user to enter a channel in range of 0 to 7 */
	Copy_U8ChannelNumber &= 0b00000111;
	
	/* Selecting the channel number */
	ADMUX = (ADMUX & 0b11100000) | Copy_U8ChannelNumber ;
	
	#if CONVERSION_MODE == SINGLE_CONVERSION
		/* Start conversion in Single Conversion mode */
		SET_BIT(ADCSRA, ADSC);
	#endif
	
	/* Wainting untill the conversion is finshed */
	while(STILL_CONVERSIONNING == GET_BIT(ADCSRA, ADIF));
	
	/* Returning the ADC data value */
	return ADC_DATA;
	
}
