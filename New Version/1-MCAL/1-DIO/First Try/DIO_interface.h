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

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value);

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value);

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define A 0
#define B 1
#define C 2
#define D 3

#define PIN_LOW     0
#define PIN_HIGH    1
#define PORT_LOW    0x00
#define PORT_HIGH   0xff

#define PIN_INPUT   0
#define PIN_OUTPUT  1
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xff

#define NOT_OK  0
#define OK      1

#endif /* DIO_INTERFACE_H_ End */
