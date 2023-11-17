/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SW                  ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_


#define SW_u8PERMANENT      0
#define SW_u8TEMPORARY      1

#define SW_u8PULL_UP        0
#define SW_u8PULL_DOWN      1

#define SW_u8PRESSED        0
#define SW_u8NOT_PRESSED    1

#define SW_u8OK             1
#define SW_u8NOT_OK         0

#if (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK)

typedef void (*SW_Callback)(double);

#endif /* (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK) End */

typedef struct SW
{
    u8 Port;
    u8 Pin;
    u8 SwitchType;
    u8 PullType;
} SW_t;

#if (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK)

u8 SW_u8GetStateSWDebounce(SW_t *SwitchConfig, u8 *Copy_pu8SwitchState, SW_Callback Delay, double Copy_u8DelayAmount);

#endif /* (SOFTWARE_DEBOUNCING == ENABLED) && (DEBOUNCING_TECHNIQUE == WAIT_AND_DOUBLE_CHECK) End */

#if IS_PERMANENT_SWITCH_USED == USED

u8 SW_u8GetState(SW_t *SwitchConfig, u8 *Copy_pu8SwitchState);

#endif /* IS_PERMANENT_SWITCH_USED == USED End */

/* Private Functions Prototypes */
u8 static inline IsArgumentsValid(SW_t *SwitchConfig);


#endif /* SW_INTERFACE_H_ End */
