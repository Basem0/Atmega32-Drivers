/*
 * ATMEGA32.h
 *
 * Created: 10/23/2024 2:53:29 PM
 *  Author: ahmed
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

// ***************************************************************
// *************************** INCLUDES **************************
// ***************************************************************
#include "STD_LIBS.h"

// ***************************************************************
// Function declarations for the interrupt service routines (ISRs)
void __vector_1(void) __attribute__ ((signal));                     
void __vector_2(void) __attribute__ ((signal));
void __vector_3(void) __attribute__ ((signal));
void TIMER2_COMP_vect(void) __attribute__ ((signal));
void TIMER2_OVF_vect(void) __attribute__ ((signal));
void TIMER1_CAPT_vect(void) __attribute__ ((signal));
void TIMER1_COMPA_vect(void) __attribute__ ((signal));
void TIMER1_COMPB_vect(void) __attribute__ ((signal));
void TIMER1_OVF_vect(void) __attribute__ ((signal));
void TIMER0_COMP_vect(void) __attribute__ ((signal));
void TIMER0_OVF_vect(void) __attribute__ ((signal));
void SPI_STC_vect(void) __attribute__ ((signal));
void USART_RXC_vect(void) __attribute__ ((signal));
void USART_UDRE_vect(void) __attribute__ ((signal));
void USART_TXC_vect(void) __attribute__ ((signal));
void ADC_vect(void) __attribute__ ((signal));
void EE_RDY_vect(void) __attribute__ ((signal));
void ANA_COMP_vect(void) __attribute__ ((signal));
// ***************************************************************



// *********************** GPIO REGISTERs ************************
// PORTA REGISTERs
#define PORTA     ((vuint8 *)0x3B)
#define DDRA      ((vuint8 *)0x3A)
#define PINA      ((vuint8 *)0x39)

// PORTB REGISTERs
#define PORTB     ((vuint8 *)0x38)
#define DDRB      ((vuint8 *)0x37)
#define PINB      ((vuint8 *)0x36)

// PORTC REGISTERs
#define PORTC     ((vuint8 *)0x35)
#define DDRC      ((vuint8 *)0x34)
#define PINC      ((vuint8 *)0x33)

// PORTD REGISTERs
#define PORTD     ((vuint8 *)0x32)
#define DDRD      ((vuint8 *)0x31)
#define PIND      ((vuint8 *)0x30)
// ***************************************************************

// ********************* INTERRUPT REGISTERs *********************
#define GICR      ((vuint8 *)0x5B)
#define MCUCR     ((vuint8 *)0x55)
#define MCUCSR    ((vuint8 *)0x54)
#define GIFR      ((vuint8 *)0x5A)
#define SREG	  ((vuint8 *)0x5F)

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
// ***************************************************************






#endif /* ATMEGA32_H_ */