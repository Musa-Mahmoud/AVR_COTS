#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MUART_Private.h"
#include "MUART_CFG.h"


void MUART_VoidInit(void)
{
	
/******************************************************************************
/* SWC: MUART_Program  ********************************************************
 * Auther: Musa Mahmoud	 ******************************************************
 * Version: 1.0  **************************************************************
 * Date: 13/11/2021	 **********************************************************
 * DISC: This macro choose the INT enable of the receive buffer  **************
 * ENABLE  = 1  
 * DISABLE = 0  
 ******************************************************************************/
	#if RX_INT_ENABLE == ENABLE
		SET_BIT(UCSRB, RXCIE);
	#elif RX_INT_ENABLE == DISABLE
		CLR_BIT(UCSRB, RXCIE);
	#else
		#error ("RX_INT_ENABLE invalid value")
	#endif
	
/******************************************************************************
/* SWC: MUART_Program  ********************************************************
 * Auther: Musa Mahmoud	 ******************************************************
 * Version: 1.0  **************************************************************
 * Date: 13/11/2021	 **********************************************************
 * DISC: This macro choose the INT enable of the receive buffer  **************
 * ENABLE  = 1  
 * DISABLE = 0  
 ******************************************************************************/
	#if TX_INT_ENABLE == ENABLE
		SET_BIT(UCSRB, TXCIE);
	#elif TX_INT_ENABLE == DISABLE
		CLR_BIT(UCSRB, TXCIE);
	#else
		#error ("TX_INT_ENABLE invalid value")
	#endif
	
/******************************************************************************
/* SWC: MUART_Program  ********************************************************
 * Auther: Musa Mahmoud	 ******************************************************
 * Version: 1.0  **************************************************************
 * Date: 13/11/2021	 **********************************************************
 * DISC: This macro choose the INT enable of the receive buffer  **************
 * ENABLE  = 1  
 * DISABLE = 0  
 ******************************************************************************/
	#if EMP_INT_ENABLE == ENABLE
		SET_BIT(UCSRB, UDRIE);
	#elif EMP_INT_ENABLE == DISABLE
		CLR_BIT(UCSRB, UDRIE);
	#else
		#error ("EMP_INT_ENABLE invalid value")
	#endif
	
	
	/* Doing all the operation of UCSRC on this varaible then assign its value at one time to the UCSRC */
	u8 LOC_U8Help = 0b10000000;
	
	/* Transmission Speed: Normal speed */
	SET_BIT(UCSRA, U2X);
	
	/* Receiver State: Disable */
	CLR_BIT(UCSRB, RXEN);
	
	/* Transmitter State: Enable */
	SET_BIT(UCSRB, TXEN);
	
	/* Character Size: 8-bit */
	CLR_BIT(UCSRB, UCSZ2);
	SET_BIT(LOC_U8Help, UCSZ1);
	SET_BIT(LOC_U8Help, UCSZ0);
	
	/* Mode Select: Asynchronous Operation */
	SET_BIT(LOC_U8Help, UMSEL);
	
	/* Parity Mode: Disabled */
	CLR_BIT(LOC_U8Help, UPM1);
	CLR_BIT(LOC_U8Help, UPM0);
	
	/* Stop Bit Select: 1-bit */
	CLR_BIT(LOC_U8Help, USBS);
	
	/* Assigning the help varaible to the UCSRC */
	UCSRC = LOC_U8Help;
	
	/* USART Baud Rate Register: 9600 bps */
	UBRRL = UBRR_VALUE;
}


void MUART_VoidSend(u8 Copy_U8Data)
{
	while(FLAG_NOT_SET == GET_BIT(UCSRA, UDRE));
	
	UDR = Copy_U8Data;
}


u8 MUART_U8Receive(void)
{
	while(FLAG_NOT_SET == GET_BIT(UCSRA, RXC));
	
	return UDR;
}