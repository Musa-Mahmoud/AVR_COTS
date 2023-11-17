/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SSD                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"

u8 static inline IsConfigurationValid(SSD_t *SSDConfig)
{
    if( (SSDConfig->ComType != SSD_u8COM_ANODE && SSDConfig->ComType != SSD_u8COM_CATHODE) \
        || SSDConfig->Port > DIO_u8PORTD \
        || SSDConfig->EnablePort > DIO_u8PORTD \
        || SSDConfig->EnablePin > DIO_u8PIN7 \
        || SSDConfig->DPPort > DIO_u8PORTD \
        || SSDConfig->DPPin > DIO_u8PIN7)
    {
        return SSD_u8NOT_OK;
    }

    return SSD_u8OK;
}

u8 SSD_u8DisplayNumber(SSD_t *SSDConfig, u8 Copy_u8Number)
{
    if(!IsConfigurationValid(SSDConfig))
    {
        return SSD_u8NOT_OK;
    }
    
    if(Copy_u8Number > 9)
    {
        return SSD_u8NOT_OK;
    }

    if(SSDConfig->ComType == SSD_u8COM_ANODE)
    {
        DIO_u8SetPortValue(SSDConfig->Port, SSD_Numbers[Copy_u8Number]);
    }
    else if(SSDConfig->ComType == SSD_u8COM_CATHODE)
    {
        DIO_u8SetPortValue(SSDConfig->Port, ~SSD_Numbers[Copy_u8Number]);
    }

    return SSD_u8OK;
}

u8 SSD_u8Enable(SSD_t *SSDConfig)
{
    if(!IsConfigurationValid(SSDConfig))
    {
        return SSD_u8NOT_OK;
    }

    if(SSDConfig->ComType == SSD_u8COM_ANODE)
    {
        DIO_u8SetPinValue(SSDConfig->EnablePort, SSDConfig->EnablePin, DIO_u8PIN_HIGH);
    }
    else if(SSDConfig->ComType == SSD_u8COM_CATHODE)
    {
        DIO_u8SetPinValue(SSDConfig->EnablePort, SSDConfig->EnablePin, DIO_u8PIN_LOW);
    }

    return SSD_u8OK;
}

u8 SSD_u8Disable(SSD_t *SSDConfig)
{
    if(!IsConfigurationValid(SSDConfig))
    {
        return SSD_u8NOT_OK;
    }

    if(SSDConfig->ComType == SSD_u8COM_ANODE)
    {
        DIO_u8SetPinValue(SSDConfig->EnablePort, SSDConfig->EnablePin, DIO_u8PIN_LOW);
    }
    else if(SSDConfig->ComType == SSD_u8COM_CATHODE)
    {
        DIO_u8SetPinValue(SSDConfig->EnablePort, SSDConfig->EnablePin, DIO_u8PIN_HIGH);
    }

    return SSD_u8OK;
}

u8 SSD_u8EnableDecimalPoint(SSD_t *SSDConfig)
{
    if(!IsConfigurationValid(SSDConfig))
    {
        return SSD_u8NOT_OK;
    }

    if(SSDConfig->ComType == SSD_u8COM_ANODE)
    {
        DIO_u8SetPinValue(SSDConfig->DPPort, SSDConfig->DPPin, DIO_u8PIN_LOW);
    }
    else if(SSDConfig->ComType == SSD_u8COM_CATHODE)
    {
        DIO_u8SetPinValue(SSDConfig->DPPort, SSDConfig->DPPin, DIO_u8PIN_HIGH);
    }

    return SSD_u8OK;
}

u8 SSD_u8DisableDecimalPoint(SSD_t *SSDConfig)
{
    if(!IsConfigurationValid(SSDConfig))
    {
        return SSD_u8NOT_OK;
    }

    if(SSDConfig->ComType == SSD_u8COM_ANODE)
    {
        DIO_u8SetPinValue(SSDConfig->DPPort, SSDConfig->DPPin, DIO_u8PIN_HIGH);
    }
    else if(SSDConfig->ComType == SSD_u8COM_CATHODE)
    {
        DIO_u8SetPinValue(SSDConfig->DPPort, SSDConfig->DPPin, DIO_u8PIN_LOW);
    }

    return SSD_u8OK;
}
