
#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_


/*** Prototyps ***/

void HLCD_VoidSendChar(u8 Copy_U8Data);

void HLCD_VoidSendCommand(u8 Copy_U8Command);

void HLCD_VoidInit(void);

u8 HLCD_U8GetAddressCounter(void);

void HLCD_VoidSendString(const char Copy_U8Data[]);

void HLCD_VoidSendNumber(u32 Copy_U8Number);

void HLCD_VoidSendCustomChar(u8 Copy_U8Array[]);

void HLCD_VoidSetPosition(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number);

void HLCD_VoidSendCharAtPos(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number, u8 Copy_U8Char);

void HLCD_VoidSendStringAtPos(u8 Copy_U8Row_Number, u8 Copy_U8Column_Number, u8 Copy_U8String[]);


#endif