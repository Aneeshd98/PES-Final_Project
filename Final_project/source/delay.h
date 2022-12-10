/*****************************************************************************
​ ​*​ ​Copyright​ ​(C)​ ​2022​ ​by​ ​Aneesh​ Deshpande
​ ​*
​ ​*​ ​Redistribution,​ ​modification​ ​or​ ​use​ ​of​ ​this​ ​software​ ​in​ ​source​ ​or​ ​binary
​ ​*​ ​forms​ ​is​ ​permitted​ ​as​ ​long​ ​as​ ​the​ ​files​ ​maintain​ ​this​ ​copyright.​ ​Users​ ​are
​ ​*​ ​permitted​ ​to​ ​modify​ ​this​ ​and​ ​use​ ​it​ ​to​ ​learn​ ​about​ ​the​ ​field​ ​of​ ​embedded
​ ​*​ ​software.​ ​Aneesh Deshpande​ ​and​ ​the​ ​University​ ​of​ ​Colorado​ ​are​ ​not​ ​liable​ ​for
​ ​*​ ​any​ ​misuse​ ​of​ ​this​ ​material.
​ ​*
 *****************************************************************************/
/*
 * @file delay.h
 * @breif Header file for delay.c source file.
 * @Created on: 08-Dec-2022
 * @Author: Aneesh Deshpande
 * @version 1
 */
#ifndef DELAY_H_
#define DELAY_H_

/*Including files*/
#include <stdint.h>


typedef uint32_t ticktime_t;

//************************************************Function Prototypes*********************************************

void Init_SysTick(void);
void reset_timer();
ticktime_t now();
ticktime_t get_timer();

#endif /* DELAY_H_ */
