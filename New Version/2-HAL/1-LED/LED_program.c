/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    LED                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

u8 LED_u8TurnOn(LED_t *LedConfig)
{
    if(NULL == LedConfig)
    {
        return LED_u8NOT_OK;
    }

    if(LedConfig->Port > DIO_u8PORTD || LedConfig->Pin > DIO_u8PIN7)
    {
        return LED_u8NOT_OK;
    }

    if(LedConfig->ConnectionType != LED_u8SOURCE_CONNECTION && LedConfig->ConnectionType != LED_u8SINK_CONNECTION)
    {
        return LED_u8NOT_OK;
    }

    if(LED_u8SOURCE_CONNECTION == LedConfig->ConnectionType)
    {
        DIO_u8SetPinValue(LedConfig->Port, LedConfig->Pin, DIO_u8PIN_HIGH);
    }
    else
    {
        DIO_u8SetPinValue(LedConfig->Port, LedConfig->Pin, DIO_u8PIN_LOW);
    }

    return LED_u8OK;
}

u8 LED_u8TurnOff(LED_t *LedConfig)
{
    if(NULL == LedConfig)
    {
        return LED_u8NOT_OK;
    }

    if(LedConfig->Port > DIO_u8PORTD || LedConfig->Pin > DIO_u8PIN7)
    {
        return LED_u8NOT_OK;
    }

    if(LedConfig->ConnectionType != LED_u8SOURCE_CONNECTION && LedConfig->ConnectionType != LED_u8SINK_CONNECTION)
    {
        return LED_u8NOT_OK;
    }

    if(LED_u8SOURCE_CONNECTION == LedConfig->ConnectionType)
    {
        DIO_u8SetPinValue(LedConfig->Port, LedConfig->Pin, DIO_u8PIN_LOW);
    }
    else
    {
        DIO_u8SetPinValue(LedConfig->Port, LedConfig->Pin, DIO_u8PIN_HIGH);
    }

    return LED_u8OK;
}
