#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MGIE_Private.h"

void MGIE_VoidEnable(void)
{
	SET_BIT(SREG, I);
}
void MGIE_VoidDisable(void)
{
	CLR_BIT(SREG, I);
}