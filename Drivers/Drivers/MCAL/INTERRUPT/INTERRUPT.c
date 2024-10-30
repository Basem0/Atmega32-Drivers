/*
 * INTERRUPT.c
 *
 * Created: 10/23/2024 9:24:34 PM
 * Author: ahmed
 */

// ***************************************************************
// *************************** INCLUDES **************************
// ***************************************************************
#include "../GPIO/GPIO.h"
#include "INTERRUPT.h"

// ***************************************************************
// ******************** User type definitions ********************
// ***************************************************************
static volatile void (*EXTI_Fun[3])() = {NULL, NULL, NULL};

// ***************************************************************
// ********************** Static Functions ***********************
// ***************************************************************

// Function to define the external interrupt sense control
static STD_RET EXTI_Sense_Def(EXTI_INTx_t pin, EXTI_SENSE sense)
{
	STD_RET RetVal = E_NOK;

	switch(pin)
	{
		case EXTI_INT0:
			RetVal = E_OK;
			switch (sense)
			{
				case LOW_LEVEL:    CLR_BIT(*MCUCR, ISC00); CLR_BIT(*MCUCR, ISC01); break;
				case ON_CHANGE:    SET_BIT(*MCUCR, ISC00); CLR_BIT(*MCUCR, ISC01); break;
				case FALLING_EDGE: CLR_BIT(*MCUCR, ISC00); SET_BIT(*MCUCR, ISC01); break;
				case RISING_EDGE:  SET_BIT(*MCUCR, ISC00); SET_BIT(*MCUCR, ISC01); break;
				default: RetVal = E_NOK;
			}
			break;
		case EXTI_INT1:
			RetVal = E_OK;
			switch (sense)
			{
				case LOW_LEVEL:    CLR_BIT(*MCUCR, ISC10); CLR_BIT(*MCUCR, ISC11); break;
				case ON_CHANGE:    SET_BIT(*MCUCR, ISC10); CLR_BIT(*MCUCR, ISC11); break;
				case FALLING_EDGE: CLR_BIT(*MCUCR, ISC10); SET_BIT(*MCUCR, ISC11); break;
				case RISING_EDGE:  SET_BIT(*MCUCR, ISC10); SET_BIT(*MCUCR, ISC11); break;
				default: RetVal = E_NOK;
			}
			break;

		case EXTI_INT2:
			RetVal = E_OK;
			switch (sense)
			{
				case FALLING_EDGE: CLR_BIT(*MCUCSR, ISC2); break;
				case RISING_EDGE:  SET_BIT(*MCUCSR, ISC2); break;
				default: RetVal = E_NOK;
			}
			break;
			
		default: RetVal = E_NOK;
	}
	return RetVal;
}

// Function to configure the external interrupt pins
static STD_RET Configure_EXTI_Pin(EXTI_INTx_t pin, Pin_Config* pin_t)
{
	STD_RET RetVal = E_NOK;

	switch(pin)
	{
		case EXTI_INT0:
			pin_t->port = GPIO_PORTD;
			pin_t->pin = GPIO_PIN2;
			EXTI_INT0_ENABLE();
			EXTI_INT0_CLR_FLAG();
			RetVal = E_OK;
			break;

		case EXTI_INT1:
			pin_t->port = GPIO_PORTD;
			pin_t->pin = GPIO_PIN3;
			EXTI_INT1_ENABLE();
			EXTI_INT1_CLR_FLAG();
			RetVal = E_OK;
			break;

		case EXTI_INT2:
			pin_t->port = GPIO_PORTB;
			pin_t->pin = GPIO_PIN2;
			EXTI_INT2_ENABLE();
			EXTI_INT2_CLR_FLAG();
			RetVal = E_OK;
			break;

		default:
			RetVal = E_NOK; // Handle invalid pin case
			break;
	}

	return RetVal;
}

// ***************************************************************
// ***************************** APIs ****************************
// ***************************************************************
STD_RET EXTI_Init(EXTI_t *obj)
{
	STD_RET RetVal = E_NOK;

	if (NULL == obj)
	{
		RetVal = E_NULL_PTR;
	}
	else
	{
		Pin_Config pin_t;
		pin_t.direction = GPIO_INPUT;

		// Configure the external interrupt pin
		RetVal = Configure_EXTI_Pin(obj->pin, &pin_t);
		if (RetVal == E_OK)
		{
			// Initialize the GPIO pin for external interrupt
			GPIO_Pin_Init(&pin_t);

			// Set the sense control for the interrupt
			RetVal = EXTI_Sense_Def(obj->pin, obj->sense);

			// Assign the user-provided interrupt handler
			if (RetVal == E_OK)
			{
				EXTI_Fun[obj->pin] = obj->EXT_InterruptHandler;
				GLOBAL_INTERRUPT_ENABLE();
			}
		}
	}

	return RetVal;
}

// ***************************************************************
// ************************* ISR Handlers ************************
// ***************************************************************
void __vector_1(void)
{
	if (EXTI_Fun[EXTI_INT0] != NULL)
	{
		EXTI_Fun[EXTI_INT0]();
	}
}

void __vector_2(void)
{
	if (EXTI_Fun[EXTI_INT1] != NULL)
	{
		EXTI_Fun[EXTI_INT1]();
	}
}

void __vector_3(void)
{
	if (EXTI_Fun[EXTI_INT2] != NULL)
	{
		EXTI_Fun[EXTI_INT2]();
	}
}
