
#ifndef	_HLED_INTERFACE_H_
#define	_HLED_INTERFACE_H_


/*** Prototypes ***/

void HLED_VoidOnLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber);

void HLED_VoidOffLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber);

void HLED_VoidTglLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber);

void HLED_VoidBlinkLEDms(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber, u16 Copy_U8TglTimeMs);

void HLED_VoidBlinkLEDus(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber, u16 Copy_U8TglTimeUs);




#endif