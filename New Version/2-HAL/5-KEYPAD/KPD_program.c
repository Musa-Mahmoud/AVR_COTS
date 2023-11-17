/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    KEYPAD              ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_u8GetPressedKey(void)
{
    u8 Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;
    u8 Local_u8PressesKey = KPD_NO_PRESSES_KEY;
    static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;
    static u8 Local_u8KPDColumnArr[COLUMN_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};
    static u8 Local_u8KPDRowArr[ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    for (Local_u8ColumnIdx = 0; Local_u8ColumnIdx < COLUMN_NUM; Local_u8ColumnIdx++)
    {
        /* Activate current column */
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8PIN_LOW);

        for (Local_u8RowIdx = 0; Local_u8RowIdx < ROW_NUM; Local_u8RowIdx++)
        {
            /* Read the current row */
            DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);

            /* Check if switch is presses */
            if(DIO_u8PIN_LOW == Local_u8PinState)
            {
                Local_u8PressesKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

                /* Polling(Busy Waiting) until the key is released */
                while(DIO_u8PIN_LOW == Local_u8PinState)
                {
                    DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);
                }
                return Local_u8PressesKey;
            }
        }
        /* Deactivate current column */
        DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
    }

    return Local_u8PressesKey;
}
