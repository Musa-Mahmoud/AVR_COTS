#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (Copy_u8Direction != PIN_INPUT && Copy_u8Direction != PIN_OUTPUT)
    {
        return NOT_OK;
    }

    if (PIN_OUTPUT == Copy_u8Direction)
    {
        if (A == Copy_u8Port)
        {
            SET_BIT(DDRA, Copy_u8Pin);
        }
        else if (B == Copy_u8Port)
        {
            SET_BIT(DDRB, Copy_u8Pin);
        }
        else if (C == Copy_u8Port)
        {
            SET_BIT(DDRC, Copy_u8Pin);
        }
        else
        {
            SET_BIT(DDRD, Copy_u8Pin);
        }
    }
    else
    {
        if (A == Copy_u8Port)
        {
            CLR_BIT(DDRA, Copy_u8Pin);
        }
        else if (B == Copy_u8Port)
        {
            CLR_BIT(DDRB, Copy_u8Pin);
        }
        else if (C == Copy_u8Port)
        {
            CLR_BIT(DDRC, Copy_u8Pin);
        }
        else
        {
            CLR_BIT(DDRD, Copy_u8Pin);
        }
    }

    return OK;
}

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    if (Copy_u8Port > PORT_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (A == Copy_u8Port)
    {
        DDRA = Copy_u8Direction;
    }
    else if (B == Copy_u8Port)
    {
        DDRB = Copy_u8Direction;
    }
    else if (C == Copy_u8Port)
    {
        DDRC = Copy_u8Direction;
    }
    else
    {
        DDRD = Copy_u8Direction;
    }

    return OK;
}

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (Copy_u8Value != PIN_HIGH && Copy_u8Value != PIN_LOW)
    {
        return NOT_OK;
    }

    if (PIN_HIGH == Copy_u8Value)
    {
        if (A == Copy_u8Port)
        {
            SET_BIT(PORTA, Copy_u8Pin);
        }
        else if (B == Copy_u8Port)
        {
            SET_BIT(PORTB, Copy_u8Pin);
        }
        else if (C == Copy_u8Port)
        {
            SET_BIT(PORTC, Copy_u8Pin);
        }
        else
        {
            SET_BIT(PORTD, Copy_u8Pin);
        }
    }
    else
    {
        if (A == Copy_u8Port)
        {
            CLR_BIT(PORTA, Copy_u8Pin);
        }
        else if (B == Copy_u8Port)
        {
            CLR_BIT(PORTB, Copy_u8Pin);
        }
        else if (C == Copy_u8Port)
        {
            CLR_BIT(PORTC, Copy_u8Pin);
        }
        else
        {
            CLR_BIT(PORTD, Copy_u8Pin);
        }
    }

    return OK;
}

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    if (Copy_u8Port > PORT_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (A == Copy_u8Port)
    {
        PORTA = Copy_u8Value;
    }
    else if (B == Copy_u8Port)
    {
        PORTB = Copy_u8Value;
    }
    else if (C == Copy_u8Port)
    {
        PORTC = Copy_u8Value;
    }
    else
    {
        PORTD = Copy_u8Value;
    }

    return OK;
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Value)
{
    if (Copy_u8Port > PORT_MAX_NUMBER || Copy_u8Pin > PIN_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (NULL == Copy_pu8Value)
    {
        return NOT_OK;
    }

    if (A == Copy_u8Port)
    {
        *Copy_pu8Value = GET_BIT(PINA, Copy_u8Pin);
    }
    else if (B == Copy_u8Port)
    {
        *Copy_pu8Value = GET_BIT(PINB, Copy_u8Pin);
    }
    else if (C == Copy_u8Port)
    {
        *Copy_pu8Value = GET_BIT(PINC, Copy_u8Pin);
    }
    else
    {
        *Copy_pu8Value = GET_BIT(PIND, Copy_u8Pin);
    }

    return OK;
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_pu8Value)
{
    if (Copy_u8Port > PORT_MAX_NUMBER)
    {
        return NOT_OK;
    }

    if (NULL == Copy_pu8Value)
    {
        return NOT_OK;
    }

    if (A == Copy_u8Port)
    {
        *Copy_pu8Value = PINA;
    }
    else if (B == Copy_u8Port)
    {
        *Copy_pu8Value = PINB;
    }
    else if (C == Copy_u8Port)
    {
        *Copy_pu8Value = PINC;
    }
    else
    {
        *Copy_pu8Value = PIND;
    }

    return OK;
}
