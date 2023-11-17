/**
  * Authar: Musa Mahmoud  *
  * Data: 9/24/2021		  *
  * Version: 1.0		  *
  * File Name: HLCD_CFG.h *
  * Descriotion: This configration file is for selecting the ports and the pin of the LCD on the micro controller(M.C.) *
						  **/


#ifndef _HLCD_CFG_H_
#define _HLCD_CFG_H_

/**
  * Write 0 for PORTA_REG,
  * Write 1 for PORTB_REG, 
  * Write 2 for PORTC_REG,
  * Write 3 for PORTD_REG 
					 **/
#define HLCD_U8DataPort    2

/** Write a number from 0 to 7 to choose the M.C. pin **/
#define HLCD_U8ControlPort 1

/** Write a number from 0 to 7 to choose the M.C. pin for the register selection **/
#define HLCD_U8RSPin       0

/** Write a number from 0 to 7 to choose the M.C. pin for reading/writting from/on the LCD **/
#define HLCD_U8RWPin       1

/** Write a number from 0 to 7 to choose the M.C. pin for enableing the sequence **/
#define HLCD_U8ENPin       2


#endif