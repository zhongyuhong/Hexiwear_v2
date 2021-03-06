/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : RGBR.h
**     Project     : Hexiwear_PEx_2_SDKv2
**     Processor   : MK64FN1M0VDC12
**     Component   : LED
**     Version     : Component 01.072, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-25, 18:26, # CodeGen: 24
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : RGBR
**          SDK                                            : KSDK1
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            Anode on port side, HIGH is ON               : no
**            On/Off                                       : Enabled
**              Pin                                        : SDK_BitIO
**            PWM                                          : Disabled
**          Shell                                          : Disabled
**     Contents    :
**         On         - void RGBR_On(void);
**         Off        - void RGBR_Off(void);
**         Neg        - void RGBR_Neg(void);
**         Get        - uint8_t RGBR_Get(void);
**         Put        - void RGBR_Put(uint8_t val);
**         SetRatio16 - void RGBR_SetRatio16(uint16_t ratio);
**         Deinit     - void RGBR_Deinit(void);
**         Init       - void RGBR_Init(void);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013-2016, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file RGBR.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup RGBR_module RGBR module documentation
**  @{
*/         

#ifndef __RGBR_H
#define __RGBR_H

/* MODULE RGBR. */
#include "KSDK1.h" /* include SDK */

#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_NONE
  /* Include shared modules, which are used for whole project */
  #include "PE_Types.h"
  #include "PE_Error.h"
  #include "PE_Const.h"
  #include "IO_Map.h"
#endif

/* Include inherited components */
#include "KSDK1.h"
#include "LEDpin7.h"

#define RGBR_ClrVal()    LEDpin7_ClrVal() /* put the pin on low level */
#define RGBR_SetVal()    LEDpin7_SetVal() /* put the pin on high level */
#define RGBR_SetInput()  LEDpin7_SetInput() /* use the pin as input pin */
#define RGBR_SetOutput() LEDpin7_SetOutput() /* use the pin as output pin */

#define RGBR_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define RGBR_On() LEDpin7_ClrVal()
/*
** ===================================================================
**     Method      :  RGBR_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RGBR_Off() LEDpin7_SetVal()
/*
** ===================================================================
**     Method      :  RGBR_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RGBR_Neg() LEDpin7_NegVal()
/*
** ===================================================================
**     Method      :  RGBR_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RGBR_Get() (!(LEDpin7_GetVal()))
/*
** ===================================================================
**     Method      :  RGBR_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

void RGBR_Init(void);
/*
** ===================================================================
**     Method      :  RGBR_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define RGBR_Put(val)  ((val) ? RGBR_On() : RGBR_Off())
/*
** ===================================================================
**     Method      :  RGBR_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void RGBR_Deinit(void);
/*
** ===================================================================
**     Method      :  RGBR_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void RGBR_SetRatio16(uint16_t ratio);
/*
** ===================================================================
**     Method      :  RGBR_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END RGBR. */

#endif
/* ifndef __RGBR_H */
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
