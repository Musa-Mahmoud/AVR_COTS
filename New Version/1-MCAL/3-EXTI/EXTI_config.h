/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    EXTI                ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* Options:
            1- EXTI_u8LOW_LEVEL
            2- EXTI_u8ON_CHANGE
            3- EXTI_u8FALLING_EDGE
            4- EXTI_u8RISING_EDGE
                                */
#define INT0_SENSE          EXTI_u8FALLING_EDGE
/* Options:
            1- EXTI_u8LOW_LEVEL
            2- EXTI_u8ON_CHANGE
            3- EXTI_u8FALLING_EDGE
            4- EXTI_u8RISING_EDGE
                                */
#define INT1_SENSE          EXTI_u8FALLING_EDGE
/* Options:
            1- EXTI_u8FALLING_EDGE
            2- EXTI_u8RISING_EDGE
                                */
#define INT2_SENSE          EXTI_u8FALLING_EDGE

/* Options:
            1- ENABLED
            2- DISABLED
                                */
#define INT0_INITIAL_STATE  ENABLED
/* Options:
            1- ENABLED
            2- DISABLED
                                */
#define INT1_INITIAL_STATE  ENABLED
/* Options:
            1- ENABLED
            2- DISABLED
                                */
#define INT2_INITIAL_STATE  ENABLED

#endif /* EXTI_CONFIG_H_ END */
