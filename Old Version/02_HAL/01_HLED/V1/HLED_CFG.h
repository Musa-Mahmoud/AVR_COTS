
#ifndef	_HLED_CFG_H_
#define	_HLED_CFG_H_

/*** Macros ***/
#define NEGATIVE_LOGIC 0

#define POSITIVE_LOGIC 1


/*
 * Description: Choose your LED connection type between positive logic or negative logic by writing: 
 * 0 or NEGATIVE_LOGIC -> for negative logic
 * 1 or POSITIVE_LOGIC -> for positive logic
 * Negative Logic: When you connect the cathode(-) of the LED to the MCU port and the anode(+) to the power source(Vcc) it's called negative logic.
 * Positive Logic: When you connect the anode(+) of the LED to the MCU port and the cathode(-) to the ground(gnd) it's called positive logic.
 */

#define LED_CONNECTION_TYPE POSITIVE_LOGIC

#endif