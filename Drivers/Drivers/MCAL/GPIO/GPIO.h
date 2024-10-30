/*
 * GPIO.h
 *
 * Created: 10/23/2024 3:32:55 PM
 *  Author: ahmed
 */ 


#ifndef GPIO_H_
#define GPIO_H_

// ***************************************************************
// *************************** INCLUDES **************************
// ***************************************************************
#include "../../LIBS/ATMEGA32.h"

// ***************************************************************
// *************** Macros Configuration References ***************
// ***************************************************************
#define BIT_MASK    (uint8)1
#define PORT_MASK   (uint8)0xFF

#define PORT_PIN_MAX_NUMBER  8
#define PORT_MAX_NUMBER      4

#define GPIO_PORT_HIGH  0xFF
#define GPIO_PORT_LOW   0x00

// ***************************************************************
// ******************** User type definitions ********************
// ***************************************************************
typedef enum
{
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7, 
}GPIO_PINS;

typedef enum
{
	GPIO_PORTA = 0,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
}GPIO_PORT;

typedef enum
{
	GPIO_INPUT = 0,
	GPIO_OUTPUT,
	GPIO_PULL_UP,	
}GPIO_DIRECTION;

typedef enum
{
	GPIO_LOW = 0,
	GPIO_HIGH,
}GPIO_LOGIC;

typedef struct
{
	GPIO_PINS pin;
	GPIO_PORT port;
	GPIO_DIRECTION direction;
	GPIO_LOGIC logic;
}Pin_Config;

// ***************************************************************
// ***************************** APIs ****************************
// ***************************************************************
STD_RET GPIO_Pin_Init(const Pin_Config * pin_t);
STD_RET GPIO_Pin_Read(const Pin_Config * pin_t, uint8 * PinState);
STD_RET GPIO_Pin_Write(const Pin_Config * pin_t, uint8 PinState);
STD_RET GPIO_Pin_Toggle(const Pin_Config * pin_t);
STD_RET GPIO_Pin_GetDirection(const Pin_Config * pin_t, uint8 * PinDirection);

STD_RET GPIO_Port_Init(GPIO_PORT PortIndex, uint8 PortDirection);
STD_RET GPIO_Port_Read(GPIO_PORT PortIndex, uint8 *PortState);
STD_RET GPIO_Port_Write(GPIO_PORT PortIndex, uint8 PortState);
STD_RET GPIO_Port_Toggle(GPIO_PORT PortIndex);


#endif /* GPIO_H_ */