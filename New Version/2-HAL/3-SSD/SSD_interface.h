/************************************************************************************/
/************************************************************************************/
/************************        Author: Musa Mahmoud        ************************/
/************************        Layer:  HAL                 ************************/
/************************        SWC:    SSD                 ************************/
/************************        Version:1.0                 ************************/
/************************************************************************************/
/************************************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/* Error State Macros */
#define SSD_u8OK        1
#define SSD_u8NOT_OK    0

/* Configuration Options Macros */
#define SSD_u8COM_ANODE     1
#define SSD_u8COM_CATHODE   0

/* SSD  */

/* Type Definition */
typedef struct SSD
{
    u8 ComType;         /* Common connection type: Anode or Cathode                 */
    u8 Port;            /* MCU I/O port for connecting 7-segments' segment          */
    u8 EnablePort;      /* MCU I/O port for connecting 7-segments' common pin       */
    u8 EnablePin;       /* MCU I/O pin for connecting 7-segments' common pin        */
    u8 DPPort;          /* MCU I/O port for connecting 7-segments' decimal point    */
    u8 DPPin;           /* MCU I/O pin for connecting 7-segments' decimal point     */
}SSD_t;

/* Functions Prototypes */
u8 static inline IsConfigurationValid(SSD_t *SSDConfig);

u8 SSD_u8DisplayNumber(SSD_t *SSDConfig, u8 Copy_u8Number);

u8 SSD_u8Enable(SSD_t *SSDConfig);

u8 SSD_u8Disable(SSD_t *SSDConfig);

u8 SSD_u8EnableDecimalPoint(SSD_t *SSDConfig);

u8 SSD_u8DisableDecimalPoint(SSD_t *SSDConfig);


#endif /* SSD_INTERFACE_H_ End */
