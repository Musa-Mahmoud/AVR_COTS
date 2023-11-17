/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    EXTI                ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8LOW_LEVEL            1
#define EXTI_u8ON_CHANGE            2
#define EXTI_u8FALLING_EDGE         3
#define EXTI_u8RISING_EDGE          4

#define EXTI_u8INT0                 0
#define EXTI_u8INT1                 1
#define EXTI_u8INT2                 2

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

/* Description: A function to set the required sense control of INT0 using post-build configuration 
 * Inputs: Copy_u8Sense, options are: 1- EXTI_u8LOW_LEVEL
 *                                    2- EXTI_u8ON_CHANGE
 *                                    3- EXTI_u8FALLING_EDGE
 *                                    4- EXTI_u8RISING_EDGE
 * Outputs: Error status with type u8
 */
u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense);

/* Description: A function to set the required sense control of INT1 using post-build configuration 
 * Inputs: Copy_u8Sense, options are: 1- EXTI_u8LOW_LEVEL
 *                                    2- EXTI_u8ON_CHANGE
 *                                    3- EXTI_u8FALLING_EDGE
 *                                    4- EXTI_u8RISING_EDGE
 * Outputs: Error status with type u8
 */
u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense);

/* Description: A function to set the required sense control of INT1 using post-build configuration 
 * Inputs: Copy_u8Sense, options are: 1- EXTI_u8FALLING_EDGE
 *                                    2- EXTI_u8RISING_EDGE
 * Outputs: Error status with type u8
 */
u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber);

u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));


#endif /* EXTI_INTERFACE_H_ END */
