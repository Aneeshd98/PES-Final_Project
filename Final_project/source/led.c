/*
 * REFERENCE: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 *
 *@LED.C
 *@Brief: Source code for configuring led.
 *Created on: 08-Dec-2022
 *Author: Aneesh Deshpande
 */

/*Include files*/
#include "LED.h"

#define BLUE_LED (1)   //PORT D pin 1

/*
 * Function: Initializing the LED's by providing clock
 *           and configuring them as output pins.
 *
 * Parameter [IN]: void
 * Parameter return : void
 */
void led_init()
{
	//CLOCK TO PORT D
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	//Make pin as GPIO.
	PORTD->PCR[BLUE_LED] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED] |= PORT_PCR_MUX(4);
}

