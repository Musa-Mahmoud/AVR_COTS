/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    EEPROM              ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"

#include "util/delay.h"
#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"



void EEPROM_WriteDataByte(u16 Copy_u16ByteAddress, u8 Copy_u8DataByte)
{
    TWI_SendStartCondition();

    /* Send the 24C08 fixed slave address(4 MSB), A2 value and the memory block number */
    TWI_SendSlaveAddressWithWrite(MOST_4BIT_SLA | (A2_CONNECTION << A2_POS) | GET_BLK_NUM(Copy_u16ByteAddress));

    /* Send the data byte address after sending its specific block in the slave address */
    TWI_MasterWriteDataByte((u8) Copy_u16ByteAddress);

    /* Send the data which to be stored in the EEPROM */
    TWI_MasterWriteDataByte(Copy_u8DataByte);

    TWI_SendStopCondition();

    /* Wait until writing to the EEPROM is finished */
    _delay_ms(10);
}

void EEPROM_ReadDataByte(u16 Copy_u16ByteAddress, u8 *Copy_pu8DataByte)
{
    TWI_SendStartCondition();

    /* Send the 24C08 fixed slave address(4 MSB), A2 value and the memory block number with write request */
    TWI_SendSlaveAddressWithWrite(MOST_4BIT_SLA | (A2_CONNECTION << A2_POS) | GET_BLK_NUM(Copy_u16ByteAddress));

    /* Send the needed byte address after sending its specific block in the slave address */
    TWI_MasterWriteDataByte((u8) Copy_u16ByteAddress);

    /* Send repeated start to change the request form writing to reading */
    TWI_SendRepeatedStart();

    /* Send the 24C08 fixed slave address(4 MSB), A2 value and the memory block number with read request */
    TWI_SendSlaveAddressWithRead(MOST_4BIT_SLA | (A2_CONNECTION << A2_POS) | GET_BLK_NUM(Copy_u16ByteAddress));

    /* Send the data which to be stored in the EEPROM */
    TWI_MasterReadDataByte(Copy_pu8DataByte);

    TWI_SendStopCondition();
}
