/*
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    Final_project.c
 * @brief   Application entry point.
 * @Created on: 06-Dec-2022
 * @Author: Aneesh Deshpande
 */
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "tmp_snsr.h"
#include "adc.h"
#include"led.h"
#include"timers.h"
#include "delay.h"
#include "stdbool.h"
/* TODO: insert other definitions and declarations here. */
#define FIVE_SECOND (80) 	//Macro for getting temperature every 5 second.
#define pwm_period  (255) 	//Macro for defining PWM period.
#define PWM_MAX_VAL (255)	//PWM max value.
#define PWM_MIN_VAL (0)		//PWM min value.
#define PWM_STEP    (40)	// Increment or decrement step size for pwm.

/*
 * @brief   Application entry point.
 */
int main(void)
{
	float cur_tmp_val=0,prv_tmp=0, tmp_diff=0, abs_tmp_diff=0;
	bool gt_flg=0;
	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif
	Init_SysTick();
	led_init();
	tpm_pwm_init(pwm_period);
	Init_ADC();
	reset_timer();		//Resetting timer before entering while loop.
	while(1)
	{
		if (get_timer() > FIVE_SECOND ) //Check for 5 second.
		{
			cur_tmp_val=Measure_Temperature();	//get temperature from the sensor.
			gt_flg=0;
			if (prv_tmp != cur_tmp_val)	//check for temperature change.
			{
				tmp_diff = prv_tmp-cur_tmp_val;
				if(tmp_diff<0)		    //check for increase in temperature.
				{
					gt_flg=1;
					abs_tmp_diff=abs(tmp_diff);
					if(abs_tmp_diff>=1)
					{
						if ((TPM0->CONTROLS[1].CnV<=PWM_MAX_VAL)) //check if pwm is at max value.
						{
							TPM0->CONTROLS[1].CnV = TPM0->CONTROLS[1].CnV + PWM_STEP;
						}
						else
							TPM0->CONTROLS[1].CnV=PWM_MAX_VAL;
					}
				}
				else
				{
					if(tmp_diff>1 && gt_flg==0)
					{
						if ((TPM0->CONTROLS[1].CnV<=PWM_MIN_VAL))	// check if pwm is at the min value.
						{
							TPM0->CONTROLS[1].CnV=PWM_MIN_VAL;
						}
						else
						{
							TPM0->CONTROLS[1].CnV = TPM0->CONTROLS[1].CnV - PWM_STEP;
						}
					}
				}
				prv_tmp=cur_tmp_val;	//set current temp value as previous value for next iteration.
			}
			printf("The temperature reading from the embedded temperature sensor is %0.2f C.\n\r", cur_tmp_val);
			reset_timer();
		}
	}
	return 0 ;
}
