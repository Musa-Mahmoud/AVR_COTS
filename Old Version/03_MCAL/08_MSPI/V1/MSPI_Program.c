#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MSPI_Private.h"
#include "MDIO_Interface.h"


/** Slave Functions **/
void MSPI_VoidSlaveInit(void)
{
	u8 LOC_U8Help = 0;
	/* SPI State: Enable */
	SET_BIT(LOC_U8Help, SPE);
	/* Data Order: MSB of the data word is transmitted first */
	CLR_BIT(LOC_U8Help, DORD);
	/* Master/Slave Select: Slave */
	CLR_BIT(LOC_U8Help, MSTR);
	/* Clock Polarity: Leading Edge -> Rising, Trailing Edge -> Falling */
	CLR_BIT(LOC_U8Help, CPOL);
	/* Clock Phase: Leading Edge -> Setup, Trailing Edge -> Sample */
	SET_BIT(LOC_U8Help, CPHA);

	/* Assign the help variable to the SPCR */
	SPCR = LOC_U8Help;
	
	/** Setting the dirctions **/
	/* MOSI */
	MDIO_VoidSetPinDirection(PORTB, PIN5, INPUT);
	/* MISO */
	MDIO_VoidSetPinDirection(PORTB, PIN6, OUTPUT);
	/* Slave Selection*/
	MDIO_VoidSetPinDirection(PORTB, PIN4, LOW);
}

u8 MSPI_U8Receive(void)
{
	LOC_U8RecValue = SPDR;
	while(0 == GET_BIT(SPSR,SPIF));
	return LOC_U8RecValue;
}


/** Master Functions **/
void MSPI_VoidMasterInit(void)
{
	
}

void MSPI_VoidSend(u8 Copy_U8Data)
{
	
}
