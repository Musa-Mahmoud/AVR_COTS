
#ifndef _MTIMR_PRIVATE_H_
#define _MTIMR_PRIVATE_H_


/*** Macros ***/

/** Timer 0 **/
/* TCCR0 Macros */
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

/* TCNT0 Macros */
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0


/** Timer 1 **/
/* TCCR1A Macros */
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

/* TCCR1B Macros */
#define ICNC1  7
#define ICES1  6
//Reserved Bit 5
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0


/*** Timer Registers' Addresses ***/
#define TIMSK *((volatile u8*) 0x59)
#define TIFR  *((volatile u8*) 0x58)

/** Timer/Counter Interrupt Mask Register – TIMSK **/
#define OCIE2  7
#define TOIE2  6
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2
#define OCIE0  1
#define TOIE0  0


/** Timer0 and Timer1 Prescalers **/
#define SFIOR *((volatile u8*) 0x50)


/** Timer0 Registers' Addresses **/
#define TCCR0 *((volatile u8*) 0x53)
#define TCNT0 *((volatile u8*) 0x52)
#define OCR0  *((volatile u8*) 0x5C)


/** Timer1 Registers' Addresses **/
#define TCCR1A *((volatile u8*)  0x4F)
#define TCCR1B *((volatile u8*)  0x4E)
#define TCNT1H *((volatile u8*)  0x4D)
#define TCNT1L *((volatile u8*)  0x4C)
#define TCNT1  *((volatile u16*) 0x4C)
#define OCR1AH *((volatile u8*)  0x4B)
#define OCR1AL *((volatile u8*)  0x4A)
#define OCR1A  *((volatile u16*) 0x4A)
#define OCR1BH *((volatile u8*)  0x49)
#define OCR1BL *((volatile u8*)  0x48)
#define OCR1B  *((volatile u16*) 0x48)
#define ICR1H  *((volatile u8*)  0x47)
#define ICR1L  *((volatile u8*)  0x46)
#define ICR1   *((volatile u16*) 0x46)


/*** Prototypes ***/

/** Interrupt Vectors for Timer0 with overflow **/
void __vector_11(void) __attribute__((signal));

#endif