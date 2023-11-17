/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    TWI                 ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_register.h"

/* Pass 0 in the slave address argument if master will not be addressed */
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
    /* Set clock frequency to 400 kpbs */
    /* Set TWBR to 2 */
    TWBR = 2;

    /* Clear the 2 bits of TWPS */
    CLR_BIT(TWSR, TWSR_TWPS1);
    CLR_BIT(TWSR, TWSR_TWPS0);

    /* Enable master generating acknowledge bit after receiving the data */
    SET_BIT(TWCR, TWCR_TWEA);

    /* Initialize the node address */
    if (0 != Copy_u8SlaveAddress)
    {
        TWAR = Copy_u8SlaveAddress << 1;
    }

    /* Enable TWI */
    SET_BIT(TWCR, TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
    /* Initialize the node address */
    TWAR = Copy_u8SlaveAddress << 1;
    /* Enable slave generating acknowledge bit after receiving its address with request or receiving the data */
    SET_BIT(TWCR, TWCR_TWEA);
    /* Enable TWI */
    SET_BIT(TWCR, TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition(void)
{
    TWI_ErrStatus Local_ErrStatus = NoError;
    
    /* Send start condition on the bus */
    SET_BIT(TWCR, TWCR_TWSTA);

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (START_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = StartConditionErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendRepeatedStart(void)
{
    TWI_ErrStatus Local_ErrStatus = NoError;
    
    /* Send start condition on the bus */
    SET_BIT(TWCR, TWCR_TWSTA);

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (REP_START_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = RepeatedStartErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Clear the start condition bit */
    CLR_BIT(TWCR, TWCR_TWSTA);

    /* Set the slave address in the 7 MSB of the data register with 0 in LSB for write request */
    TWDR = Copy_u8SlaveAddress & 0xfe;

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (SLAVE_ADDR_AND_WR_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = SlaveAddressWithWriteErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Clear the start condition bit */
    CLR_BIT(TWCR, TWCR_TWSTA);

    /* Set the slave address in the 7 MSB of the data register with 1 in LSB for read request */
    TWDR = Copy_u8SlaveAddress | 0x01;

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (SLAVE_ADDR_AND_RD_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = SlaveAddressWithReadErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Write the data byte */
    TWDR = Copy_u8DataByte;

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (MASTER_WR_BYTE_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = MasterWriteByteErr;
    }

    return Local_ErrStatus;
}

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
    TWI_ErrStatus Local_ErrStatus = NoError;

    /* Clear the interrupt flag to let the slave start sending data */
    SET_BIT(TWCR, TWCR_TWINT);

    /* Wait until the interrupt flag is raised again and the previous operation is complete */
    while (0 == GET_BIT(TWCR, TWCR_TWINT));

    /* Check the status of the previous operation to ensure that it's the one we done */
    if (MASTER_RD_BYTE_WITH_ACK != (TWSR & 0xf8))
    {
        Local_ErrStatus = MasterReadByteErr;
    }
    else
    {
        /* Read the received data */
        *Copy_pu8DataByte = TWDR;
    }

    return Local_ErrStatus;
}

void TWI_SendStopCondition(void)
{
    /* Generate stop condition on the bus */
    SET_BIT(TWCR, TWCR_TWSTO);

    /* Clear the interrupt flag to start the previous operation */
    SET_BIT(TWCR, TWCR_TWINT);
}
