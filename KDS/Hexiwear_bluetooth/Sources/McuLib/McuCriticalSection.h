/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : McuCriticalSection.h
**     Project     : FRDM-K64F_Generator
**     Processor   : MK64FN1M0VLL12
**     Component   : CriticalSection
**     Version     : Component 01.010, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-12, 14:14, # CodeGen: 97
**     Abstract    :
**
**     Settings    :
**          Component name                                 : McuCriticalSection
**          SDK                                            : McuLib
**          Use Processor Expert Default                   : no
**          Use FreeRTOS                                   : no
**     Contents    :
**         CriticalVariable - void McuCriticalSection_CriticalVariable(void);
**         EnterCritical    - void McuCriticalSection_EnterCritical(void);
**         ExitCritical     - void McuCriticalSection_ExitCritical(void);
**
**     * Copyright (c) 2014-2016, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file McuCriticalSection.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup McuCriticalSection_module McuCriticalSection module documentation
**  @{
*/         

#ifndef __McuCriticalSection_H
#define __McuCriticalSection_H

/* MODULE McuCriticalSection. */
#include "McuLib.h" /* SDK and API used */
#include "McuCriticalSectionconfig.h" /* configuration */


/* other includes needed */
#if McuCriticalSection_CONFIG_USE_RTOS_CRITICAL_SECTION
  #include "FreeRTOS.h"
  #include "task.h"  /* FreeRTOS header file for taskENTER_CRITICAL() and taskEXIT_CRITICAL() macros */
#endif


/* workaround macros for wrong EnterCritical()/ExitCritical() in the low level drivers. */
#define McuCriticalSection_CriticalVariableDrv() \
  McuCriticalSection_CriticalVariable()
#define McuCriticalSection_EnterCriticalDrv() \
  McuCriticalSection_EnterCritical()
#define McuCriticalSection_ExitCriticalDrv() \
  McuCriticalSection_ExitCritical()

#ifdef __HIWARE__
  #pragma MESSAGE DISABLE C3303 /* C3303 Implicit concatenation of strings */
#endif

#if McuCriticalSection_CONFIG_USE_PEX_DEFAULT
  #define McuCriticalSection_CriticalVariable() /* nothing needed */
#elif McuCriticalSection_CONFIG_USE_RTOS_CRITICAL_SECTION
  #define McuCriticalSection_CriticalVariable() /* nothing needed */
#elif McuCriticalSection_CONFIG_USE_CUSTOM_CRITICAL_SECTION
  #define McuCriticalSection_CriticalVariable() uint8_t cpuSR; /* variable to store current status */
#endif
/*
** ===================================================================
**     Method      :  McuCriticalSection_CriticalVariable (component CriticalSection)
**     Description :
**         Defines a variable if necessary. This is a macro.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#if McuCriticalSection_CONFIG_USE_PEX_DEFAULT
  #define McuCriticalSection_EnterCritical()   EnterCritical()
#elif McuCriticalSection_CONFIG_USE_RTOS_CRITICAL_SECTION
  #define McuCriticalSection_EnterCritical()   taskENTER_CRITICAL_FROM_ISR() /* FreeRTOS critical section inside interrupt */
#elif McuCriticalSection_CONFIG_USE_CUSTOM_CRITICAL_SECTION
  #define McuCriticalSection_EnterCritical() \
    do {                                  \
      /*lint -save  -esym(529,cpuSR) Symbol 'cpuSR' not subsequently referenced. */\
      __asm (                             \
      "mrs   r0, PRIMASK     \n\t"        \
      "cpsid i               \n\t"        \
      "strb r0, %[output]   \n\t"         \
      : [output] "=m" (cpuSR) :: "r0");   \
      __asm ("" ::: "memory");            \
      /*lint -restore Symbol 'cpuSR' not subsequently referenced. */\
    } while(0)
#endif
/*
** ===================================================================
**     Method      :  McuCriticalSection_EnterCritical (component CriticalSection)
**     Description :
**         Enters a critical section
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#if McuCriticalSection_CONFIG_USE_PEX_DEFAULT
  #define McuCriticalSection_ExitCritical()   ExitCritical()
#elif McuCriticalSection_CONFIG_USE_RTOS_CRITICAL_SECTION
  #define McuCriticalSection_ExitCritical()   taskEXIT_CRITICAL_FROM_ISR(0) /* FreeRTOS critical section inside interrupt */
#elif McuCriticalSection_CONFIG_USE_CUSTOM_CRITICAL_SECTION
  #define McuCriticalSection_ExitCritical() \
   do{                                  \
     __asm (                            \
     "ldrb r0, %[input]    \n\t"        \
     "msr PRIMASK,r0        \n\t"       \
     ::[input] "m" (cpuSR) : "r0");     \
   } while(0)
#endif
/*
** ===================================================================
**     Method      :  McuCriticalSection_ExitCritical (component CriticalSection)
**     Description :
**         Exits a critical section
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END McuCriticalSection. */

#endif
/* ifndef __McuCriticalSection_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
