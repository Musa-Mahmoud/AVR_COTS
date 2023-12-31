/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SSD                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_


/* Seven Segments Common Anode Numbers 1:9 Representation */
#define ZERO    0b11000000
#define ONE     0b11111001
#define TWO     0b10100100
#define THREE   0b10110000
#define FOUR    0b10011001
#define FIVE    0b10010010
#define SIX     0b10000010
#define SEVEN   0b11111000
#define EIGHT   0b10000000
#define NINE    0b10010000

/* Seven Segments Common Anode Array of the Numbers */
static u8 SSD_Numbers[10] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

#endif /* SSD_PRIVATE_H_ End */
