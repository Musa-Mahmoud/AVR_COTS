/**
  * Authar: Musa Mahmoud  *
  * Data: 6/10/2021		  *
  * Version: 1.0		  *
  * File Name: HKPD_CFG.h *
  * Descriotion: This configration file is for selecting the ports and the pin of the Keypad on the micro controller(M.C.) *
						  **/
						  
#ifndef _HKPD_CFG_H_
#define _HKPD_CFG_H_

/**
  * Write 0 for PORTA_REG,
  * Write 1 for PORTB_REG, 
  * Write 2 for PORTC_REG,
  * Write 3 for PORTD_REG 
						  **/
#define HKPD_PORT 0

/**
  * Write 0 for Pin Number 0,
  * Write 1 for Pin Number 1, 
  * Write 2 for Pin Number 2,
  * Write 3 for Pin Number 4,
  * Write 5 for Pin Number 5,
  * Write 6 for Pin Number 6,
  * Write 7 for Pin Number 7
						     **/
#define HKPD_ROW0_PIN 0
#define HKPD_ROW1_PIN 1
#define HKPD_ROW2_PIN 2
#define HKPD_ROW3_PIN 3

#define HKPD_COLUMN0_PIN 4
#define HKPD_COLUMN1_PIN 5
#define HKPD_COLUMN2_PIN 6
#define HKPD_COLUMN3_PIN 7


/** Keypad switches value **/
/* First inner array is for the top first row and so on */
#define KPD_LAYOUT { {'7', '8', '9', '/' }, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'C', '0', '=', '+'} }


/* The return value when there is no key is pressed */
#define HKPD_NOT_PRESSED_VALUE 255

#endif