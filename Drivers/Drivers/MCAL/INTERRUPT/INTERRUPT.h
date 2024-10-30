/*
 * INTERRUPT.h
 *
 * Created: 10/23/2024 9:24:18 PM
 *  Author: ahmed
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// ***************************************************************
// *************************** INCLUDES **************************
// ***************************************************************
#include "../../LIBS/ATMEGA32.h"

// ***************************************************************
// *************** Macros Configuration References ***************
// ***************************************************************
#define GLOBAL_INTERRUPT_ENABLE()       (SET_BIT(*SREG, 7))
#define GLOBAL_INTERRUPT_DISABLE()      (CLR_BIT(*SREG, 7))

#define EXTI_INT0_ENABLE()		(SET_BIT(*GICR, 6))
#define EXTI_INT1_ENABLE()		(SET_BIT(*GICR, 7))
#define EXTI_INT2_ENABLE()		(SET_BIT(*GICR, 5))

#define EXTI_INT0_DISABLE()		(CLR_BIT(*GICR, 6))
#define EXTI_INT1_DISABLE()		(CLR_BIT(*GICR, 7))
#define EXTI_INT2_DISABLE()		(CLR_BIT(*GICR, 5))

#define EXTI_INT0_CLR_FLAG()	(SET_BIT(*GIFR, 6))
#define EXTI_INT1_CLR_FLAG()	(SET_BIT(*GIFR, 7))
#define EXTI_INT2_CLR_FLAG()	(SET_BIT(*GIFR, 5))

// ***************************************************************
// ******************** User type definitions ********************
// ***************************************************************
typedef enum
{
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2,
}EXTI_INTx_t;

typedef enum
{
	LOW_LEVEL = 0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}EXTI_SENSE;


typedef struct
{
	void (* EXT_InterruptHandler)(void);
	EXTI_INTx_t pin;
	EXTI_SENSE sense;
}EXTI_t;

// ***************************************************************
// ***************************** APIs ****************************
// ***************************************************************
STD_RET EXTI_Init(EXTI_t *obj);

#endif /* INTERRUPT_H_ */