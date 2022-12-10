/*****************************************************************************
​ ​*​ ​Copyright​ ​(C)​ ​2022​ ​by​ ​Aneesh​ Deshpande
​ ​*
​ ​*​ ​Redistribution,​ ​modification​ ​or​ ​use​ ​of​ ​this​ ​software​ ​in​ ​source​ ​or​ ​binary
​ ​*​ ​forms​ ​is​ ​permitted​ ​as​ ​long​ ​as​ ​the​ ​files​ ​maintain​ ​this​ ​copyright.​ ​Users​ ​are
​ ​*​ ​permitted​ ​to​ ​modify​ ​this​ ​and​ ​use​ ​it​ ​to​ ​learn​ ​about​ ​the​ ​field​ ​of​ ​embedded
​ ​*​ ​software.​ ​Aneesh​ Deshpande ​and​ ​the​ ​University​ ​of​ ​Colorado​ ​are​ ​not​ ​liable​ ​for
​ ​*​ ​any​ ​misuse​ ​of​ ​this​ ​material.
​ ​*
 *****************************************************************************/
/*
 * @file timer.h
 * @breif Header file for timer.c source file.
 * @Created on: 08-Dec-2022
 * @Author: Aneesh Deshpande
 * @version 1
 */

#ifndef TIMER_H_
#define TIMER_H_

/*Including files*/
#include <stdio.h>
#include "MKL25Z4.h"

//************************************************Function Prototypes*********************************************
void tpm_pwm_init(uint16_t period);
void reset_timer();

#endif /* TIMER_H_ */
