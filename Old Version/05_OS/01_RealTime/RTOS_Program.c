#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RTOS_CFG.h"
#include "RTOS_Private.h"

u16 GLB_U16TicksNumber = 0;

Task-t SystemTasks[NUMBER_OF_TASKS];

void RTOS_VoidCreatTask(u8 *Copy_U8Ptf, u16 Copy_U16Priority, u16 Copy_U16Priodicity)
{
	SystemTasks[Copy_U16Priority].priodicity = Copy_U16Priodicity;
	
	SystemTasks[Copy_U16Priority].ptf = Copy_U8Ptf;
}

void RTOS_VoidSchadular(void)
{
	u16 LOC_U16Itr;
	
	GLB_U16TicksNumber ++;
	
	
	for(LOC_U16Itr = 0, LOC_U16Itr < NUMBER_OF_TASKS, LOC_U16Itr++)
	{
		if(0 == GLB_U16TicksNumber % SystemTasks[LOC_U16Itr].priodicity)
		{
			SystemTasks[LOC_U16Itr].ptf();
		}
	}
}