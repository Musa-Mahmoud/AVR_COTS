
#ifndef _MSPI_PRIVATE_H_
#define _MSPI_PRIVATE_H_

/*** Macros ***/

/** SPI Control Register – SPCR **/
#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

/** SPI Status Register – SPSR **/
#define SPIF  7
#define WCOL  6
// Reserved   5
// Reserved   4
// Reserved   3
// Reserved   2
// Reserved   1
#define SPI2X 0


/*** SPI Registers' Addresses ***/
#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)

#endif