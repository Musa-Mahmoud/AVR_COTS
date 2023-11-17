/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  RTOS Stack          ************************/
/************************        SWC:    RTOS                ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"

#include "GIE_interface.h"
#include "TIMER0_interface.h"

#include "RTOS_interface.h"
#include "RTOS_config.h"
#include "RTOS_private.h"

Task_t SystemTasks[TASK_NUM] = {{NULL}};

void RTOS_voidStart(void)
{
    Timer0_u8OverflowSetCallback(&voidScheduler);
    GIE_voidEnable();
    Timer0_voidInit();
}

u8 RTOS_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*Copy_pvTaskFunc) (void), u16 Copy_u16FirstStart)
{
    u8 Local_u8ErrorState = OK;

    if (NULL != Copy_pvTaskFunc)
    {
        SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
        SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
        SystemTasks[Copy_u8Priority].FirstStart = Copy_u16FirstStart;
        SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
}

static void voidScheduler(void)
{
    u16 Local_u16TaskCounter;

    /* Loop on all tasks to check their periodicity */
    for (Local_u16TaskCounter = 0; Local_u16TaskCounter < TASK_NUM; Local_u16TaskCounter++)
    {
        if (NULL != SystemTasks[Local_u16TaskCounter].TaskFunc)
        {
            if (TASK_RESUMED == SystemTasks[Local_u16TaskCounter].State)
            {
                if (0 == SystemTasks[Local_u16TaskCounter].FirstStart)
                {
                    SystemTasks[Local_u16TaskCounter].TaskFunc();
                    SystemTasks[Local_u16TaskCounter].FirstStart = SystemTasks[Local_u16TaskCounter].Periodicity - 1U;
                }
                else
                {
                    SystemTasks[Local_u16TaskCounter].FirstStart--;
                }
            }
        }
    }
}
