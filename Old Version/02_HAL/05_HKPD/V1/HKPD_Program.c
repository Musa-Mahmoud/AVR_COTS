#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Interface.h"
#include "HKPD_Private.h"
#include "HKPD_CFG.h"
#include <avr/delay.h>


void HKPD_VoidInit(void)
{
	//MDIO_VoidSetPortDirection(HKPD_PORT, 0xf0);
	//MDIO_VoidSetPortValue(HKPD_PORT, 0xff);
	
	/* Activatting Rows Pullup Resistor */
	MDIO_VoidActivatePinInternalPullupResistor(HKPD_PORT, HKPD_ROW0_PIN);
	MDIO_VoidActivatePinInternalPullupResistor(HKPD_PORT, HKPD_ROW1_PIN);
	MDIO_VoidActivatePinInternalPullupResistor(HKPD_PORT, HKPD_ROW2_PIN);
	MDIO_VoidActivatePinInternalPullupResistor(HKPD_PORT, HKPD_ROW3_PIN);
	
	/* Setting Columns Direction */
	MDIO_VoidSetPinDirection(HKPD_PORT, HKPD_COLUMN0_PIN, OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT, HKPD_COLUMN1_PIN, OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT, HKPD_COLUMN2_PIN, OUTPUT);
	MDIO_VoidSetPinDirection(HKPD_PORT, HKPD_COLUMN3_PIN, OUTPUT);
	/* Setting Columns Values */
	MDIO_VoidSetPinValue(HKPD_PORT, HKPD_COLUMN0_PIN, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT, HKPD_COLUMN1_PIN, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT, HKPD_COLUMN2_PIN, HIGH);
	MDIO_VoidSetPinValue(HKPD_PORT, HKPD_COLUMN3_PIN, HIGH);
}

u8 HKPD_U8GetPressedKey(void)
{
	u8 LOC_U8RowPinValue;
	u8 LOC_U8PressedKey = HKPD_NOT_PRESSED_VALUE;
	static u8 LOC_U8RowsConfgArray [] = {HKPD_ROW0_PIN, HKPD_ROW1_PIN, HKPD_ROW2_PIN, HKPD_ROW3_PIN};
	static u8 LOC_U8ColumnsConfgArray [] ={HKPD_COLUMN0_PIN, HKPD_COLUMN1_PIN, HKPD_COLUMN2_PIN, HKPD_COLUMN3_PIN} ;
	static u8 LOC_U8HKPDLayout[][4] = KPD_LAYOUT;
	
	
	for(u8 LOC_U8ColumnNumber = 0; LOC_U8ColumnNumber < 4; LOC_U8ColumnNumber++)
	{
		MDIO_VoidSetPinValue(HKPD_PORT, LOC_U8ColumnsConfgArray[LOC_U8ColumnNumber], LOW);
		
		for(u8 LOC_U8RowNumber = 0; LOC_U8RowNumber < 4; LOC_U8RowNumber++)
		{
			LOC_U8RowPinValue = MDIO_U8GetPinValue(HKPD_PORT, LOC_U8RowsConfgArray[LOC_U8RowNumber]);
			
			if(KPD_PRESSED == LOC_U8RowPinValue)
			{
				LOC_U8PressedKey = LOC_U8HKPDLayout[LOC_U8RowNumber][LOC_U8ColumnNumber];
			}
			
			/* Looping until the user removes his hand from the keypad */
			while(LOW == MDIO_U8GetPinValue(HKPD_PORT, LOC_U8RowsConfgArray[LOC_U8RowNumber]))
			{
				
			}
			
			/* Delay for the switch bouncing */
			_delay_us(10);

		}
		
		MDIO_VoidSetPinValue(HKPD_PORT, LOC_U8ColumnsConfgArray[LOC_U8ColumnNumber], HIGH);
	}
	return LOC_U8PressedKey;
	
}