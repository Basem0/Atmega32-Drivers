/*
 * main.c
 *
 * Created: 10/23/2024 2:49:18 PM
 *  Author: ahmed
 */ 



#include "MCAL/GPIO/GPIO.h"
#include "MCAL/INTERRUPT/INTERRUPT.h"

void Led_Toggle();

Pin_Config PORTC_Pin0 = 
{
	.port = GPIO_PORTC,
	.pin = GPIO_PIN0,
	.direction = GPIO_OUTPUT,
	.logic = GPIO_LOW
};
EXTI_t INT0_Pin =
{
	.pin = EXTI_INT0,
	.sense = RISING_EDGE,
	.EXT_InterruptHandler = &Led_Toggle,
};

int main(void)
{
	GPIO_Pin_Init(&PORTC_Pin0);
	EXTI_Init(&INT0_Pin);
    while(1)
    {

    }
}

void Led_Toggle()
{
	GPIO_Pin_Toggle(&PORTC_Pin0);
}