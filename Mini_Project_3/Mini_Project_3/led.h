/*
 * led.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Hayam
 */

#ifndef LED_H_
#define LED_H_

# include "std_types.h"

#define RED_LED_PORT_ID     PORTB_ID
#define RED_LED_PIN_ID      PIN5_ID
#define GREEN_LED_PORT_ID   PORTB_ID
#define GREEN_LED_PIN_ID    PIN6_ID
#define BLUE_LED_PORT_ID    PORTB_ID
#define BLUE_LED_PIN_ID     PIN7_ID

#define POSITVE_LOGIC

typedef enum
{
	RED,GREEN,BLUE
}LED_ID;


void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);

#endif /* LED_H_ */
