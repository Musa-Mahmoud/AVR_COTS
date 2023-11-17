/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    CLCD                ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_


#define CLCD_DATA_PORT      DIO_u8PORTA

#define CLCD_CTRL_PORT      DIO_u8PORTC
#define CLCD_RS_PIN         DIO_u8PIN0
#define CLCD_RW_PIN         DIO_u8PIN1
#define CLCD_E_PIN          DIO_u8PIN2

/* Write:
 * FOUR_BIT_MODE: To use theLCD in 4-bit mode
 * EIGHT_BIT_MODE: To use the LCD in 8-bit mode
 * 
 */
#define CLCD_MODE           FOUR_BIT_MODE


#endif /* CLCD_CONFIG_H_ End */
