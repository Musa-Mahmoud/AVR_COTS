/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    CLCD                ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/


#include "STD_TYPES.h"
#include <util/delay.h> 

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
    /* Set RS pin to low for command */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
    /* Set RW pin to low for write */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
    /* Set command(higher 4 bits in case of 4-bit mode) to data pins */
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
    /* Send enable pulse */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
    _delay_us(10);
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

#if CLCD_MODE == FOUR_BIT_MODE
	/* Set command(lower 4 bits) to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT, (Copy_u8Command << LOWER_BITS_SHIFT));
	/* Send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
#endif
	/* Wait for the command */
	_delay_ms(2);
}


void CLCD_voidSendData(u8 Copy_u8Data)
{
    /* Set RS pin to high for data */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
    /* Set RW pin to low for write */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
    /* Set data(higher 4 bits in case of 4-bit mode) to data pins */
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
    /* Send enable pulse */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
    _delay_us(10);
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);

#if CLCD_MODE == FOUR_BIT_MODE
	/* Set data(lower 4 bits) to data pins */
	DIO_u8SetPortValue(CLCD_DATA_PORT, (Copy_u8Data << LOWER_BITS_SHIFT));
	/* Send enable pulse */
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_us(10);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
#endif
	/* Wait for the data */
	_delay_ms(2);
}


void CLCD_voidInit(void)
{
    /* Wait for more than 30 ms */
    _delay_ms(40);
#if CLCD_MODE == EIGHT_BIT_MODE
    /* Function set command: 2 lines, 5x8 font size */
    CLCD_voidSendCommand(0b00111000);
#elif CLCD_MODE == FOUR_BIT_MODE
    /* Function set command: 2 lines, 5x8 font size */
    CLCD_voidSendCommand(0b00000010);
    CLCD_voidSendCommand(0b00101000);
#endif
    /* Display on/off control: display enable, disable cursor, no blink cursor */
    CLCD_voidSendCommand(0b00001100);
    /* Clear display */
    CLCD_voidSendCommand(0b00000001);
}


void CLCD_voidSendString(const char *Copy_pcString)
{
    while(NULL_CHARACTER != *Copy_pcString)
    {
        /* Send the current char then increment the pointer to the next char */
        CLCD_voidSendData(*Copy_pcString++);
    }
}


void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8Address;

    if(0 == Copy_u8XPos)
    {
        /* Location is at first line */
        Local_u8Address = Copy_u8YPos;
    }
    else if(1 == Copy_u8XPos)
    {
        /* Location is at second line */
        Local_u8Address = Copy_u8YPos + 0x40; 
    }

    /* Set bit number 7 for set DDRAM Address command then send the command */
    CLCD_voidSendCommand(Local_u8Address + 128);
}


void CLCD_voidWriteSpecialCharacter(u8 *Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
    u8 Local_u8CGRAMAddress = 0;

    /* Calculate the CGRAM address whose each block is 8-bytes */
    Local_u8CGRAMAddress =  Copy_u8PatternNumber * 8;

    /* Send CGRAM address command to LCD, with setting bit 6, clearing bit 7 */
    CLCD_voidSendCommand(Local_u8CGRAMAddress + 64);

    /* Write the pattern into CGRAM */
    for (u8 Local_u8Iterator = 0; Local_u8Iterator < 8; Local_u8Iterator++)
    {
        CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
    }
    
    /* Go back to DDRAM to display the pattern */
    CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);

    /* Display the pattern written in the CGRAM */
    CLCD_voidSendData(Copy_u8PatternNumber);
}


void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
    /* Initialized with 1 to append 1 to the end of the number after reversing it to overcome the leading zeros problem */
    u32 Local_u32ReversedNumber = 1;

    if(0 == Copy_u32Number)
    {
        CLCD_voidSendData('0');
    }
    else
    {
        /* Reverse the number */
        while(Copy_u32Number != 0)
        {
            Local_u32ReversedNumber = (Local_u32ReversedNumber * 10) + (Copy_u32Number % 10);
            Copy_u32Number /= 10;
        }

        /* Sending the number to the LCD after reversing it again without the first digit as we append it at the beginning */
        while(Local_u32ReversedNumber != 1)
        {
            /* Sending the ASCII of the number's digits to the LCD */
            CLCD_voidSendData(Local_u32ReversedNumber % 10 + '0');
            Local_u32ReversedNumber /= 10;
        }
    }
}


void CLCD_voidClearDisplay(void)
{
    CLCD_voidSendCommand(0b00000001);
}
