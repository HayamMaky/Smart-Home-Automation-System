/*
 * app.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Hayam
 */
#include"adc.h"
#include"buzzer.h"
#include"dc_motor.h"
#include"flame_sensor.h"
#include"lcd.h"
#include"ldr_sensor.h"
#include"led.h"
#include"lm35_sensor.h"
#include"std_types.h"
/*******************************************************/

int main(void)
{

	LEDS_init();
	ADC_init();
	LCD_init();
	DcMotor_Init();
	FlameSensor_init();
	 Buzzer_init();
	while(1)
	{
		 /*  Automatic Lighting Control
		  *  Based on the LDR readings, the system controls three LEDs
          *  according to light intensity thresholds:
          *  1-Intensity < 15%: All 3 LEDs (Red, Green, and Blue) turn ON.
          *  2-Intensity 16–50%: Red and Green LEDs turn ON.
          *  3-Intensity 51–70%: Only the Red LED turns ON.
          *  4-Intensity > 70%: All LEDs are turned OFF.
		  */
		if((LDR_getLightIntensity())<=15)
		{
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		}
		else if((LDR_getLightIntensity())<=50)
		{
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		}
		else if((LDR_getLightIntensity())<=70)
		{
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		else
		{
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		/*LDR reading display*/
		LCD_moveCursor(1,9);
		LCD_displayString("LDR=");
		LCD_moveCursor(1,13);
		if(LDR_getLightIntensity()<100)
		{
			LCD_intgerToString(LDR_getLightIntensity());
			LCD_displayString("% ");
		}
		else
		{
		LCD_intgerToString(LDR_getLightIntensity());
		LCD_displayString("%");
		}
		/*Automatic Fan Speed Control
		 * Fan speed is automatically adjusted based on room
		 * temperature, controlled by a PWM signal. The fan operates at different speeds based on
		 * temperature ranges:
		 * Temperature ≥ 40°C: Fan ON at 100% speed.
		 * Temperature ≥ 35°C and < 40°C: Fan ON at 75% speed.
		 * Temperature ≥ 30°C and < 35°C: Fan ON at 50% speed.
		 * Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed.
		 * Temperature < 25°C: Fan OFF.
		 */
		/*Temperature < 25°C: Fan OFF.*/
		if((LM35_getTemperature())<25)
		{
			DcMotor_Rotate(Stop, 0);
		}
		/*Temperature ≥ 25°C and < 30°C: Fan ON at 25% speed. */
		else if((LM35_getTemperature())<30)
		{
			DcMotor_Rotate(CW, 25);
		}
		else if((LM35_getTemperature())<35)
		{
			DcMotor_Rotate(CW, 50);
		}
		else if ((LM35_getTemperature())<40)
		{
			DcMotor_Rotate(CW, 75);
		}
		else
		{
			DcMotor_Rotate(CW, 100);
		}
		/*fan state display*/
		if((LM35_getTemperature())<25)
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN is OFF     ");

		}
		else
		{
			LCD_moveCursor(0,0);
			LCD_displayString("FAN is ON     ");
			LCD_displayString(" ");
		}
		LCD_moveCursor(1,0);
		LCD_displayString("Temp=");
		LCD_moveCursor(1,5);
		if(LM35_getTemperature()<100)
		{
	        LCD_intgerToString(LM35_getTemperature());
		    LCD_displayString(" ");
		}
		else
		{
		    LCD_intgerToString(LM35_getTemperature());

		}
		/*Fire Detection and Alert:
		 * The system raises an alarm and displays "Critical alert!" on the
		 * LCD if fire is detected.
		 * The system remains in alert mode until the flame is no longer detected.
		 */
		if(FlameSensor_getValue()==LOGIC_HIGH)
		{
			LCD_sendCommand(LCD_CLEAR_COMMAND);
			LCD_moveCursor(0,0);
			LCD_displayString("Critical Alarm!");
			while(FlameSensor_getValue()==LOGIC_HIGH)
			{
			Buzzer_on();

			}
		}
		else
		{
			Buzzer_off();
			LCD_displayString(" ");
		}


	}
}

