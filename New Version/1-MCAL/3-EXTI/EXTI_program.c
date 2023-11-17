/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    EXTI                ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"


/* Static pointer to function to hold INT0 ISR address */
static void (*Int0Func)(void) = NULL;

/* Static pointer to function to hold INT1 ISR address */
static void (*Int1Func)(void) = NULL;

/* Static pointer to function to hold INT2 ISR address */
static void (*Int2Func)(void) = NULL;


void EXTI_voidInt0Init(void)
{
    /* Check sense control */
#if INT0_SENSE == EXTI_u8LOW_LEVEL
    CLR_BIT(MCUCR, MCUCR_ISC01);
    CLR_BIT(MCUCR, MCUCR_ISC00);
#elif INT0_SENSE == EXTI_u8ON_CHANGE
    CLR_BIT(MCUCR, MCUCR_ISC01);
    SET_BIT(MCUCR, MCUCR_ISC00);
#elif INT0_SENSE == EXTI_u8FALLING_EDGE
    SET_BIT(MCUCR, MCUCR_ISC01);
    CLR_BIT(MCUCR, MCUCR_ISC00);
#elif INT0_SENSE == EXTI_u8RISING_EDGE
    SET_BIT(MCUCR, MCUCR_ISC01);
    SET_BIT(MCUCR, MCUCR_ISC00);
#else
#error "Wrong INT0_SENSE configuration option"
#endif

    /* Check peripheral interrupt enable initial state */
#if INT0_INITIAL_STATE == ENABLED
    SET_BIT(GICR, GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
    CLR_BIT(GICR, GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE configuration option"
#endif
}


u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8Sense)
    {
    case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC01); CLR_BIT(MCUCR, MCUCR_ISC00); break;
    case EXTI_u8ON_CHANGE: CLR_BIT(MCUCR, MCUCR_ISC01); SET_BIT(MCUCR, MCUCR_ISC00); break;
    case EXTI_u8FALLING_EDGE: SET_BIT(MCUCR, MCUCR_ISC01); CLR_BIT(MCUCR, MCUCR_ISC00); break;
    case EXTI_u8RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC01); SET_BIT(MCUCR, MCUCR_ISC00); break;
    default: Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}


void EXTI_voidInt1Init(void)
{
    /* Check sense control */
#if INT1_SENSE == EXTI_u8LOW_LEVEL
    CLR_BIT(MCUCR, MCUCR_ISC11);
    CLR_BIT(MCUCR, MCUCR_ISC10);
#elif INT1_SENSE == EXTI_u8ON_CHANGE
    CLR_BIT(MCUCR, MCUCR_ISC11);
    SET_BIT(MCUCR, MCUCR_ISC10);
#elif INT1_SENSE == EXTI_u8FALLING_EDGE
    SET_BIT(MCUCR, MCUCR_ISC11);
    CLR_BIT(MCUCR, MCUCR_ISC10);
#elif INT1_SENSE == EXTI_u8RISING_EDGE
    SET_BIT(MCUCR, MCUCR_ISC11);
    SET_BIT(MCUCR, MCUCR_ISC10);
#else
#error "Wrong INT1_SENSE configuration option"
#endif

    /* Check peripheral interrupt enable initial state */
#if INT1_INITIAL_STATE == ENABLED
    SET_BIT(GICR, GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
    CLR_BIT(GICR, GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE configuration option"
#endif
}


u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8Sense)
    {
    case EXTI_u8LOW_LEVEL: CLR_BIT(MCUCR, MCUCR_ISC11); CLR_BIT(MCUCR, MCUCR_ISC10); break;
    case EXTI_u8ON_CHANGE: CLR_BIT(MCUCR, MCUCR_ISC11); SET_BIT(MCUCR, MCUCR_ISC10); break;
    case EXTI_u8FALLING_EDGE: SET_BIT(MCUCR, MCUCR_ISC11); CLR_BIT(MCUCR, MCUCR_ISC10); break;
    case EXTI_u8RISING_EDGE: SET_BIT(MCUCR, MCUCR_ISC11); SET_BIT(MCUCR, MCUCR_ISC10); break;
    default: Local_u8ErrorState = NOK;
    }
    
    return Local_u8ErrorState;
}


void EXTI_voidInt2Init(void)
{
    /* Check sense control */
#if INT2_SENSE == EXTI_u8FALLING_EDGE
    CLR_BIT(MCUCR, MCUCSR_ISC2);
#elif INT2_SENSE == EXTI_u8RISING_EDGE
    SET_BIT(MCUCR, MCUCSR_ISC2);
#else
#error "Wrong INT2_SENSE configuration option"
#endif

    /* Check peripheral interrupt enable initial state */
#if INT2_INITIAL_STATE == ENABLED
    SET_BIT(GICR, GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
    CLR_BIT(GICR, GICR_INT2);
#else
#error "Wrong INT2_INITIAL_STATE configuration option"
#endif
}


u8 EXTI_u8Int2SetSenseControl(u8 Copy_u8Sense)
{
    u8 Local_u8ErrorState = OK;

    /* Disable INT2 interrupt to avoid interrupt when changing ISC2 value */
    EXTI_u8IntDisable(EXTI_u8INT2);

    switch (Copy_u8Sense)
    {
    case EXTI_u8FALLING_EDGE: CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
    case EXTI_u8RISING_EDGE: SET_BIT(MCUCSR, MCUCSR_ISC2); break;
    default: Local_u8ErrorState = NOK;
    }
    
    /* Clear the INT2 flag by writing a logical one to its bit */
    SET_BIT(GIFR, GIFR_INTF2);

    /* Enable INT2 interrupt again */
    EXTI_u8IntEnable(EXTI_u8INT2);

    return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8IntNumber)
    {
    case EXTI_u8INT0: SET_BIT(GICR, GICR_INT0); break;
    case EXTI_u8INT1: SET_BIT(GICR, GICR_INT1); break;
    case EXTI_u8INT2: SET_BIT(GICR, GICR_INT2); break;
    default: Local_u8ErrorState = NOK;
    }
    
    return Local_u8ErrorState;
}


u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8IntNumber)
    {
    case EXTI_u8INT0: CLR_BIT(GICR, GICR_INT0); break;
    case EXTI_u8INT1: CLR_BIT(GICR, GICR_INT1); break;
    case EXTI_u8INT2: CLR_BIT(GICR, GICR_INT2); break;
    default: Local_u8ErrorState = NOK;
    }
    
    return Local_u8ErrorState;
}


u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
    u8 Local_u8ErrorState = OK;

    if(NULL != Copy_pvInt0Func)
    {
        Int0Func = Copy_pvInt0Func;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }

    return Local_u8ErrorState;
}


u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
    u8 Local_u8ErrorState = OK;

    if(NULL != Copy_pvInt1Func)
    {
        Int1Func = Copy_pvInt1Func;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }

    return Local_u8ErrorState;
}


u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
    u8 Local_u8ErrorState = OK;

    if(NULL != Copy_pvInt2Func)
    {
        Int2Func = Copy_pvInt2Func;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }

    return Local_u8ErrorState;
}


/* ISR of INT0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(NULL != Int0Func)
    {
        Int0Func();
    }
}


/* ISR of INT1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if(NULL != Int1Func)
    {
        Int1Func();
    }
}


/* ISR of INT2 */
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if(NULL != Int2Func)
    {
        Int2Func();
    }
}
