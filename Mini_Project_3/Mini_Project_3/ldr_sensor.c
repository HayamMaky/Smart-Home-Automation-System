/*
 * ldr_sensor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Hayam
 */
#include "ldr_sensor.h"
#include "adc.h"
#include "gpio.h"

/*
 * Description :
 * Function responsible for calculate the light intensity. from the ADC digital value.
 */
 uint16 LDR_getLightIntensity(void)
{
  GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT);
  uint16 light_intensity_value ;
  uint16 adc_value = 0;
  /* Read ADC channel where the LDR sensor is connected */
  adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
  /* Calculate the light intensity from the ADC value*/
  light_intensity_value = ((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE);


  return light_intensity_value;
}
