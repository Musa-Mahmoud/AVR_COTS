
#ifndef _MEXIT_PRIVATE_H_
#defin _MEXIT_PRIVATE_H_

#define MCUCR  *((u8*) 0x55)
#define MCUCSR *((u8*) 0x54)
#define GICR   *((u8*) 0x5B)
#define GIFR   *((u8*) 0x5A)

/*** Prototypes ***/
void __vector_1(void) __attribute__((signal));


#endif