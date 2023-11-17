#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Interface.h"
#include "HLCD_CFG.h"
#include "HLCD_Private.h"
#include <avr/delay.h>

void HLCD_VoidSendChar(u8 Copy_U8Data)
{
	/* RS = 1 for send data*/
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RSPin, HIGH);
	
	/* RW = 0 to write in the LCD */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RWPin, LOW);
	
	/* Send the data */
	MDIO_VoidSetPortValue(HLCD_U8DataPort, Copy_U8Data);

	/* Enable sequence */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8ENPin, HIGH);
	_delay_us(10);
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8ENPin, LOW);
	/* Delay for the character to be drawn*/
	_delay_ms(2);
}



void HLCD_VoidSendCommand(u8 Copy_U8Command)
{
	/* RS = 0 for send command*/
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RSPin, LOW);
	
	/* RW = 0 to write in the LCD*/
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RWPin, LOW);
	
	/* Send the command*/
	MDIO_VoidSetPortValue(HLCD_U8DataPort, Copy_U8Command);

	/* Enable sequence */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8ENPin, HIGH);
	_delay_us(10);
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8ENPin, LOW);
	/* Delay for the command */
	_delay_ms(2);
}



void HLCD_VoidInit(void)
{
	/** Set Direction **/
	MDIO_VoidSetPortDirection(HLCD_U8DataPort, 0xff);
	
	MDIO_VoidSetPinDirection(HLCD_U8ControlPort, HLCD_U8RSPin, OUTPUT);
	MDIO_VoidSetPinDirection(HLCD_U8ControlPort, HLCD_U8RWPin, OUTPUT);
	MDIO_VoidSetPinDirection(HLCD_U8ControlPort, HLCD_U8ENPin, OUTPUT);
	
	
	/** Initialization Sequence **/
	/* Wainting for more than 30 ms until the voltage rises to 4.5 volt */
	_delay_ms(40);
	
	/* Function set command: 2 lines, 5*8 Font size */
	HLCD_VoidSendCommand(0b00111000);
	
	/* Wainting for more than 39 micro sec and we remove it becuase we already delayed at send command function */
	_delay_us(100);
	
	/* Display on/off control: display enable , with cursor and no blinking cursor */
	HLCD_VoidSendCommand(0b00001100);
	
	/* Wainting for more than 39 micro sec and we remove it becuase we already delayed at send command function */
	_delay_us(100);

	/* Display Clear */
	HLCD_VoidSendCommand(0b00000001);
	
	/* Wainting for more than 1.53 ms */
	_delay_ms(2);
}



u8 HLCD_U8GetAddressCounter(void)
{
	u8 LOC_U8AddressCounterValue;
	
	/* Set M.C. Direction to input to read from the LCD M.C. */
	MDIO_VoidSetPortDirection(HLCD_U8DataPort, INPUT);
	
	/* RS = 0 to select the LCD instruction register(IR) */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RSPin, LOW);
	
	/* RW = 1 to read: busy flag and the address counter */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8RWPin, HIGH);
	
	/* En = 1 to read: busy flag and the address counter */
	MDIO_VoidSetPinValue(HLCD_U8ControlPort, HLCD_U8ENPin, HIGH);
	
	/* Get Address Counter without the busy flag and assign it in variable */
	LOC_U8AddressCounterValue = (MDIO_U8GetPortValue(HLCD_U8DataPort) & 127);
	
	/* Reset M.C. Direction to output */
	MDIO_VoidSetPortDirection(HLCD_U8DataPort, 0xff);
	
	/* Return Address Counter value */
	return LOC_U8AddressCounterValue;
}



void HLCD_VoidSendString(const char Copy_U8Data[])
{
	u8 iterator = 0;
	
	while(Copy_U8Data[iterator] != NULLCHAR)
	{
		HLCD_VoidSendChar(Copy_U8Data[iterator]);
		iterator++;
	}
}



void HLCD_VoidSendNumber(u32 Copy_U32Number)
{
	u32 LOC_U32ReversedNumber = 1;
	
	if(0 == Copy_U32Number)
	{
		HLCD_VoidSendChar('0');
	}
	else
	{
		/* Loop to reverse the number */
		while(Copy_U32Number > 0)
		{
			LOC_U32ReversedNumber = (LOC_U32ReversedNumber * 10) + (Copy_U32Number % 10);
			Copy_U32Number /= 10;
		}
		
		/* Loop to print the number reversed for the second time */
		u32 LOC_U32Number;
		while(LOC_U32ReversedNumber > 1)
		{
			LOC_U32Number = LOC_U32ReversedNumber % 10;
			/* '0' -> is the ASCII of zero whitch = 48 in decimal */
			HLCD_VoidSendChar(LOC_U32Number + '0');
			LOC_U32ReversedNumber /= 10;
		}
	}
}



void HLCD_VoidSendCustomChar(u8 Copy_U8Array[])
{
	static u8 LOC_U8CGRAMCharCounter = 0;
	
	/* Save previous Address Counter temporarily */
	u8 LOC_U8PreviousDDRAMAddress = HLCD_U8GetAddressCounter();
	
	/* Set the proper CGRAM address */
	if(LOC_U8CGRAMCharCounter <= 8)
	{
		HLCD_VoidSendCommand( 0b01000000 + (8 * LOC_U8CGRAMCharCounter) );
		LOC_U8CGRAMCharCounter++;
	}
	
	/* Load the custom character into the CGRAM */
	for(u8 LOC_U8Iterator = 0; LOC_U8Iterator < 8; LOC_U8Iterator++)
	{
		HLCD_VoidSendChar(Copy_U8Array[LOC_U8Iterator]);
	}
	
	/* Set DDRAM address to it's previous value */
	HLCD_VoidSendCommand(LOC_U8PreviousDDRAMAddress + 128);
}




void HLCD_VoidSetPosition(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number)
{
	if(0 == Copy_U8Row_Number )
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 128);
	}
	else if(1 == Copy_U8Row_Number)
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 192);
	}
}




void HLCD_VoidSendCharAtPos(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number, u8 Copy_U8Char)
{
	if(0 == Copy_U8Row_Number )
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 128);
		HLCD_VoidSendChar(Copy_U8Char);
	}
	else if(1 == Copy_U8Row_Number)
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 192);
		HLCD_VoidSendChar(Copy_U8Char);
	}
}




void HLCD_VoidSendStringAtPos(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number, u8 Copy_U8String[])
{
	if(0 == Copy_U8Row_Number )
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 128);
		HLCD_VoidSendString(Copy_U8String);
	}
	else if(1 == Copy_U8Row_Number)
	{
		HLCD_VoidSendCommand(Copy_U8Column_Number + 192);
		HLCD_VoidSendString(Copy_U8String);
	}
}


