#include "STD_TYPES.h"
#include "BIT_Math.h"
#include "MWDT_Private.h"


void MWDT_VoidEnable(void)
{
	/* Watchdog State: Enable */
	SET_BIT(WDTCR, WDE);
	/* Watchdog Timer Prescaler: Vcc = 5, Typical Time-out = 1.0s */
	SET_BIT(WDTCR, WDP2);
	SET_BIT(WDTCR, WDP1);
	CLR_BIT(WDTCR, WDP0);
}

void MWDT_VoidDisable(void)
{
	WDTCR = (1 << WDTOE) | (1 << WDE);
	WDTCR = 0x00;
}
