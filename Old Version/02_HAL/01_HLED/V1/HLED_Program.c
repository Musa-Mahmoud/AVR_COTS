#include "STD_TYPES.h"
#include "MDIO_Interface.h"
#include "HLED_CFG.h"
#include "avr/delay.h"


void HLED_VoidOnLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber)
{
	#if LED_CONNECTION_TYPE == POSITIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
	#elif LED_CONNECTION_TYPE == NEGATIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
	#endif
}


void HLED_VoidOffLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber)
{
	#if LED_CONNECTION_TYPE == POSITIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
	#elif LED_CONNECTION_TYPE == NEGATIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
	#endif
}


void HLED_VoidTglLED(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber)
{
	MDIO_VoidTogglePinValue(Copy_U8PortNumber, Copy_U8PinNumber);
}


void HLED_VoidBlinkLEDms(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber, u16 Copy_U8TglTimeMs)
{
	#if LED_CONNECTION_TYPE == POSITIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
		_delay_ms(Copy_U8TglTimeMs / 2);
	
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
		_delay_ms(Copy_U8TglTimeMs / 2);
		
	#elif LED_CONNECTION_TYPE == NEGATIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
		_delay_ms(Copy_U8TglTimeMs / 2);
	
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
		_delay_ms(Copy_U8TglTimeMs / 2);
	#endif
}


void HLED_VoidBlinkLEDus(u8 Copy_U8PortNumber, u8 Copy_U8PinNumber, u16 Copy_U8TglTimeUs)
{
	#if LED_CONNECTION_TYPE == POSITIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
		_delay_us(Copy_U8TglTimeMs / 2);
		
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
		_delay_us(Copy_U8TglTimeMs / 2);
		
	#elif LED_CONNECTION_TYPE == NEGATIVE_LOGIC
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, LOW);
		_delay_us(Copy_U8TglTimeMs / 2);
		
		MDIO_VoidSetPinValue(Copy_U8PortNumber, Copy_U8PinNumber, HIGH);
		_delay_us(Copy_U8TglTimeMs / 2);
	#endif
		
}
