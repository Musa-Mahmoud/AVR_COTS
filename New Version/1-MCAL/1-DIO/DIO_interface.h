/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    DIO                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#if IS_PORT_DRIVER_USED == NOT_USED

#define DIO_u8PIN_OUTPUT 	1
#define DIO_u8PIN_INPUT		0

#define DIO_u8PORT_OUTPUT	0xff
#define DIO_u8PORT_INPUT	0x00

#endif /* IS_PORT_DRIVER_USED == NOT_USED End */

#define DIO_u8PIN_HIGH		1
#define DIO_u8PIN_LOW		0

#define DIO_u8PORT_HIGH		0xff
#define DIO_u8PORT_LOW		0x00

#define DIO_u8PORTA			0
#define DIO_u8PORTB			1
#define DIO_u8PORTC			2
#define DIO_u8PORTD			3

#define DIO_u8PIN0			0
#define DIO_u8PIN1			1
#define DIO_u8PIN2			2
#define DIO_u8PIN3			3
#define DIO_u8PIN4			4
#define DIO_u8PIN5			5
#define DIO_u8PIN6			6
#define DIO_u8PIN7			7

#define DIO_u8A				0
#define DIO_u8B				1
#define DIO_u8C				2
#define DIO_u8D				3

#define DIO_u8NOT_OK		0
#define DIO_u8OK			1

#if IS_PORT_DRIVER_USED == NOT_USED

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

#endif /* IS_PORT_DRIVER_USED == NOT_USED End */

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value);


#endif /* DIO_INTERFACE_H_ End */
