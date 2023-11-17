/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SW                  ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SW_config.h"
#include "SW_private.h"
#include "SW_interface.h"


u8 static inline IsArgumentsValid(SW_t *SwitchConfig)
{
    if(NULL == SwitchConfig)
    {
        return NOT_VALID;
    }

    if(SwitchConfig->Port > DIO_u8PORTD || SwitchConfig->Pin > DIO_u8PIN7)
    {
        return NOT_VALID;
    }

    if(SwitchConfig->SwitchType != SW_u8PERMANENT && SwitchConfig->SwitchType != SW_u8TEMPORARY)
    {
        return NOT_VALID;
    }

    if(SwitchConfig->PullType != SW_u8PULL_UP && SwitchConfig->PullType != SW_u8PULL_DOWN)
    {
        return NOT_VALID;
    }

    return VALID;
}

#if (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK)

u8 SW_u8GetStateSWDebounce(SW_t *SwitchConfig, u8 *Copy_pu8SwitchState, SW_Callback Delay, double Copy_u8DelayAmount)
{
    u8 Local_u8PinValue;

    if(NOT_VALID == IsArgumentsValid(SwitchConfig) || NULL == Copy_pu8SwitchState)
    {
        return SW_u8NOT_OK;
    }

    /* Applying software debouncing using wait and double check technique */
    /* Check if the button is temporary(not a self-locking) then debounce it */
    if(SW_u8TEMPORARY == SwitchConfig->SwitchType)
    {   
        /* Getting the pin value and debouncing using wait and double check technique */
        if(DIO_u8OK == DIO_u8GetPinValue(SwitchConfig->Port, SwitchConfig->Pin, &Local_u8PinValue))
        {
            Delay(Copy_u8DelayAmount);
            /* Getting the pin value */
            if(DIO_u8NOT_OK == DIO_u8GetPinValue(SwitchConfig->Port, SwitchConfig->Pin, &Local_u8PinValue))
            {
                return DIO_u8NOT_OK;
            }
        }
        else
        {
            return DIO_u8NOT_OK;
        }
    }
    else if(SW_u8PERMANENT == SwitchConfig->SwitchType)
    {
        /* Getting the pin value */
        if(DIO_u8NOT_OK == DIO_u8GetPinValue(SwitchConfig->Port, SwitchConfig->Pin, &Local_u8PinValue))
        {
            return DIO_u8NOT_OK;
        }
    }

    if(SW_u8PULL_UP == SwitchConfig->PullType)
    {
        if(Local_u8PinValue == 0)
        {
            *Copy_pu8SwitchState = SW_u8PRESSED;
        }
        else
        {
            *Copy_pu8SwitchState = SW_u8NOT_PRESSED;
        }
    }
    else if(SW_u8PULL_DOWN == SwitchConfig->PullType)
    {
        if(0 == Local_u8PinValue)
        {
            *Copy_pu8SwitchState = SW_u8NOT_PRESSED;
        }
        else if(1 == Local_u8PinValue)
        {
            *Copy_pu8SwitchState = SW_u8PRESSED;
        }
    }

    return SW_u8OK;
}
#endif /* (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK) End */

#if IS_PERMANENT_SWITCH_USED == USED

u8 SW_u8GetState(SW_t *SwitchConfig, u8 *Copy_pu8SwitchState)
{
    u8 Local_u8PinValue;

    if(NOT_VALID == IsArgumentsValid(SwitchConfig) || NULL == Copy_pu8SwitchState)
    {
        return SW_u8NOT_OK;
    }

    /* Getting the pin value */
    if(DIO_u8NOT_OK == DIO_u8GetPinValue(SwitchConfig->Port, SwitchConfig->Pin, &Local_u8PinValue))
    {
        return DIO_u8NOT_OK;
    }

    if(SW_u8PULL_UP == SwitchConfig->PullType)
    {
        if(Local_u8PinValue == 0)
        {
            *Copy_pu8SwitchState = SW_u8PRESSED;
        }
        else
        {
            *Copy_pu8SwitchState = SW_u8NOT_PRESSED;
        }
    }
    else if(SW_u8PULL_DOWN == SwitchConfig->PullType)
    {
        if(0 == Local_u8PinValue)
        {
            *Copy_pu8SwitchState = SW_u8NOT_PRESSED;
        }
        else if(1 == Local_u8PinValue)
        {
            *Copy_pu8SwitchState = SW_u8PRESSED;
        }
    }

    return SW_u8OK;
}

#endif /* IS_PERMANENT_SWITCH_USED == USED End */
