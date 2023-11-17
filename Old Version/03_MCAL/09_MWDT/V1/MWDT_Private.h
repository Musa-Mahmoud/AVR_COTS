
#ifndef _MWDT_PRIVATE_H_
#define _MWDT_PRIVATE_H_

/*** Macros ***/

/** Watchdog Timer Control Register – WDTCR**/
// Reserved   7
// Reserved   6
// Reserved   5
#define WDTOE 4
#define WDE   3
#define WDP2  2
#define WDP1  1
#define WDP0  0


/*** WDT Registers' Addresses ***/
#define WDTCR *((volatile u8*) 0x41)

#endif