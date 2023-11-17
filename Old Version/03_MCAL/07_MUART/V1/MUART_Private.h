
#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_


/*** Macros ***/

/** USART Control and Status Register A – UCSRA **/
#define RXC   7
#define TXC   6
#define UDRE  5
#define FE    4
#define DOR   3
#define PE    2
#define U2X   1
#define MPCM  0


/** USART Control and Status Register B – UCSRB **/
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2
#define RXB8  1
#define TXB8  0


/** USART Control and Status Register C – UCSRC **/
#define URSEL 7
#define UMSEL 6
#define UPM1  5
#define UPM0  4
#define USBS  3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0


/** USART Baud Rate Registers – UBRRH **/
#define URSEL 7
//Reserved Bit 6
//Reserved Bit 5
//Reserved Bit 4
// The reset 4-bits and the 8-bits of UBRRL is a 12-bit register which contains the USART baud rate

/** Magical Numbers **/
#define UBRR_VALUE 	   51
#define FLAG_SET   	   1
#define FLAG_NOT_SET   0
#define ENABLE		   1
#define DISABLE		   0



/*** USART Registers' Addresses ***/
#define UDR   *((volatile u8*) 0x2C)
#define UCSRA *((volatile u8*) 0x2B)
#define UCSRB *((volatile u8*) 0x2A)	
#define UCSRC *((volatile u8*) 0x40)
#define UBRRH *((volatile u8*) 0x40)
#define UBRRL *((volatile u8*) 0x29)

#endif