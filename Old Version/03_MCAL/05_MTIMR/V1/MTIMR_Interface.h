
#ifndef _MTIMR_INTERFACE_H_
#define _MTIMR_INTERFACE_H_


/*** Macros ***/


/*** Prototypes ***/

/** Timer 0 **/
void MTIMR0_VoidInit(void);

/* Fast PWM */
void MTIMR0_VoidFastPWM(void);

void MTIMR0_VoidSetDutyCycle(u8 Copy_U8DutyCycleValue);


/** Timer 1 **/


#endif