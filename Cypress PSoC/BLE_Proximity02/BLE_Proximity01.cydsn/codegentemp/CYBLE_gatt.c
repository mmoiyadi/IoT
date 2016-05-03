/***************************************************************************//**
* \file CYBLE_gatt.c
* \version 3.10
* 
* \brief
*  This file contains the source code for the GATT API of the BLE Component.
* 
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "CYBLE_eventHandler.h"


/***************************************
* Global variables
***************************************/

CYBLE_STATE_T cyBle_state;

#if ((CYBLE_MODE_PROFILE) && (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES))
    
#if(CYBLE_MODE_PROFILE)
    #if defined(__ARMCC_VERSION)
        CY_ALIGN(CYDEV_FLS_ROW_SIZE) const CY_BLE_FLASH_STORAGE cyBle_flashStorage CY_SECTION(".cy_checksum_exclude") =
    #elif defined (__GNUC__)
        const CY_BLE_FLASH_STORAGE cyBle_flashStorage CY_SECTION(".cy_checksum_exclude")
            CY_ALIGN(CYDEV_FLS_ROW_SIZE) =
    #elif defined (__ICCARM__)
        #pragma data_alignment=CY_FLASH_SIZEOF_ROW
        #pragma location=".cy_checksum_exclude"
        const CY_BLE_FLASH_STORAGE cyBle_flashStorage =
    #endif  /* (__ARMCC_VERSION) */
    {
        { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u }, 
        {{
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
        }}, 
        0x0Au, /* CYBLE_GATT_DB_CCCD_COUNT */ 
        0x05u, /* CYBLE_GAP_MAX_BONDED_DEVICE */ 
    };
#endif /* (CYBLE_MODE_PROFILE) */

#endif  /* (CYBLE_MODE_PROFILE) && (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES) */

#if(CYBLE_GATT_ROLE_SERVER)
    
    const CYBLE_GATTS_T cyBle_gatts =
{
    0x0008u,    /* Handle of the GATT service */
    0x000Au,    /* Handle of the Service Changed characteristic */
    0x000Bu,    /* Handle of the Client Characteristic Configuration descriptor */
};
    
    static uint8 cyBle_attValues[0x50u] = {
    /* Device Name */
    (uint8)'P', (uint8)'r', (uint8)'o', (uint8)'x', (uint8)'i', (uint8)'m', (uint8)'i', (uint8)'t', (uint8)'y', (uint8)' ',
(uint8)'R', (uint8)'e', (uint8)'p', (uint8)'o', (uint8)'r', (uint8)'t', (uint8)'e', (uint8)'r', 

    /* Appearance */
    0x00u, 0x02u, 

    /* Peripheral Preferred Connection Parameters */
    0x28u, 0x00u, 0x38u, 0x00u, 0x00u, 0x00u, 0xE8u, 0x03u, 

    /* Service Changed */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* Alert Level */
    0x00u, 

    /* Tx Power Level */
    0x00u, 

    /* Custom Characteristic */
    0x00u, 

    /* First Name */
    

    /* Last Name */
    

    /* Email Address */
    

    /* Age */
    0x00u, 

    /* Date of Birth */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* Gender */
    0x00u, 

    /* Weight */
    0x00u, 0x00u, 

    /* Height */
    0x00u, 0x00u, 

    /* VO2 Max */
    0x00u, 

    /* Heart Rate Max */
    0x00u, 

    /* Resting Heart Rate */
    0x00u, 

    /* Maximum Recommended Heart Rate */
    0x00u, 

    /* Aerobic Threshold */
    0x00u, 

    /* Anaerobic Threshold */
    0x00u, 

    /* Sport Type for Aerobic and Anaerobic Thresholds */
    0x00u, 

    /* Date of Threshold Assessment */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* Waist Circumference */
    0x00u, 0x00u, 

    /* Hip Circumference */
    0x00u, 0x00u, 

    /* Fat Burn Heart Rate Lower Limit */
    0x00u, 

    /* Fat Burn Heart Rate Upper Limit */
    0x00u, 

    /* Aerobic Heart Rate Lower Limit */
    0x00u, 

    /* Aerobic Heart Rate Upper Limit */
    0x00u, 

    /* Anaerobic Heart Rate Lower Limit */
    0x00u, 

    /* Anaerobic Heart Rate Upper Limit */
    0x00u, 

    /* Five Zone Heart Rate Limits */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* Three Zone Heart Rate Limits */
    0x00u, 0x00u, 

    /* Two Zone Heart Rate Limit */
    0x00u, 

    /* Database Change Increment */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* User Index */
    0xFFu, 

    /* User Control Point */
    0x01u, 0x00u, 

    /* Language */
    

};
#if(CYBLE_GATT_DB_CCCD_COUNT != 0u)
uint8 cyBle_attValuesCCCD[CYBLE_GATT_DB_CCCD_COUNT];
#endif /* CYBLE_GATT_DB_CCCD_COUNT != 0u */

CYBLE_GATTS_ATT_GEN_VAL_LEN_T cyBle_attValuesLen[CYBLE_GATT_DB_ATT_VAL_COUNT] = {
    { 0x0012u, (void *)&cyBle_attValues[0] }, /* Device Name */
    { 0x0002u, (void *)&cyBle_attValues[18] }, /* Appearance */
    { 0x0008u, (void *)&cyBle_attValues[20] }, /* Peripheral Preferred Connection Parameters */
    { 0x0004u, (void *)&cyBle_attValues[28] }, /* Service Changed */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[0] }, /* Client Characteristic Configuration */
    { 0x0001u, (void *)&cyBle_attValues[32] }, /* Alert Level */
    { 0x0001u, (void *)&cyBle_attValues[33] }, /* Tx Power Level */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[2] }, /* Client Characteristic Configuration */
    { 0x0001u, (void *)&cyBle_attValues[34] }, /* Custom Characteristic */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[4] }, /* Client Characteristic Configuration */
    { 0x0000u, (void *)&cyBle_attValues[35] }, /* First Name */
    { 0x0000u, (void *)&cyBle_attValues[35] }, /* Last Name */
    { 0x0000u, (void *)&cyBle_attValues[35] }, /* Email Address */
    { 0x0001u, (void *)&cyBle_attValues[35] }, /* Age */
    { 0x0004u, (void *)&cyBle_attValues[36] }, /* Date of Birth */
    { 0x0001u, (void *)&cyBle_attValues[40] }, /* Gender */
    { 0x0002u, (void *)&cyBle_attValues[41] }, /* Weight */
    { 0x0002u, (void *)&cyBle_attValues[43] }, /* Height */
    { 0x0001u, (void *)&cyBle_attValues[45] }, /* VO2 Max */
    { 0x0001u, (void *)&cyBle_attValues[46] }, /* Heart Rate Max */
    { 0x0001u, (void *)&cyBle_attValues[47] }, /* Resting Heart Rate */
    { 0x0001u, (void *)&cyBle_attValues[48] }, /* Maximum Recommended Heart Rate */
    { 0x0001u, (void *)&cyBle_attValues[49] }, /* Aerobic Threshold */
    { 0x0001u, (void *)&cyBle_attValues[50] }, /* Anaerobic Threshold */
    { 0x0001u, (void *)&cyBle_attValues[51] }, /* Sport Type for Aerobic and Anaerobic Thresholds */
    { 0x0004u, (void *)&cyBle_attValues[52] }, /* Date of Threshold Assessment */
    { 0x0002u, (void *)&cyBle_attValues[56] }, /* Waist Circumference */
    { 0x0002u, (void *)&cyBle_attValues[58] }, /* Hip Circumference */
    { 0x0001u, (void *)&cyBle_attValues[60] }, /* Fat Burn Heart Rate Lower Limit */
    { 0x0001u, (void *)&cyBle_attValues[61] }, /* Fat Burn Heart Rate Upper Limit */
    { 0x0001u, (void *)&cyBle_attValues[62] }, /* Aerobic Heart Rate Lower Limit */
    { 0x0001u, (void *)&cyBle_attValues[63] }, /* Aerobic Heart Rate Upper Limit */
    { 0x0001u, (void *)&cyBle_attValues[64] }, /* Anaerobic Heart Rate Lower Limit */
    { 0x0001u, (void *)&cyBle_attValues[65] }, /* Anaerobic Heart Rate Upper Limit */
    { 0x0004u, (void *)&cyBle_attValues[66] }, /* Five Zone Heart Rate Limits */
    { 0x0002u, (void *)&cyBle_attValues[70] }, /* Three Zone Heart Rate Limits */
    { 0x0001u, (void *)&cyBle_attValues[72] }, /* Two Zone Heart Rate Limit */
    { 0x0004u, (void *)&cyBle_attValues[73] }, /* Database Change Increment */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[6] }, /* Client Characteristic Configuration */
    { 0x0001u, (void *)&cyBle_attValues[77] }, /* User Index */
    { 0x0002u, (void *)&cyBle_attValues[78] }, /* User Control Point */
    { 0x0002u, (void *)&cyBle_attValuesCCCD[8] }, /* Client Characteristic Configuration */
    { 0x0000u, (void *)&cyBle_attValues[80] }, /* Language */
};

const CYBLE_GATTS_DB_T cyBle_gattDB[0x57u] = {
    { 0x0001u, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x0007u, {{0x1800u, NULL}}                           },
    { 0x0002u, 0x2803u /* Characteristic                      */, 0x00000201u /* rd     */, 0x0003u, {{0x2A00u, NULL}}                           },
    { 0x0003u, 0x2A00u /* Device Name                         */, 0x00000201u /* rd     */, 0x0003u, {{0x0012u, (void *)&cyBle_attValuesLen[0]}} },
    { 0x0004u, 0x2803u /* Characteristic                      */, 0x00000201u /* rd     */, 0x0005u, {{0x2A01u, NULL}}                           },
    { 0x0005u, 0x2A01u /* Appearance                          */, 0x00000201u /* rd     */, 0x0005u, {{0x0002u, (void *)&cyBle_attValuesLen[1]}} },
    { 0x0006u, 0x2803u /* Characteristic                      */, 0x00000201u /* rd     */, 0x0007u, {{0x2A04u, NULL}}                           },
    { 0x0007u, 0x2A04u /* Peripheral Preferred Connection Par */, 0x00000201u /* rd     */, 0x0007u, {{0x0008u, (void *)&cyBle_attValuesLen[2]}} },
    { 0x0008u, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x000Bu, {{0x1801u, NULL}}                           },
    { 0x0009u, 0x2803u /* Characteristic                      */, 0x00002001u /* ind    */, 0x000Bu, {{0x2A05u, NULL}}                           },
    { 0x000Au, 0x2A05u /* Service Changed                     */, 0x00002000u /* ind    */, 0x000Bu, {{0x0004u, (void *)&cyBle_attValuesLen[3]}} },
    { 0x000Bu, 0x2902u /* Client Characteristic Configuration */, 0x00000A04u /* rd,wr  */, 0x000Bu, {{0x0002u, (void *)&cyBle_attValuesLen[4]}} },
    { 0x000Cu, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x000Eu, {{0x1803u, NULL}}                           },
    { 0x000Du, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x000Eu, {{0x2A06u, NULL}}                           },
    { 0x000Eu, 0x2A06u /* Alert Level                         */, 0x00000A04u /* rd,wr  */, 0x000Eu, {{0x0001u, (void *)&cyBle_attValuesLen[5]}} },
    { 0x000Fu, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x0012u, {{0x1804u, NULL}}                           },
    { 0x0010u, 0x2803u /* Characteristic                      */, 0x00001201u /* rd,ntf */, 0x0012u, {{0x2A07u, NULL}}                           },
    { 0x0011u, 0x2A07u /* Tx Power Level                      */, 0x00001201u /* rd,ntf */, 0x0012u, {{0x0001u, (void *)&cyBle_attValuesLen[6]}} },
    { 0x0012u, 0x2902u /* Client Characteristic Configuration */, 0x00000A04u /* rd,wr  */, 0x0012u, {{0x0002u, (void *)&cyBle_attValuesLen[7]}} },
    { 0x0013u, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x0016u, {{0x0000u, NULL}}                           },
    { 0x0014u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0016u, {{0x0000u, NULL}}                           },
    { 0x0015u, 0x0000u /* Custom Characteristic               */, 0x00010A04u /* rd,wr  */, 0x0016u, {{0x0001u, (void *)&cyBle_attValuesLen[8]}} },
    { 0x0016u, 0x2902u /* Client Characteristic Configuration */, 0x00010A04u /* rd,wr  */, 0x0016u, {{0x0002u, (void *)&cyBle_attValuesLen[9]}} },
    { 0x0017u, 0x2800u /* Primary service                     */, 0x00000001u /*        */, 0x0057u, {{0x181Cu, NULL}}                           },
    { 0x0018u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0019u, {{0x2A8Au, NULL}}                           },
    { 0x0019u, 0x2A8Au /* First Name                          */, 0x00010A04u /* rd,wr  */, 0x0019u, {{0x0000u, (void *)&cyBle_attValuesLen[10]}} },
    { 0x001Au, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x001Bu, {{0x2A90u, NULL}}                           },
    { 0x001Bu, 0x2A90u /* Last Name                           */, 0x00010A04u /* rd,wr  */, 0x001Bu, {{0x0000u, (void *)&cyBle_attValuesLen[11]}} },
    { 0x001Cu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x001Du, {{0x2A87u, NULL}}                           },
    { 0x001Du, 0x2A87u /* Email Address                       */, 0x00010A04u /* rd,wr  */, 0x001Du, {{0x0000u, (void *)&cyBle_attValuesLen[12]}} },
    { 0x001Eu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x001Fu, {{0x2A80u, NULL}}                           },
    { 0x001Fu, 0x2A80u /* Age                                 */, 0x00010A04u /* rd,wr  */, 0x001Fu, {{0x0001u, (void *)&cyBle_attValuesLen[13]}} },
    { 0x0020u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0021u, {{0x2A85u, NULL}}                           },
    { 0x0021u, 0x2A85u /* Date of Birth                       */, 0x00010A04u /* rd,wr  */, 0x0021u, {{0x0004u, (void *)&cyBle_attValuesLen[14]}} },
    { 0x0022u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0023u, {{0x2A8Cu, NULL}}                           },
    { 0x0023u, 0x2A8Cu /* Gender                              */, 0x00010A04u /* rd,wr  */, 0x0023u, {{0x0001u, (void *)&cyBle_attValuesLen[15]}} },
    { 0x0024u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0025u, {{0x2A98u, NULL}}                           },
    { 0x0025u, 0x2A98u /* Weight                              */, 0x00010A04u /* rd,wr  */, 0x0025u, {{0x0002u, (void *)&cyBle_attValuesLen[16]}} },
    { 0x0026u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0027u, {{0x2A8Eu, NULL}}                           },
    { 0x0027u, 0x2A8Eu /* Height                              */, 0x00010A04u /* rd,wr  */, 0x0027u, {{0x0002u, (void *)&cyBle_attValuesLen[17]}} },
    { 0x0028u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0029u, {{0x2A96u, NULL}}                           },
    { 0x0029u, 0x2A96u /* VO2 Max                             */, 0x00010A04u /* rd,wr  */, 0x0029u, {{0x0001u, (void *)&cyBle_attValuesLen[18]}} },
    { 0x002Au, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x002Bu, {{0x2A8Du, NULL}}                           },
    { 0x002Bu, 0x2A8Du /* Heart Rate Max                      */, 0x00010A04u /* rd,wr  */, 0x002Bu, {{0x0001u, (void *)&cyBle_attValuesLen[19]}} },
    { 0x002Cu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x002Du, {{0x2A92u, NULL}}                           },
    { 0x002Du, 0x2A92u /* Resting Heart Rate                  */, 0x00010A04u /* rd,wr  */, 0x002Du, {{0x0001u, (void *)&cyBle_attValuesLen[20]}} },
    { 0x002Eu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x002Fu, {{0x2A91u, NULL}}                           },
    { 0x002Fu, 0x2A91u /* Maximum Recommended Heart Rate      */, 0x00010A04u /* rd,wr  */, 0x002Fu, {{0x0001u, (void *)&cyBle_attValuesLen[21]}} },
    { 0x0030u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0031u, {{0x2A7Fu, NULL}}                           },
    { 0x0031u, 0x2A7Fu /* Aerobic Threshold                   */, 0x00010A04u /* rd,wr  */, 0x0031u, {{0x0001u, (void *)&cyBle_attValuesLen[22]}} },
    { 0x0032u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0033u, {{0x2A83u, NULL}}                           },
    { 0x0033u, 0x2A83u /* Anaerobic Threshold                 */, 0x00010A04u /* rd,wr  */, 0x0033u, {{0x0001u, (void *)&cyBle_attValuesLen[23]}} },
    { 0x0034u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0035u, {{0x2A93u, NULL}}                           },
    { 0x0035u, 0x2A93u /* Sport Type for Aerobic and Anaerobi */, 0x00010A04u /* rd,wr  */, 0x0035u, {{0x0001u, (void *)&cyBle_attValuesLen[24]}} },
    { 0x0036u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0037u, {{0x2A86u, NULL}}                           },
    { 0x0037u, 0x2A86u /* Date of Threshold Assessment        */, 0x00010A04u /* rd,wr  */, 0x0037u, {{0x0004u, (void *)&cyBle_attValuesLen[25]}} },
    { 0x0038u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0039u, {{0x2A97u, NULL}}                           },
    { 0x0039u, 0x2A97u /* Waist Circumference                 */, 0x00010A04u /* rd,wr  */, 0x0039u, {{0x0002u, (void *)&cyBle_attValuesLen[26]}} },
    { 0x003Au, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x003Bu, {{0x2A8Fu, NULL}}                           },
    { 0x003Bu, 0x2A8Fu /* Hip Circumference                   */, 0x00010A04u /* rd,wr  */, 0x003Bu, {{0x0002u, (void *)&cyBle_attValuesLen[27]}} },
    { 0x003Cu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x003Du, {{0x2A88u, NULL}}                           },
    { 0x003Du, 0x2A88u /* Fat Burn Heart Rate Lower Limit     */, 0x00010A04u /* rd,wr  */, 0x003Du, {{0x0001u, (void *)&cyBle_attValuesLen[28]}} },
    { 0x003Eu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x003Fu, {{0x2A89u, NULL}}                           },
    { 0x003Fu, 0x2A89u /* Fat Burn Heart Rate Upper Limit     */, 0x00010A04u /* rd,wr  */, 0x003Fu, {{0x0001u, (void *)&cyBle_attValuesLen[29]}} },
    { 0x0040u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0041u, {{0x2A7Eu, NULL}}                           },
    { 0x0041u, 0x2A7Eu /* Aerobic Heart Rate Lower Limit      */, 0x00010A04u /* rd,wr  */, 0x0041u, {{0x0001u, (void *)&cyBle_attValuesLen[30]}} },
    { 0x0042u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0043u, {{0x2A84u, NULL}}                           },
    { 0x0043u, 0x2A84u /* Aerobic Heart Rate Upper Limit      */, 0x00010A04u /* rd,wr  */, 0x0043u, {{0x0001u, (void *)&cyBle_attValuesLen[31]}} },
    { 0x0044u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0045u, {{0x2A81u, NULL}}                           },
    { 0x0045u, 0x2A81u /* Anaerobic Heart Rate Lower Limit    */, 0x00010A04u /* rd,wr  */, 0x0045u, {{0x0001u, (void *)&cyBle_attValuesLen[32]}} },
    { 0x0046u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0047u, {{0x2A82u, NULL}}                           },
    { 0x0047u, 0x2A82u /* Anaerobic Heart Rate Upper Limit    */, 0x00010A04u /* rd,wr  */, 0x0047u, {{0x0001u, (void *)&cyBle_attValuesLen[33]}} },
    { 0x0048u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0049u, {{0x2A8Bu, NULL}}                           },
    { 0x0049u, 0x2A8Bu /* Five Zone Heart Rate Limits         */, 0x00010A04u /* rd,wr  */, 0x0049u, {{0x0004u, (void *)&cyBle_attValuesLen[34]}} },
    { 0x004Au, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x004Bu, {{0x2A94u, NULL}}                           },
    { 0x004Bu, 0x2A94u /* Three Zone Heart Rate Limits        */, 0x00010A04u /* rd,wr  */, 0x004Bu, {{0x0002u, (void *)&cyBle_attValuesLen[35]}} },
    { 0x004Cu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x004Du, {{0x2A95u, NULL}}                           },
    { 0x004Du, 0x2A95u /* Two Zone Heart Rate Limit           */, 0x00010A04u /* rd,wr  */, 0x004Du, {{0x0001u, (void *)&cyBle_attValuesLen[36]}} },
    { 0x004Eu, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0050u, {{0x2A99u, NULL}}                           },
    { 0x004Fu, 0x2A99u /* Database Change Increment           */, 0x00000A04u /* rd,wr  */, 0x0050u, {{0x0004u, (void *)&cyBle_attValuesLen[37]}} },
    { 0x0050u, 0x2902u /* Client Characteristic Configuration */, 0x00000A04u /* rd,wr  */, 0x0050u, {{0x0002u, (void *)&cyBle_attValuesLen[38]}} },
    { 0x0051u, 0x2803u /* Characteristic                      */, 0x00000201u /* rd     */, 0x0052u, {{0x2A9Au, NULL}}                           },
    { 0x0052u, 0x2A9Au /* User Index                          */, 0x00000201u /* rd     */, 0x0052u, {{0x0001u, (void *)&cyBle_attValuesLen[39]}} },
    { 0x0053u, 0x2803u /* Characteristic                      */, 0x00002801u /* wr,ind */, 0x0055u, {{0x2A9Fu, NULL}}                           },
    { 0x0054u, 0x2A9Fu /* User Control Point                  */, 0x00002802u /* wr,ind */, 0x0055u, {{0x0002u, (void *)&cyBle_attValuesLen[40]}} },
    { 0x0055u, 0x2902u /* Client Characteristic Configuration */, 0x00000A04u /* rd,wr  */, 0x0055u, {{0x0002u, (void *)&cyBle_attValuesLen[41]}} },
    { 0x0056u, 0x2803u /* Characteristic                      */, 0x00000A01u /* rd,wr  */, 0x0057u, {{0x2AA2u, NULL}}                           },
    { 0x0057u, 0x2AA2u /* Language                            */, 0x00010A04u /* rd,wr  */, 0x0057u, {{0x0000u, (void *)&cyBle_attValuesLen[42]}} },
};


#endif /* (CYBLE_GATT_ROLE_SERVER) */

#if(CYBLE_GATT_ROLE_CLIENT)
    
CYBLE_CLIENT_STATE_T cyBle_clientState;
CYBLE_GATTC_T cyBle_gattc;
CYBLE_GATT_ATTR_HANDLE_RANGE_T cyBle_gattcDiscoveryRange;
    
#endif /* (CYBLE_GATT_ROLE_CLIENT) */


#if(CYBLE_GATT_ROLE_SERVER)

/****************************************************************************** 
* Function Name: CyBle_GattsReInitGattDb
***************************************************************************//**
* 
*  Reinitializes the GATT database.
* 
*  \return
*  CYBLE_API_RESULT_T: An API result states if the API succeeded or failed with
*  error codes:

*  Errors codes                          | Description
*  ------------                          | -----------
*  CYBLE_ERROR_OK						 | GATT database was reinitialized successfully.
*  CYBLE_ERROR_INVALID_STATE             | If the function is called in any state except CYBLE_STATE_DISCONNECTED.
*  CYBLE_ERROR_INVALID_PARAMETER         | If the Database has zero entries or is a NULL pointer.
* 
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattsReInitGattDb(void)
{
    CYBLE_API_RESULT_T apiResult;
    
    if(CYBLE_STATE_DISCONNECTED == CyBle_GetState())
    {
        apiResult = CyBle_GattsDbRegister(cyBle_gattDB, CYBLE_GATT_DB_INDEX_COUNT, CYBLE_GATT_DB_MAX_VALUE_LEN);
    }
    else
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    
    return(apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_GattsWriteEventHandler
***************************************************************************//**
* 
*  Handles the Write Request Event for GATT service.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
*  \return
*  CYBLE_GATT_ERR_CODE_T: An API result returns one of the following status 
*  values.

*  Errors codes                          | Description
*  --------------------                  | -----------
*  CYBLE_GATT_ERR_NONE                   | Write is successful.
* 
******************************************************************************/
CYBLE_GATT_ERR_CODE_T CyBle_GattsWriteEventHandler(CYBLE_GATTS_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_GATT_ERR_CODE_T gattErr = CYBLE_GATT_ERR_NONE;
    
    /* Client Characteristic Configuration descriptor write request */
    if(eventParam->handleValPair.attrHandle == cyBle_gatts.cccdHandle)
    {
        /* Store value to database */
        gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair, 0u, 
                        &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
        
        if(CYBLE_GATT_ERR_NONE == gattErr)
        {
            if(CYBLE_IS_INDICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
            {
                CyBle_ApplCallback((uint32)CYBLE_EVT_GATTS_INDICATION_ENABLED, eventParam);
            }
            else
            {
                CyBle_ApplCallback((uint32)CYBLE_EVT_GATTS_INDICATION_DISABLED, eventParam);
            }
        }
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
    return (gattErr);
}


#endif /* (CYBLE_GATT_ROLE_SERVER) */

#if(CYBLE_GATT_ROLE_CLIENT)


/****************************************************************************** 
* Function Name: CyBle_GattcStartDiscovery
***************************************************************************//**
* 
*  Starts the automatic server discovery process. Two events may be generated 
*  after calling this function - CYBLE_EVT_GATTC_DISCOVERY_COMPLETE or 
*  CYBLE_EVT_GATTC_ERROR_RSP. The CYBLE_EVT_GATTC_DISCOVERY_COMPLETE event is 
*  generated when the remote device was successfully discovered. The
*  CYBLE_EVT_GATTC_ERROR_RSP is generated if the device discovery is failed.
* 
*  \param connHandle: The handle which consists of the device ID and ATT connection ID.
* 
* \return
*	CYBLE_API_RESULT_T : Return value indicates if the function succeeded or
*                        failed. Following are the possible error codes.
*
*   <table>	
*   <tr>
*	  <th>Errors codes</th>
*	  <th>Description</th>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_OK</td>
*	  <td>On successful operation</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_PARAMETER</td>
*	  <td>'connHandle' value does not represent any existing entry.</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_OPERATION</td>
*	  <td>The operation is not permitted</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_MEMORY_ALLOCATION_FAILED</td>
*	  <td>Memory allocation failed</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_INVALID_STATE</td>
*	  <td>If the function is called in any state except connected or discovered</td>
*	</tr>
*   </table>
* 
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattcStartDiscovery(CYBLE_CONN_HANDLE_T connHandle)
{
    uint8 j;
    CYBLE_API_RESULT_T apiResult;
    
    if((CyBle_GetState() != CYBLE_STATE_CONNECTED) || 
       ((CyBle_GetClientState() != CYBLE_CLIENT_STATE_CONNECTED) && 
        (CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED))) 
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else
    {
        /* Clean old discovery information */
        for(j = 0u; j < (uint8) CYBLE_SRVI_COUNT; j++)
        {
            (void)memset(&cyBle_serverInfo[j].range, 0, sizeof(cyBle_serverInfo[0].range));
        }

        cyBle_connHandle = connHandle;
        cyBle_gattcDiscoveryRange.startHandle = CYBLE_GATT_ATTR_HANDLE_START_RANGE;
        cyBle_gattcDiscoveryRange.endHandle = CYBLE_GATT_ATTR_HANDLE_END_RANGE;
        
        CyBle_ServiceInit();
        
        apiResult = CyBle_GattcDiscoverAllPrimaryServices(connHandle);

        if(CYBLE_ERROR_OK == apiResult)
        {
            CyBle_SetClientState(CYBLE_CLIENT_STATE_SRVC_DISCOVERING);
            cyBle_eventHandlerFlag |= CYBLE_AUTO_DISCOVERY;
        }
    }
    
    return (apiResult);
}


/****************************************************************************** 
* Function Name: CyBle_GattcStartPartialDiscovery
***************************************************************************//**
* 
*  Starts the automatic server discovery process as per the range provided
*  on a GATT Server to which it is connected. This API could be used for 
*  partial server discovery after indication received to the Service Changed
*  Characteristic Value. Two events may be generated 
*  after calling this function - CYBLE_EVT_GATTC_DISCOVERY_COMPLETE or 
*  CYBLE_EVT_GATTC_ERROR_RSP. The CYBLE_EVT_GATTC_DISCOVERY_COMPLETE event is 
*  generated when the remote device was successfully discovered. The
*  CYBLE_EVT_GATTC_ERROR_RSP is generated if the device discovery is failed.
* 
*  \param connHandle: The handle which consists of the device ID and ATT connection ID.
*  \param startHandle: Start of affected attribute handle range.
*  \param endHandle: End of affected attribute handle range.
* 
*  \return
*	CYBLE_API_RESULT_T : Return value indicates if the function succeeded or
*                        failed. Following are the possible error codes.
*
*   <table>	
*   <tr>
*	  <th>Errors codes</th>
*	  <th>Description</th>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_OK</td>
*	  <td>On successful operation</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_PARAMETER</td>
*	  <td>'connHandle' value does not represent any existing entry.</td>
*	</tr>
*	<tr>
*	  <td>CYBLE_ERROR_INVALID_OPERATION</td>
*	  <td>The operation is not permitted</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_MEMORY_ALLOCATION_FAILED</td>
*	  <td>Memory allocation failed</td>
*	</tr>
*   <tr>
*	  <td>CYBLE_ERROR_INVALID_STATE</td>
*	  <td>If the function is called in any state except connected or discovered</td>
*	</tr>
*   </table>
* 
******************************************************************************/
CYBLE_API_RESULT_T CyBle_GattcStartPartialDiscovery(CYBLE_CONN_HANDLE_T connHandle,
                        CYBLE_GATT_DB_ATTR_HANDLE_T startHandle, CYBLE_GATT_DB_ATTR_HANDLE_T endHandle)
{
    uint8 j;
    CYBLE_API_RESULT_T apiResult;
    
    if((CyBle_GetState() != CYBLE_STATE_CONNECTED) || 
       ((CyBle_GetClientState() != CYBLE_CLIENT_STATE_CONNECTED) && 
        (CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED))) 
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else
    {
        /* Clean old discovery information of affected attribute range */
        for(j = 0u; j < (uint8) CYBLE_SRVI_COUNT; j++)
        {
            if((cyBle_serverInfo[j].range.startHandle >= startHandle) &&
               (cyBle_serverInfo[j].range.startHandle <= endHandle))
            {
                (void)memset(&cyBle_serverInfo[j].range, 0, sizeof(cyBle_serverInfo[0].range));
            }
        }

        cyBle_connHandle = connHandle;
        cyBle_gattcDiscoveryRange.startHandle = startHandle;
        cyBle_gattcDiscoveryRange.endHandle = endHandle;

        CyBle_ServiceInit();

        apiResult = CyBle_GattcDiscoverPrimaryServices(connHandle, &cyBle_gattcDiscoveryRange);

        if(CYBLE_ERROR_OK == apiResult)
        {
            CyBle_SetClientState(CYBLE_CLIENT_STATE_SRVC_DISCOVERING);
            cyBle_eventHandlerFlag |= CYBLE_AUTO_DISCOVERY;
        }
    }
    
    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_GattcDiscoverCharacteristicsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a "CYBLE_EVT_GATTC_READ_BY_TYPE_RSP"
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param *discCharInfo: The pointer to a characteristic information structure.
* 
* \return
*  None
* 
******************************************************************************/
void CyBle_GattcDiscoverCharacteristicsEventHandler(CYBLE_DISC_CHAR_INFO_T *discCharInfo)
{
    if(discCharInfo->uuid.uuid16 == CYBLE_UUID_CHAR_SERVICE_CHANGED)
    {
        CyBle_CheckStoreCharHandle(cyBle_gattc.serviceChanged);
    }
}


/******************************************************************************
* Function Name: CyBle_GattcDiscoverCharDescriptorsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a "CYBLE_EVT_GATTC_FIND_INFO_RSP" event.
*  Based on the descriptor UUID, an appropriate data structure is populated 
*  using the data received as part of the callback.
* 
*  \param *discDescrInfo: The pointer to a descriptor information structure.
*  \param discoveryService: The index of the service instance
* 
* \return
*  None
* 
******************************************************************************/
void CyBle_GattcDiscoverCharDescriptorsEventHandler(CYBLE_DISC_DESCR_INFO_T *discDescrInfo)
{
    if(discDescrInfo->uuid.uuid16 == CYBLE_UUID_CHAR_CLIENT_CONFIG)
    {
        CyBle_CheckStoreCharDescrHandle(cyBle_gattc.cccdHandle);
    }
}


/******************************************************************************
* Function Name: CyBle_GattcIndicationEventHandler
***************************************************************************//**
* 
*  Handles the Indication Event.
* 
*  \param *eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_GattcIndicationEventHandler(CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T *eventParam)
{
    if(cyBle_gattc.serviceChanged.valueHandle == eventParam->handleValPair.attrHandle)
    {
        CyBle_ApplCallback((uint32)CYBLE_EVT_GATTC_INDICATION, eventParam);
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
    }
}


#endif /* (CYBLE_GATT_ROLE_CLIENT) */


/* [] END OF FILE */
