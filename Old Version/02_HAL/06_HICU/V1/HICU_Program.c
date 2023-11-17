#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MEXIT_Interface.h"
#include "MGIE_Interface.h"
#include "MTIMR_Interface.h"

/** Global Varibales **/
u8  GLB_U8Flag = 0;
u16 GLB_U16OverFlowCounter = 0;


/** Software ICU using EXIT0 with Timer0 **/
void ISR_EXIT0(void)
{
	if(0 == GLB_U8Flag)
	{
		/* Timer 0 is On */
		void MTIMR0_VoidInit(void);
		/* ISC sence the falling edge */
	}
	else if(1 == GLB_U8Flag)
	{
		
	}
	else if(2 == GLB_U8Flag)
	{
		
	}
}

void ISR_Timer0(void)
{
	GLB_U16OverFlowCounter++;
}

void HICU0_VoidInit(void)
{
	MINT0_VoidSetCallBack();
}


/** Software ICU using EXIT1 with Timer0 **/
void HICU1_VoidInit(void)
{
	
}


/** Software ICU using EXIT2 with Timer0 **/
void HICU2_VoidInit(void)
{
	
}