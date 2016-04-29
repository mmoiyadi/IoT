/*******************************************************************************
* File Name: Connect_LED.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Connect_LED_ALIASES_H) /* Pins Connect_LED_ALIASES_H */
#define CY_PINS_Connect_LED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Connect_LED_0			(Connect_LED__0__PC)
#define Connect_LED_0_PS		(Connect_LED__0__PS)
#define Connect_LED_0_PC		(Connect_LED__0__PC)
#define Connect_LED_0_DR		(Connect_LED__0__DR)
#define Connect_LED_0_SHIFT	(Connect_LED__0__SHIFT)
#define Connect_LED_0_INTR	((uint16)((uint16)0x0003u << (Connect_LED__0__SHIFT*2u)))

#define Connect_LED_INTR_ALL	 ((uint16)(Connect_LED_0_INTR))


#endif /* End Pins Connect_LED_ALIASES_H */


/* [] END OF FILE */
