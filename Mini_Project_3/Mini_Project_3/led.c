/*
 * led.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Hayam
 */
#include"led.h"
#include"gpio.h"
#include"std_types.h"

/*Initializes all Leds (red, green, blue) pins direction.Turn off all the Leds */
void LEDS_init(void)
{
	/*Initializes all Leds (red, green, blue) pins direction. */
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);
	/*Turn off all the Leds*/
#ifdef POSITVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#elif NEGATIVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#endif
}

/*Turns on the specified LED.*/
void LED_on(LED_ID id)
{
#ifdef POSITVE_LOGIC
	switch(id)
	{
	case RED:
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
		break;
	case GREEN:
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
		break;
	case BLUE:
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
		break;
	}
#elif NEGATIVE_LOGIC
	switch(id)
			{
			case RED:
				GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
				break;
			case GREEN:
				GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
				break;
			case BLUE:
				GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
				break;
			}
#endif
}

/*Turns off the specified LED.*/
void LED_off(LED_ID id)
{
#ifdef POSITVE_LOGIC
	switch(id)
		{
		case RED:
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
			break;
		case GREEN:
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
			break;
		case BLUE:
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
			break;
		}
#elif
	switch(id)
		{
		case RED:
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
			break;
		case GREEN:
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
			break;
		case BLUE:
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
			break;
#endif
}

