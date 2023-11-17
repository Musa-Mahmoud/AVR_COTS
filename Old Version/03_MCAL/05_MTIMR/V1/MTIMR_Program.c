#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTIMR_Private.h"
#include "MDIO_Interface.h"

/** TIMER 0 **/
void MTIMR0_VoidInit(void)
{
	/* Selecting the Mode: Normal Mode */
	CLR_BIT(TCCR0, FOC0);
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	/* Compare Match Output Mode: Normal port operation */
	CLR_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
	/* Clock Select: CLK/256 */
	SET_BIT(TCCR0, CS02);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS00);
	
	/** Enable PIE: Timer0 **/
	CLR_BIT(TIMSK, 1);
	SET_BIT(TIMSK, 0);
	
	
	/** Setting the TCNT0 to 238 **/
	TCNT0 = 238;
}


void __vector_11(void)
{
	static u8 counter;
	counter++;
	
	if(123 == counter)
	{
		TCNT0 = 238;
		
		MDIO_VoidTogglePinValue(PORTA_REG, PIN7);
	
		counter = 0;
	}
}


void MTIMR0_VoidFastPWM(void)
{
	/* Selecting the Mode: Fast PWS */
	CLR_BIT(TCCR0, FOC0);
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	/* Compare Match Output Mode: Clear OC0 on compare match, set OC0 at TOP */
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
	/* Clock Select: CLK/256 */
	SET_BIT(TCCR0, CS02);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS00);
	/** Disable PIE: Timer0 **/
	CLR_BIT(TIMSK, 1);
	CLR_BIT(TIMSK, 0);
	
}


void MTIMR_VoidSetDutyCycle(u8 Copy_U8DutyCycleValue)
{

	OCR0 = Copy_U8DutyCycleValue;
	
}

/** TIMER 1 **/