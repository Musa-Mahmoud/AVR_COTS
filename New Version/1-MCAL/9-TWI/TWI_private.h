/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  MCAL                ************************/
/************************        SWC:    TWI                 ************************/
/************************        Version: 1.0                ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK                           0x08 /* Start has been sent                                                     */
#define REP_START_ACK                       0x10 /* Repeated start has been sent                                            */
#define SLAVE_ADDR_AND_WR_ACK               0x18 /* Master transmit ( slave address + write request ) with acknowledgment   */
#define SLAVE_ADDR_AND_RD_ACK               0x40 /* Master transmit ( slave address + read request ) with acknowledgment    */
#define MASTER_WR_BYTE_ACK                  0x28 /* Master transmit data with acknowledgment                                */
#define MASTER_RD_BYTE_WITH_ACK             0x50 /* Master received data with acknowledgment                                */
#define MASTER_RD_BYTE_WITH_NACK            0x58 /* Master received data without acknowledgment                             */
#define SLAVE_ADDR_RCVD_RD_REQ              0xA8 /* Slave address is received with write request                            */
#define SLAVE_ADDR_RCVD_WR_REQ              0x60 /* Slave address is received with red request                              */
#define SLAVE_DATA_RECEIVED                 0x80 /* Byte is received                                                        */
#define SLAVE_BYTE_TRANSMITTED              0xB8 /* Written byte is transmitted                                             */

#endif /* TWI_PRIVATE_H_ End */
