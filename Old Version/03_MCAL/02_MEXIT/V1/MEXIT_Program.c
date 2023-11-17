#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MEXIT_Private.h"
#include "MDIO_Interface.h"

/* Globle pointer to function */
static void (*INT0CallBackPointer) (void);


/** INT0 **/
void MINT0_VoidInit(void)
{
	void MDIO_VoidActivatePinInternalPullupResistor(PORTD_REG, PIN2);
	
	/* Setting mode: 3)Falling edge */
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
}
void MINT0_VoidEnableINT(void)
{
	SET_BIT(GICR, 6);
}
void MINT0_VoidDisableINT(void)
{
	CLR_BIT(GICR, 6);
}
/* Call back function for ISR INT0*/
void MINT0_VoidSetCallBack(void(*Copy_PointerToFunction)(void))
{
	INT0CallBackPointer = Copy_PointerToFunction;
}


/** INT1 **/
void MINT1_VoidInit(void)
{
	
}
void MINT1_VoidEnableINT(void)
{
	
}
void MINT1_VoidDisableINT(void)
{
	
}


/** INT2 **/
void MINT2_VoidInit(void)
{
	
}
void MINT2_VoidEnableINT(void)
{
	
}
void MINT2_VoidDisableINT(void)
{
	
}


/** ISR for INT0 **/
void __vector_1(void)
{
	if(NULL != INT0CallBackPointer)
	{
		INT0CallBackPointer();
	}
}


