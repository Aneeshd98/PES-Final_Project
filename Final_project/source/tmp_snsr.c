/*
 * Reference: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_6/Analog%20Demo/src/main.c
 * 			  https://www.nxp.com/docs/en/application-note/AN3031.pdf
 */
/*
 * @file tmp_snsr.c
 * @brief File to get temperature using kl25z.
 * @Created on: 06-Dec-2022
 * @Author: Aneesh Deshpande
 */
/*Include files*/
#include "tmp_snsr.h"
#include "adc.h"

/*Defining macros*/
#define CHANNEL_26 (0x1A)
#define Vtemp25    (224)
#define slope_cold (52)
#define slope_hot  (56)
#define multiplier (100)
#define ref_temp   (25)

/*
 * Function: To measure temperature using ADC and temperature sensor on the kl25z.
 *
 * Parameter [IN]: void
 * Parameter return : float
 */
float Measure_Temperature(void)
{
	float vtemp, temp;

	ADC0->SC1[0] = CHANNEL_26; // start conversion on channel 26

	// Wait for conversion to finish
	while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));

	// Read result, convert to floating-point
	vtemp = (float) ADC0->R[0];

	if (vtemp >= Vtemp25)
	{
		temp = ref_temp -  ((vtemp - Vtemp25)*multiplier/slope_cold); // temperature calculation using cold slope value.
	}
	else
	{
		temp = ref_temp -  ((vtemp - Vtemp25)*multiplier/slope_hot); // temperature calculation using hot slope value.
	}
	return temp;
}
