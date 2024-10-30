/*
 * GPIO.c
 *
 * Created: 10/23/2024 3:33:09 PM
 *  Author: ahmed
 */ 

// ***************************************************************
// *************************** INCLUDES **************************
// ***************************************************************
#include "GPIO.h"

// ***************************************************************
// *************** Macros Configuration References ***************
// ***************************************************************

// ***************************************************************
// ******************** User type definitions ********************
// ***************************************************************
vuint8 * portRegister[PORT_MAX_NUMBER] = {PORTA, PORTB, PORTC, PORTD};
vuint8 * pinRegister[PORT_MAX_NUMBER]  = {PINA,  PINB,  PINC,  PIND};
vuint8 * ddrRegister[PORT_MAX_NUMBER]  = {DDRA,  DDRB,  DDRC,  DDRD};

// ***************************************************************
// ***************************** APIs ****************************
// ***************************************************************
STD_RET GPIO_Pin_Init(const Pin_Config * pin_t)
{
	STD_RET RetVal = E_NOK;
	if(NULL == pin_t)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		RetVal = E_OK;
		if(pin_t->direction == GPIO_OUTPUT)
		{
			SET_BIT(*ddrRegister[pin_t->port], pin_t->pin);
			GPIO_Pin_Write(pin_t, pin_t->logic);
		}
		else if(pin_t->direction == GPIO_INPUT)
		{
			CLR_BIT(*ddrRegister[pin_t->port], pin_t->pin);
			CLR_BIT(*portRegister[pin_t->port], pin_t->pin);
		}
		else if(pin_t->direction == GPIO_INPUT)
		{
			CLR_BIT(*ddrRegister[pin_t->port], pin_t->pin);
			SET_BIT(*portRegister[pin_t->port], pin_t->pin);
		}
		else
		{
			RetVal = E_NOK;
		}
	}
	return RetVal;
}

STD_RET GPIO_Pin_Read(const Pin_Config * pin_t, uint8 * PinState)
{
	STD_RET RetVal = E_NOK;
	if(NULL == pin_t || NULL == PinState)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		*PinState = GET_BIT(*pinRegister[pin_t->port], pin_t->pin);
		RetVal = E_OK;
	}
	return RetVal;
}

STD_RET GPIO_Pin_Write(const Pin_Config * pin_t, uint8 PinState)
{
	STD_RET RetVal = E_NOK;
	if(NULL == pin_t)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		if(PinState == GPIO_HIGH)
		{
			SET_BIT(*portRegister[pin_t->port], pin_t->pin);
		}
		else
		{
			CLR_BIT(*portRegister[pin_t->port], pin_t->pin);
		}
		RetVal = E_OK;
	}
	return RetVal;	
}
STD_RET GPIO_Pin_Toggle(const Pin_Config * pin_t)
{
	STD_RET RetVal = E_NOK;
	if(NULL == pin_t)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		TOGGLE_BIT(*portRegister[pin_t->port], pin_t->pin);
		RetVal = E_OK;
	}
	return RetVal;	
}

STD_RET GPIO_Pin_GetDirection(const Pin_Config * pin_t, uint8 * PinDirection)
{
	STD_RET RetVal = E_NOK;
	if(NULL == pin_t || NULL == PinDirection)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		*PinDirection = GET_BIT(*ddrRegister[pin_t->port], pin_t->pin);
		RetVal = E_OK;
	}
	return RetVal;	
}

STD_RET GPIO_Port_Init(GPIO_PORT PortIndex, uint8 PortDirection)
{
	STD_RET RetVal = E_NOK;
	if(PortIndex > PORT_MAX_NUMBER - 1)
	{
		RetVal = E_NOK;
	}
	else
	{
		*ddrRegister[PortIndex] = PortDirection;
		RetVal = E_OK;
	}
	return RetVal;
}

STD_RET GPIO_Port_Read(GPIO_PORT PortIndex, uint8 *PortState)
{
	STD_RET RetVal = E_NOK;
	if(NULL == PortState)
	{
		RetVal = E_NULL_PTR;
	}
	else if(PortIndex > PORT_MAX_NUMBER - 1)
	{
		RetVal = E_NOK;
	}
	else
	{
		*PortState = *pinRegister[PortIndex];
		RetVal = E_OK;
	}
	return RetVal;
}

STD_RET GPIO_Port_Write(GPIO_PORT PortIndex, uint8 PortState)
{
	STD_RET RetVal = E_NOK;
	if(PortIndex > PORT_MAX_NUMBER - 1)
	{
		RetVal = E_NOK;
	}
	else
	{
		*portRegister[PortIndex] = PortState;
		RetVal = E_OK;
	}
	return RetVal;
}

STD_RET GPIO_Port_Toggle(GPIO_PORT PortIndex)
{
	STD_RET RetVal = E_NOK;
	if(PortIndex > PORT_MAX_NUMBER - 1)
	{
		RetVal = E_NOK;
	}
	else
	{
		*portRegister[PortIndex] ^= PORT_MASK;
		RetVal = E_OK;
	}
	return RetVal;
}

