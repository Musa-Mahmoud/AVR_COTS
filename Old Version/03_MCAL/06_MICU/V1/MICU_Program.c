#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MICU_Private.h"

u8  GLB_U8Flag   = 0;
u32 GLB_U32Snap1 = 0;
u32 GLB_U32Snap2 = 0;
u32 GLB_U32Snap3 = 0;
u16 GLB_U16OverFlowCounter = 0;

void MICU_VoidInit(void)
{
	/* Selecting Timer1 Mode: non-PWM - Normal port operation, OC1A/OC1B disconnected */
	CLR_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1B1);
	CLR_BIT(TCCR1A, COM1A0);
	CLR_BIT(TCCR1A, COM1B0);

	/* Disableing Force Output Compare for Channel A/B: Zeros */
	CLR_BIT(TCCR1A, FOC1A);
	CLR_BIT(TCCR1A, FOC1B);
	
	/* Waveform Generation Mode: Normal */
	CLR_BIT(TCCR1A, WGM13);
	CLR_BIT(TCCR1A, WGM12);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1A, WGM10);
	
	/* Input Capture Noise Canceler: Disable */
	CLR_BIT(TCCR1B, ICNC1);
	
	/* Initalizing Input Capture Edge Select: Rising (positive) edge */
	SET_BIT(TCCR1B, ICES1);
	
	/* Prescaller value (Clock Select): clk/1 (No prescaling) */
	CLR_BIT(TCCR1B, CS12);
	CLR_BIT(TCCR1B, CS11);
	SET_BIT(TCCR1B, CS10);
	
	/* Timer/Counter1, Input Capture Interrupt: Enable */
	SET_BIT(TIMSK, TICIE1);
	
	/* Timer/Counter1, Output Compare A/B Match Interrupt: Disable/Disable */
	CLR_BIT(TIMSK, OCIE1A);
	CLR_BIT(TIMSK, OCIE1B);
	
	/* Timer/Counter1, Overflow Interrupt: Enable */
	SET_BIT(TIMSK, TOIE1);
	
}


/* Interrupt Vectors for Timer/Counter1 Capture Event */
void __vector_6(void)
{
	if(0 == GLB_U8Flag)
	{
		GLB_U32Snap1 = ICR1;
		/* Initalizing Input Capture Edge Select: falling (negative) edge */
		CLR_BIT(TCCR1B, ICES1);
		
		GLB_U8Flag = 1;
		GLB_U16OverFlowCounter = 0;
	}
	else if(1 == GLB_U8Flag)
	{
		GLB_U32Snap2 = ICR1 + (GLB_U16OverFlowCounter * 65536);
		/* Initalizing Input Capture Edge Select: rising (positive) edge */
		SET_BIT(TCCR1B, ICES1);
		GLB_U8Flag = 2;
	}
	else if(2 == GLB_U8Flag)
	{
		GLB_U32Snap3 = ICR1 + (GLB_U16OverFlowCounter * 65536);
		GLB_U8Flag = 3;
	}
}


/* Interrupt Vectors for Timer/Counter1 Overflow */
void __vector_9(void)
{
	GLB_U16OverFlowCounter++;
}