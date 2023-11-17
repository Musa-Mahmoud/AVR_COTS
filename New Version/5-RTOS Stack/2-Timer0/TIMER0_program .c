/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  RTOS Stack          ************************/
/************************        SWC:    TIMER0              ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_register.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

static void (*Timer0_pvCompMatchCallbackFunc) (void) = NULL;

void Timer0_voidInit(void)
{
	/* Initialize waveform generation mode to work as CTC mode */
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);

	/* Set the required compare match value */
	OCR0 = TIMER0_u8COMP_MATCH_VAL;

	/* Timer0 compare match interrupt enable */
	SET_BIT(TIMSK, TIMSK_OCIE0);

	/* Set the required pre-scaler */
	TCCR0 &= TIMER0_PRESCALER_MASK;
	TCCR0 |= TIMER0_u8PRESCALER;
}

u8 Timer0_u8OverflowSetCallback(void (*Copy_pvCallbackFunc) (void))
{
	u8 Local_u8ErrorState = OK;

	if (NULL != Copy_pvCallbackFunc)
	{
		Timer0_pvCompMatchCallbackFunc = Copy_pvCallbackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

	return Local_u8ErrorState;
}

/* Timer0 Compare Match ISR */
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if (NULL != Timer0_pvCompMatchCallbackFunc)
	{
		Timer0_pvCompMatchCallbackFunc();
	}
}
