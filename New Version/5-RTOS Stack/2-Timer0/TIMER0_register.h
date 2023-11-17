/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  RTOS Stack          ************************/
/************************        SWC:    TIMER0              ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef TIMER0_REGISTER_H_
#define TIMER0_REGISTER_H_ 

#define TCCR0           *((volatile u8*) 0x53)
#define TCCR0_FOC0      7U
#define TCCR0_WGM00     6U
#define TCCR0_COM01     5U
#define TCCR0_COM00     4U
#define TCCR0_WGM01     3U
#define TCCR0_CS02      2U
#define TCCR0_CS01      1U
#define TCCR0_CS00      0U

#define TCNT0           *((volatile u8*) 0x52)

#define OCR0            *((volatile u8*) 0x5C)

#define TIMSK           *((volatile u8*) 0x59)
#define TIMSK_OCIE2     7U
#define TIMSK_TOIE2     6U
#define TIMSK_TICIE1    5U
#define TIMSK_OCIE1A    4U
#define TIMSK_OCIE1B    3U
#define TIMSK_TOIE1     2U
#define TIMSK_OCIE0     1U
#define TIMSK_TOIE0     0U

#define TIFR            *((volatile u8*) 0x58)
#define TIFR_OCF2       7U
#define TIFR_TOV2       6U
#define TIFR_ICF1       5U
#define TIFR_OCF1A      4U
#define TIFR_OCF1B      3U
#define TIFR_TOV1       2U
#define TIFR_OCF0       1U
#define TIFR_TOV0       0U

#define SFIOR           *((volatile u8*) 0x50)

#endif /* TIMER0_REGISTER_H_ End */
