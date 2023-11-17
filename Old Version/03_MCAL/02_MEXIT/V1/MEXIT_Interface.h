
#ifndef _MEXIT_INTERFACE_H_
#define _MEXIT_INTERFACE_H_


/*** Prototypes ***/

/** INT0 **/
void MINT0_VoidInit(void);
void MINT0_VoidEnableINT(void);
void MINT0_VoidDisableINT(void);
void MINT0_VoidSetCallBack(void(*Copy_PointerToFunction)(void));

/** INT1 **/
void MINT1_VoidInit(void);
void MINT1_VoidEnableINT(void);
void MINT1_VoidDisableINT(void);

/** INT2 **/
void MINT2_VoidInit(void);
void MINT2_VoidEnableINT(void);
void MINT2_VoidDisableINT(void);

#endif
