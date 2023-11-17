
#ifndef _MSPI_INTERFACE_H_
#define _MSPI_INTERFACE_H_

/*** Prototypes ***/

/** Slave Functions **/
void MSPI_VoidSlaveInit(void);

u8 MSPI_U8Receive(void);


/** Master Functions **/
void MSPI_VoidMasterInit(void);

void MSPI_VoidSend(u8 Copy_U8Data);

#endif