/*
 * REFERENCE: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_2/Source/main.c
 */
/*
 *@timers.C
 *@Brief: Source code for configuring TPM for generating PWM signal.
 *Created on: 08-Dec-2022
 *Author: Aneesh Deshpande
 */

/*Include files*/
#include "timers.h"

/*
 * Function: Initializing the TPM for generating PWM signal
 *
 *
 * Parameter [IN]: void
 * Parameter return : void
 */

void tpm_pwm_init(uint16_t period)
{
	//TPM CONFIGURATION
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;

	//CLOCK SOURCE FOR TPM
	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1)| SIM_SOPT2_PLLFLLSEL_MASK);

	//LOAD COUNTER AND MOD VALUE
	TPM0->MOD = period-1;

	//COUNT DIRECTION UP AND DIVIDE BY 2 PRESCALER
	TPM0->SC = TPM_SC_PS(1);

	//OPERATION IN DEBUG MODE
	TPM0->CONF |= TPM_CONF_DBGMODE(3);

	//SET CHANNEL 1 TO EDGE ALIGNED LOW TRUE PWM
	TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;

	//INITIAL DUTY CYCLE
	TPM0->CONTROLS[1].CnV = 0;

	// START TPM
	TPM0->SC |= TPM_SC_CMOD(1);
}
