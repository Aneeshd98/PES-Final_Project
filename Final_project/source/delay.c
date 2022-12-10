/*
 * @file delay.c
 * @brief File to generate delay using SysTick.
 * @Created on: 08-Dec-2022
 * @Author: Aneesh Deshpande
 */
/*Include files*/
#include "delay.h"
#include "MKL25Z4.h"
#include "core_cm0plus.h"

/*Defining Macros*/
#define SYSTEM_CLK (48000000L)
#define SYS_LOAD_VAL (SYSTEM_CLK/256)

/*Global Variables*/
volatile ticktime_t strt_time=0;			//variable to store execution time in msec from the beginning.
volatile ticktime_t tmp_cnt=0;				//variable used to generate delay in msec.


void Init_SysTick(void)
{
	// SysTick is defined in core_cm0.h
	SysTick->LOAD = (SYS_LOAD_VAL) - 1; //ISR every 62.5 milliseconds
	// Set interrupt priority
	NVIC_SetPriority(SysTick_IRQn, 1);
	// Force load of reload value
	SysTick->VAL = 0;
	// Enable interrupt, enable SysTick timer
	SysTick->CTRL =  SysTick_CTRL_TICKINT_Msk |
			SysTick_CTRL_ENABLE_Msk;
}

/*
 * Function: SysTick Interrupt Handler executed every time the
 *           counter/timer overflows.
 *
 * Parameter [IN]: void
 * Parameter return : void
 */
void SysTick_Handler()
{
	strt_time+=1;
	tmp_cnt+=1;
}
/*
 * Function: Resets the tmp_cnt variable which is used to
 *           generate delay's.
 *
 * Parameter [IN]: void
 * Parameter return : void
 */
void reset_timer()
{
	tmp_cnt=0;
}
/*
 * Function: Returns time from the beginning of execution.
 *
 *
 * Parameter [IN]: void
 * Parameter return : ticktime_t strt_time.
 */
ticktime_t now()
{
	return strt_time;
}
/*
 * Function: Returns the tmp_cnt value.
 *
 *
 * Parameter [IN]: void
 * Parameter return : ticktime_t tmp_cnt.
 */
ticktime_t get_timer()
{
	return tmp_cnt;
}
