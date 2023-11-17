
#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_



/*** Macros ***/

/** Ports **/

/*Port A*/
#define A 0
#define PORTA 0

/*Port B*/
#define B 1
#define PORTB 1

/*Port C*/
#define C 2
#define PORTC 2

/*Port D*/
#define D 3
#define PORTD 3


/** Pins **/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


/** Port Inputs/Outputs **/
#define HIGH 1
#define LOW  0


/** Dirctions **/
#define INPUT  0
#define OUTPUT 1


/*** Prototypes ***/

void MDIO_VoidSetPinDirection(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8Dir);

void MDIO_VoidSetPortDirection(u8 Copy_U8PortNum, u8 Copy_U8PortDir);

u8 MDIO_U8GetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);

u8 MDIO_U8GetPortValue(u8 Copy_U8PortNum);

void MDIO_VoidSetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8PinValue);

void MDIO_VoidSetPortValue(u8 Copy_U8PortNum, u8 Copy_U8PortValue);

void MDIO_VoidTogglePinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);

void MDIO_VoidTogglePortValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);

void MDIO_VoidActivatePinInternalPullupResistor(u8 Copy_U8PortNum, u8 Copy_U8PinNum);

void MDIO_VoidActivatePortInternalPullupResistor(u8 Copy_U8PortNum);



#endif