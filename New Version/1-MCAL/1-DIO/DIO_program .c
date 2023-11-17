/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    DIO                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"

#if IS_PORT_DRIVER_USED == NOT_USED

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	if (Copy_u8Direction != DIO_u8PIN_INPUT && Copy_u8Direction != DIO_u8PIN_OUTPUT)
	{
		return DIO_u8NOT_OK;
	}

	if (DIO_u8PIN_INPUT == Copy_u8Direction)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
		case DIO_u8PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
		case DIO_u8PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
		case DIO_u8PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
		}
	}
	else
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
		case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
		case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
		case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
		}
	}

	return DIO_u8OK;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	if (Copy_u8Port > PORT_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: DDRA = Copy_u8Direction; break;
	case DIO_u8PORTB: DDRB = Copy_u8Direction; break;
	case DIO_u8PORTC: DDRC = Copy_u8Direction; break;
	case DIO_u8PORTD: DDRD = Copy_u8Direction; break;
	}

	return DIO_u8OK;
}

#endif /* IS_PORT_DRIVER_USED == NOT_USED End */

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	if (Copy_u8Value != DIO_u8PIN_LOW && Copy_u8Value != DIO_u8PIN_HIGH)
	{
		return DIO_u8NOT_OK;
	}

	if (DIO_u8PIN_LOW == Copy_u8Value)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
		case DIO_u8PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
		case DIO_u8PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
		case DIO_u8PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
		}
	}
	else
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
		case DIO_u8PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
		case DIO_u8PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
		case DIO_u8PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
		}
	}

	return DIO_u8OK;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	if (Copy_u8Port > PORT_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: PORTA = Copy_u8Value; break;
	case DIO_u8PORTB: PORTB = Copy_u8Value; break;
	case DIO_u8PORTC: PORTC = Copy_u8Value; break;
	case DIO_u8PORTD: PORTD = Copy_u8Value; break;
	}

	return DIO_u8OK;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
	if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	if(NULL == Copy_pu8Value)
	{
		return DIO_u8NOT_OK;
	}

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin); break;
	case DIO_u8PORTB: *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin); break;
	case DIO_u8PORTC: *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin); break;
	case DIO_u8PORTD: *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin); break;
	}

	return DIO_u8OK;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value)
{
	if (Copy_u8Port > PORT_MAX_NUMBER)
	{
		return DIO_u8NOT_OK;
	}

	if(NULL == Copy_pu8Value)
	{
		return DIO_u8NOT_OK;
	}

	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: *Copy_pu8Value = PINA; break;
	case DIO_u8PORTB: *Copy_pu8Value = PINB; break;
	case DIO_u8PORTC: *Copy_pu8Value = PINC; break;
	case DIO_u8PORTD: *Copy_pu8Value = PIND; break;
	}

	return DIO_u8OK;
}
