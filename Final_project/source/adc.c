/*
 * Reference: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_6/Analog%20Demo/src/main.c
 * 			  https://www.nxp.com/docs/en/application-note/AN3031.pdf
 */
/*
 * @file adc.c
 * @brief File to initialize ADC on FRDM-KL25Z.
 * @Created on: 06-Dec-2022
 * @Author: Aneesh Deshpande
 */
/*Include files*/
#include "adc.h"

/*defining macros*/
#define ADC_POS (20)

/*
 * Function: To initialize adc.
 *
 * Parameter [IN]: void
 * Parameter return : void
 */
void Init_ADC(void)
{
	//Provide clock.
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	// Select analog for pin
	PORTE->PCR[ADC_POS] &= ~PORT_PCR_MUX_MASK;
	PORTE->PCR[ADC_POS] |= PORT_PCR_MUX(0);

	// Low power configuration, long sample time, 10 bit single-ended conversion, clock divide by 8, bus clock input
	ADC0->CFG1 = ADC_CFG1_ADLPC_MASK | ADC_CFG1_ADLSMP_MASK | ADC_CFG1_MODE(2) | ADC_CFG1_ADIV(3) | ADC_CFG1_ADICLK(0);

	// Software trigger, compare function disabled, DMA disabled, voltage references VREFH and VREFL
	ADC0->SC2 = ADC_SC2_REFSEL(0);
}
