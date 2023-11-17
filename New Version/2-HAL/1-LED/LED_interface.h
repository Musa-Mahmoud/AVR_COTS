/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    LED                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#define LED_u8SOURCE_CONNECTION     1
#define LED_u8SINK_CONNECTION       0

#define LED_u8OK        1
#define LED_u8NOT_OK    0

typedef struct LED
{
    u8 Port;
    u8 Pin;
    u8 ConnectionType;
}LED_t;

u8 LED_u8TurnOn(LED_t *LedConfig);

u8 LED_u8TurnOff(LED_t *LedConfig);

#endif /* LED_INTERFACE_H_ End */
