/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    DIO                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_ 

#if IS_PORT_DRIVER_USED == NOT_USED

#define DDRA    *((volatile u8*) 0x3a)
#define DDRB    *((volatile u8*) 0x37)
#define DDRC    *((volatile u8*) 0x34)
#define DDRD    *((volatile u8*) 0x31)

#endif /* IS_PORT_DRIVER_USED == NOT_USED End */

#define PORTA   *((volatile u8*) 0x3b)
#define PINA    *((volatile u8*) 0x39)

#define PORTB   *((volatile u8*) 0x38)
#define PINB    *((volatile u8*) 0x36)

#define PORTC   *((volatile u8*) 0x35)
#define PINC    *((volatile u8*) 0x33)

#define PORTD   *((volatile u8*) 0x32)
#define PIND    *((volatile u8*) 0x30)

#endif /* DIO_REGISTER_H_ End */
