/***************************************************************************//**
* \file CYBLE_uds.c
* \version 3.10
* 
* \brief
*  This file contains the source code for
*  the User Data Service of the BLE Component.
* 
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#include "CYBLE_eventHandler.h"

static CYBLE_CALLBACK_T CyBle_UdsApplCallback;

#ifdef CYBLE_UDS_SERVER
/* Generated code */
const CYBLE_UDSS_T cyBle_udss =
{
    0x0017u,    /* Handle of the UDS service */
    {
        
        /* First Name characteristic */
        {
            0x0019u, /* Handle of the First Name characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Last Name characteristic */
        {
            0x001Bu, /* Handle of the Last Name characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Email Address characteristic */
        {
            0x001Du, /* Handle of the Email Address characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Age characteristic */
        {
            0x001Fu, /* Handle of the Age characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Date of Birth characteristic */
        {
            0x0021u, /* Handle of the Date of Birth characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Gender characteristic */
        {
            0x0023u, /* Handle of the Gender characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Weight characteristic */
        {
            0x0025u, /* Handle of the Weight characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Height characteristic */
        {
            0x0027u, /* Handle of the Height characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* VO2 Max characteristic */
        {
            0x0029u, /* Handle of the VO2 Max characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Heart Rate Max characteristic */
        {
            0x002Bu, /* Handle of the Heart Rate Max characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Resting Heart Rate characteristic */
        {
            0x002Du, /* Handle of the Resting Heart Rate characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Maximum Recommended Heart Rate characteristic */
        {
            0x002Fu, /* Handle of the Maximum Recommended Heart Rate characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Aerobic Threshold characteristic */
        {
            0x0031u, /* Handle of the Aerobic Threshold characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Anaerobic Threshold characteristic */
        {
            0x0033u, /* Handle of the Anaerobic Threshold characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Sport Type for Aerobic and Anaerobic Thresholds characteristic */
        {
            0x0035u, /* Handle of the Sport Type for Aerobic and Anaerobic Thresholds characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Date of Threshold Assessment characteristic */
        {
            0x0037u, /* Handle of the Date of Threshold Assessment characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Waist Circumference characteristic */
        {
            0x0039u, /* Handle of the Waist Circumference characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Hip Circumference characteristic */
        {
            0x003Bu, /* Handle of the Hip Circumference characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Fat Burn Heart Rate Lower Limit characteristic */
        {
            0x003Du, /* Handle of the Fat Burn Heart Rate Lower Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Fat Burn Heart Rate Upper Limit characteristic */
        {
            0x003Fu, /* Handle of the Fat Burn Heart Rate Upper Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Aerobic Heart Rate Lower Limit characteristic */
        {
            0x0041u, /* Handle of the Aerobic Heart Rate Lower Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Aerobic Heart Rate Upper Limit characteristic */
        {
            0x0043u, /* Handle of the Aerobic Heart Rate Upper Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Anaerobic Heart Rate Lower Limit characteristic */
        {
            0x0045u, /* Handle of the Anaerobic Heart Rate Lower Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Anaerobic Heart Rate Upper Limit characteristic */
        {
            0x0047u, /* Handle of the Anaerobic Heart Rate Upper Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Five Zone Heart Rate Limits characteristic */
        {
            0x0049u, /* Handle of the Five Zone Heart Rate Limits characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Three Zone Heart Rate Limits characteristic */
        {
            0x004Bu, /* Handle of the Three Zone Heart Rate Limits characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Two Zone Heart Rate Limit characteristic */
        {
            0x004Du, /* Handle of the Two Zone Heart Rate Limit characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* Database Change Increment characteristic */
        {
            0x004Fu, /* Handle of the Database Change Increment characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0050u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* User Index characteristic */
        {
            0x0052u, /* Handle of the User Index characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
        
        /* User Control Point characteristic */
        {
            0x0054u, /* Handle of the User Control Point characteristic */ 
            
            /* Array of Descriptors handles */
            {
                0x0055u, /* Handle of the Client Characteristic Configuration descriptor */ 
            }, 
        }, 
        
        /* Language characteristic */
        {
            0x0057u, /* Handle of the Language characteristic */ 
            
            /* Array of Descriptors handles */
            {
                CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE, 
            }, 
        }, 
    },
};
/* End of generated code */
    uint8 cyBle_udsFlag;
    
static CYBLE_GATT_DB_ATTR_HANDLE_T cyBle_udssReqHandle;

#endif /* CYBLE_UDS_SERVER */

#ifdef CYBLE_UDS_CLIENT
    
/* Server's User Data Service characteristics GATT DB handles structure */
CYBLE_UDSC_T cyBle_udsc;

/* Internal storage for last request handle to check response */
static CYBLE_GATT_DB_ATTR_HANDLE_T cyBle_udscReqHandle;
    
/* Read Long Descriptors variables */
static uint8 * cyBle_udscRdLongBuffPtr = NULL;
static uint8 cyBle_udscRdLongBuffLen = 0u;
static uint8 cyBle_udscCurrLen = 0u;
    
#endif /* CYBLE_UDS_CLIENT */


/******************************************************************************
* Function Name: CyBle_UdsInit
***************************************************************************//**
* 
*  Initializes the profile internals.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdsInit(void)
{
#ifdef CYBLE_UDS_SERVER
    cyBle_udsFlag = 0u;
    cyBle_udssReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
#endif /* CYBLE_UDS_SERVER */
#ifdef CYBLE_UDS_CLIENT
    if(cyBle_serverInfo[CYBLE_SRVI_UDS].range.startHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        (void)memset(&cyBle_udsc, 0, sizeof(cyBle_udsc));
    }
    cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
#endif /* CYBLE_UDS_CLIENT */
}


/******************************************************************************
* Function Name: CyBle_UdsRegisterAttrCallback
***************************************************************************//**
* 
*  Registers a callback function for service-specific attribute operations.
*  Service-specific write requests from a peer device will not be handled with
*  an unregistered callback function.
* 
*  \param callbackFunc: An application layer event callback function to receive 
*                        events from the BLE Component. The definition of 
*                        CYBLE_CALLBACK_T for UDS is: \n
*    typedef void (* CYBLE_CALLBACK_T) (uint32 eventCode, void *eventParam),
*    where:
*      * eventCode indicates the event that triggered this callback.
*      * eventParam contains the parameters corresponding to the current event.
*
* \return
*  None.
*
* \events
*  None.
*
* \sideeffect
*  The *eventParams in the callback function should not be used by the 
*  application once the callback function execution is finished. Otherwise this
*  data may become corrupted.
*  
******************************************************************************/
void CyBle_UdsRegisterAttrCallback(CYBLE_CALLBACK_T callbackFunc)
{
    CyBle_UdsApplCallback = callbackFunc;
}


#ifdef CYBLE_UDS_SERVER


/******************************************************************************
* Function Name: CyBle_UdssSetCharacteristicValue
***************************************************************************//**
* 
*  Sets the value of the characteristic, as identified by charIndex.
* 
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data that should be
*                     stored to the GATT database.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request handled successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent
*
* \events
*  None
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdssSetCharacteristicValue(CYBLE_UDS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udss.charInfo[charIndex].charHandle)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    } 
    else
    {
        CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;
        
        /* Store characteristic value into GATT database */
        locHandleValuePair.attrHandle = cyBle_udss.charInfo[charIndex].charHandle;
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        
        if(CYBLE_GATT_ERR_NONE != CyBle_GattsWriteAttributeValue(&locHandleValuePair,
                                    0u, NULL, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
        else
        {
            apiResult = CYBLE_ERROR_OK;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdssGetCharacteristicValue
***************************************************************************//**
* 
*  Gets the value of the characteristic, as identified by charIndex.
* 
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue: The pointer to the location where characteristic 
*                     value data should be stored.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - The characteristic value was read successfully
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this characteristic.
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - A characteristic is absent.
*
* \events
*  None.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdssGetCharacteristicValue(CYBLE_UDS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udss.charInfo[charIndex].charHandle)
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else
    {
        CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;
        
        /* Get characteristic value from GATT database */
        locHandleValuePair.attrHandle = cyBle_udss.charInfo[charIndex].charHandle;
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;
        
        if(CYBLE_GATT_ERR_NONE != CyBle_GattsReadAttributeValue(&locHandleValuePair,
                                    0u, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
        else
        {
            apiResult = CYBLE_ERROR_OK;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdssGetCharacteristicDescriptor
***************************************************************************//**
* 
*  Gets a characteristic descriptor of the specified characteristic.
* 
*  \param charIndex:  The index of the characteristic.
*  \param descrIndex: The index of the descriptor.
*  \param attrSize:   The size of the descriptor value attribute.
*  \param attrValue: The pointer to the location where characteristic descriptor value 
*                     data should be stored. 
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - Characteristic Descriptor value was read successfully
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - A characteristic is absent.
*
* \events
*  None.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdssGetCharacteristicDescriptor(CYBLE_UDS_CHAR_INDEX_T charIndex, 
                                                         CYBLE_UDS_DESCR_INDEX_T descrIndex,
                                                         uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if((charIndex >= CYBLE_UDS_CHAR_COUNT) || (descrIndex >= CYBLE_UDS_DESCR_COUNT))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udss.charInfo[charIndex].descrHandle[CYBLE_UDS_CCCD])
    {
        apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
    }
    else
    {
        CYBLE_GATT_HANDLE_VALUE_PAIR_T locHandleValuePair;
        
        /* Get data from database */
        locHandleValuePair.attrHandle = cyBle_udss.charInfo[charIndex].descrHandle[descrIndex];
        locHandleValuePair.value.len = attrSize;
        locHandleValuePair.value.val = attrValue;

        if(CYBLE_GATT_ERR_NONE != CyBle_GattsReadAttributeValue(&locHandleValuePair,
                                    0u, CYBLE_GATT_DB_LOCALLY_INITIATED))
        {
            apiResult = CYBLE_ERROR_INVALID_PARAMETER;
        }
        else
        {
            apiResult = CYBLE_ERROR_OK;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdssSendNotification
***************************************************************************//**
* 
*  Sends a notification of the specified characteristic value, as identified by
*  the charIndex.
* 
*  \param connHandle: The connection handle which consist of the device ID and ATT 
*                     connection ID.
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data
*                     that should be sent to the client device. 
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - The request handled successfully.
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                     characteristic
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.
*   * CYBLE_ERROR_INVALID_STATE - Connection with the client is not established.
*   * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*   * CYBLE_ERROR_NTF_DISABLED - Notification is not enabled by the client.
*
* \events
*  None.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdssSendNotification(CYBLE_CONN_HANDLE_T connHandle,
                    CYBLE_UDS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Send Notification if it is enabled and connected */
    if(CYBLE_STATE_CONNECTED != CyBle_GetState())
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udss.charInfo[charIndex].descrHandle[CYBLE_UDS_CCCD])
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if(!CYBLE_IS_NOTIFICATION_ENABLED(cyBle_udss.charInfo[charIndex].descrHandle[CYBLE_UDS_CCCD]))
    {
        apiResult = CYBLE_ERROR_NTF_DISABLED;
    }
    else
    {
        CYBLE_GATTS_HANDLE_VALUE_NTF_T ntfParam;
        
        /* Fill all fields of write request structure ... */
        ntfParam.attrHandle = cyBle_udss.charInfo[charIndex].charHandle; 
        ntfParam.value.val = attrValue;
        ntfParam.value.len = attrSize;
        
        /* Send notification to client using previously filled structure */
        apiResult = CyBle_GattsNotification(connHandle, &ntfParam);
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdssSendIndication
***************************************************************************//**
* 
*  Sends an indication of the specified characteristic value, as identified by
*  the charIndex.
* 
*  \param connHandle: The connection handle which consist of the device ID and ATT 
*                     connection ID.
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data that should be sent 
*                     to the client device.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*   * CYBLE_ERROR_OK - The request handled successfully.
*   * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameter failed.
*   * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                      characteristic.
*   * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - An optional characteristic is absent.
*   * CYBLE_ERROR_INVALID_STATE - Connection with the client is not established.
*   * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*   * CYBLE_ERROR_NTF_DISABLED - Notification is not enabled by the client.
*   * CYBLE_ERROR_IND_DISABLED - Indication is disabled for this characteristic.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSS_INDICATION_CONFIRMED - If the indication is
*                                successfully delivered to the peer device.
*  .
*   Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTS_HANDLE_VALUE_CNF - If the indication is
*                                successfully delivered to the peer device.
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdssSendIndication(CYBLE_CONN_HANDLE_T connHandle,
                    CYBLE_UDS_CHAR_INDEX_T charIndex, uint8 attrSize, uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Send Indication if it is enabled and connected */
    if(CYBLE_STATE_CONNECTED != CyBle_GetState())
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udss.charInfo[charIndex].descrHandle[CYBLE_UDS_CCCD])
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if(!CYBLE_IS_INDICATION_ENABLED(cyBle_udss.charInfo[charIndex].descrHandle[CYBLE_UDS_CCCD]))
    {
        apiResult = CYBLE_ERROR_IND_DISABLED;
    }
    else
    {
        CYBLE_GATTS_HANDLE_VALUE_IND_T indParam;
        
        /* Fill all fields of write request structure ... */
        indParam.attrHandle = cyBle_udss.charInfo[charIndex].charHandle; 
        indParam.value.val = attrValue;
        indParam.value.len = attrSize;
        
        /* Send notification to client using previously filled structure */
        apiResult = CyBle_GattsIndication(connHandle, &indParam);
        
        if(CYBLE_ERROR_OK == apiResult)
        {
            /* Save handle to support service specific value confirmation response from client */
            cyBle_udssReqHandle = indParam.attrHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdssConfirmationEventHandler
***************************************************************************//**
* 
*  Handles the Value Confirmation request event from the BLE stack.
* 
*  \param eventParam: The pointer to a structure of type CYBLE_CONN_HANDLE_T.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdssConfirmationEventHandler(const CYBLE_CONN_HANDLE_T *eventParam)
{
    if((NULL != CyBle_UdsApplCallback) 
        && (cyBle_udss.charInfo[CYBLE_UDS_UCP].charHandle == cyBle_udssReqHandle))
    {   
        CYBLE_UDS_CHAR_VALUE_T locCharIndex;
        
        cyBle_udssReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
        
        cyBle_udsFlag &= (uint8) ~CYBLE_UDS_FLAG_PROCESS;
        
        locCharIndex.connHandle = *eventParam;
        locCharIndex.charIndex = CYBLE_UDS_UCP;
        locCharIndex.value = NULL;
        
        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
        CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSS_INDICATION_CONFIRMED, &locCharIndex);
    }
}


/******************************************************************************
* Function Name: CyBle_UdssReadRequestEventHandler
***************************************************************************//**
* 
*  Handles the Read Request Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdssReadRequestEventHandler(CYBLE_GATTS_CHAR_VAL_READ_REQ_T *eventParam)
{
    if(CyBle_UdsApplCallback != NULL)
    {
        CYBLE_UDS_CHAR_VALUE_T locCharValue;
        locCharValue.connHandle = eventParam->connHandle;
        locCharValue.gattErrorCode = CYBLE_GATT_ERR_NONE;
        locCharValue.value = NULL;
    
        for(locCharValue.charIndex = CYBLE_UDS_FNM; 
            locCharValue.charIndex < CYBLE_UDS_CHAR_COUNT; 
            locCharValue.charIndex++)
        {
            if(locCharValue.charIndex == CYBLE_UDS_UCP)
            {
                /* Omit UCP characteristic */
                locCharValue.charIndex = CYBLE_UDS_LNG;
            }
            
            if(eventParam->attrHandle == cyBle_udss.charInfo[locCharValue.charIndex].charHandle)
            {

                CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSS_READ_CHAR, &locCharValue);
                        
                if(locCharValue.gattErrorCode == CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED)
	            {
                    eventParam->gattErrorCode = CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED;
                }
                
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                break;
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdssWriteEventHandler
***************************************************************************//**
* 
*  Handles the Write Request Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  CYBLE_GATT_ERR_CODE_T - An API result state if the API succeeded
*  (CYBLE_GATT_ERR_NONE) or failed with error codes:
*   * CYBLE_GATTS_ERR_PROCEDURE_ALREADY_IN_PROGRESS
*   * CYBLE_GATTS_ERR_CCCD_IMPROPERLY_CONFIGURED
* 
******************************************************************************/
CYBLE_GATT_ERR_CODE_T CyBle_UdssWriteEventHandler(CYBLE_GATTS_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_GATT_ERR_CODE_T gattErr = CYBLE_GATT_ERR_NONE;
    
    if(NULL != CyBle_UdsApplCallback)
    {
	    CYBLE_UDS_CHAR_VALUE_T locCharValue;
        locCharValue.connHandle = eventParam->connHandle;
        locCharValue.gattErrorCode = CYBLE_GATT_ERR_NONE;
	
	    if((eventParam->handleValPair.attrHandle == cyBle_udss.charInfo[CYBLE_UDS_DCI].descrHandle[CYBLE_UDS_CCCD]) ||
           (eventParam->handleValPair.attrHandle == cyBle_udss.charInfo[CYBLE_UDS_UCP].descrHandle[CYBLE_UDS_CCCD]))
	    {
            locCharValue.value = NULL;
            gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair,
                         0u, &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
            
            if(CYBLE_GATT_ERR_NONE == gattErr)
            {
                uint32 eventCode;
                
                if(eventParam->handleValPair.attrHandle == cyBle_udss.charInfo[CYBLE_UDS_DCI].descrHandle[CYBLE_UDS_CCCD])
                {
                    locCharValue.charIndex = CYBLE_UDS_DCI;
                    
                    if(CYBLE_IS_NOTIFICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
                    {
                        eventCode = (uint32) CYBLE_EVT_UDSS_NOTIFICATION_ENABLED;
                    }
                    else
                    {
                        eventCode = (uint32) CYBLE_EVT_UDSS_NOTIFICATION_DISABLED;
                    }
                }
                else
                {
                    locCharValue.charIndex = CYBLE_UDS_UCP;
                    
                    if(CYBLE_IS_INDICATION_ENABLED_IN_PTR(eventParam->handleValPair.value.val))
                    {
                        eventCode = (uint32) CYBLE_EVT_UDSS_INDICATION_ENABLED;
                    }
                    else
                    {
                        eventCode = (uint32) CYBLE_EVT_UDSS_INDICATION_DISABLED;
                    }
                }
                
                CyBle_UdsApplCallback(eventCode, &locCharValue);
            }

        #if((CYBLE_GAP_ROLE_PERIPHERAL || CYBLE_GAP_ROLE_CENTRAL) && \
            (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES))
            /* Set flag to store bonding data to flash */
            if(cyBle_peerBonding == CYBLE_GAP_BONDING)
            {
                cyBle_pendingFlashWrite |= CYBLE_PENDING_CCCD_FLASH_WRITE_BIT;
            }
        #endif /* (CYBLE_BONDING_REQUIREMENT == CYBLE_BONDING_YES) */
			    
            cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
        }
	    else
        {
            for(locCharValue.charIndex = CYBLE_UDS_FNM; 
                locCharValue.charIndex < CYBLE_UDS_CHAR_COUNT; 
                locCharValue.charIndex++)
	        {
                if(eventParam->handleValPair.attrHandle == cyBle_udss.charInfo[locCharValue.charIndex].charHandle)
	            {
	                gattErr = CyBle_GattDbCheckPermission(eventParam->handleValPair.attrHandle, 
                                                         &eventParam->connHandle,
                                                         CYBLE_GATT_DB_WRITE | CYBLE_GATT_DB_PEER_INITIATED);
                    
                    if((gattErr == CYBLE_GATT_ERR_NONE) && (locCharValue.charIndex == CYBLE_UDS_UCP))
                    {
                        if(CYBLE_UDS_IS_PROCEDURE_IN_PROGRESS)
                        {
                            gattErr = CYBLE_GATT_ERR_PROCEDURE_ALREADY_IN_PROGRESS;
                        }
                        else if(!CYBLE_IS_INDICATION_ENABLED(cyBle_udss.charInfo[CYBLE_UDS_UCP].
                                                                     descrHandle[CYBLE_UDS_CCCD]))
                        {
                            gattErr = CYBLE_GATT_ERR_CCCD_IMPROPERLY_CONFIGURED;
                        }
                        else
                        {
                        }
                    }
                    
                    if(gattErr == CYBLE_GATT_ERR_NONE)
                    {
                        locCharValue.value = &eventParam->handleValPair.value;
                        
                        if(!CYBLE_GATT_DB_ATTR_CHECK_PRPTY(eventParam->handleValPair.attrHandle, CYBLE_GATT_DB_CH_PROP_WRITE))
                        {
                            gattErr = CYBLE_GATT_ERR_WRITE_NOT_PERMITTED;
                        }
                        else if(eventParam->handleValPair.value.len > CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_MAX_LEN(eventParam->handleValPair.attrHandle))
                        {
                            gattErr = CYBLE_GATT_ERR_INVALID_ATTRIBUTE_LEN;   
                        }
                        else
                        {
                            CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSS_WRITE_CHAR, &locCharValue);
                            
                            if(locCharValue.gattErrorCode == CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED)
            	            {
                                gattErr = CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED;
                            }
                            else
                            {
                                gattErr = CyBle_GattsWriteAttributeValue(&eventParam->handleValPair, 
            	                      0u, &eventParam->connHandle, CYBLE_GATT_DB_PEER_INITIATED);
                    
                                if(gattErr == CYBLE_GATT_ERR_NONE)
                    	        {
                                    CYBLE_GATT_DB_ATTR_SET_ATTR_GEN_LEN
                                        (cyBle_udss.charInfo[locCharValue.charIndex].charHandle,
                                            locCharValue.value->len);
                                    
                                    if(locCharValue.charIndex == CYBLE_UDS_UCP)
                                    {
                                        cyBle_udsFlag |= CYBLE_UDS_FLAG_PROCESS;
                                    }
                    	        }
                            }
                        }
                    }
                    cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                    break;
				}
            }
        }
    }

    return (gattErr);
}

/****************************************************************************** 
* Function Name: CyBle_UdssPrepareWriteEventHandler
***************************************************************************//**
* 
*  Handles the Prepare Write Request Event.
* 
*  \param eventParam: The pointer to the data that comes with a prepare 
*                      write request.
*                                                  
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdssPrepareWriteRequestEventHandler(CYBLE_GATTS_PREP_WRITE_REQ_PARAM_T *eventParam)
{
    CYBLE_UDS_CHAR_INDEX_T locCharIndex;
    uint16 locMtu = CYBLE_GATT_MTU;
    (void) CyBle_GattGetMtuSize(&locMtu);
    
    for(locCharIndex = CYBLE_UDS_FNM; locCharIndex <= CYBLE_UDS_EML; locCharIndex++)
    {
        if(eventParam->baseAddr[eventParam->currentPrepWriteReqCount - 1u].handleValuePair.attrHandle == 
                cyBle_udss.charInfo[locCharIndex].charHandle)
        {
            if(CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_MAX_LEN(cyBle_udss.charInfo[locCharIndex].charHandle) > (locMtu - 3u))
            {   
                #ifdef ATT_QUEUED_WRITE_SUPPORT
                    if(eventParam->currentPrepWriteReqCount == CYBLE_GATTS_FIRST_PREP_WRITE_REQ)
                    {
                        CyBle_GattsPrepWriteReqSupport(CYBLE_GATTS_PREP_WRITE_SUPPORT);
                    }
                #endif /* ATT_QUEUED_WRITE_SUPPORT */
            } 
            else
            {
                eventParam->gattErrorCode = CYBLE_GATT_ERR_ATTRIBUTE_NOT_LONG;
            }
            
            /* Indicate that request was handled */
            cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
            break;
        }
    }
}

/****************************************************************************** 
* Function Name: CyBle_UdssExecuteWriteRequestEventHandler
***************************************************************************//**
* 
*  Handles the Execute Write Request Event.
* 
*  \param eventParam: The pointer to the data that came with a write request.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdssExecuteWriteRequestEventHandler(CYBLE_GATTS_EXEC_WRITE_REQ_T *eventParam)
{
    uint8 locCount;
    CYBLE_UDS_CHAR_VALUE_T locCharValue[CYBLE_UDS_LONG_CHAR_COUNT];
    CYBLE_GATT_VALUE_T locGattValue[CYBLE_UDS_LONG_CHAR_COUNT];
    CYBLE_UDS_CHAR_INDEX_T locCharIndex;
    for(locCharIndex = CYBLE_UDS_FNM; locCharIndex <= CYBLE_UDS_EML; locCharIndex++)
    {
        locGattValue[locCharIndex].len = 0u;
        locGattValue[locCharIndex].val = NULL;
    }
    
    for(locCount = 0u; locCount < eventParam->prepWriteReqCount; locCount++)
    {
        for(locCharIndex = CYBLE_UDS_FNM; locCharIndex <= CYBLE_UDS_EML; locCharIndex++)
        {
            if(eventParam->baseAddr[locCount].handleValuePair.attrHandle ==
                cyBle_udss.charInfo[locCharIndex].charHandle)
            {
                locGattValue[locCharIndex].len = eventParam->baseAddr[locCount].offset + 
                                   eventParam->baseAddr[locCount].handleValuePair.value.len;

                if(locGattValue[locCharIndex].val == NULL)
                {
                    locGattValue[locCharIndex].val = eventParam->baseAddr[locCount].handleValuePair.value.val;
                }
                else if(eventParam->baseAddr[locCount].offset == 0u)
                {
                    /* Case when client wants to rewrite value from beginning */
                    locGattValue[locCharIndex].val = eventParam->baseAddr[locCount].handleValuePair.value.val;
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
    
    for(locCharIndex = CYBLE_UDS_FNM; locCharIndex <= CYBLE_UDS_EML; locCharIndex++)
    {
        if((locGattValue[locCharIndex].len != 0u) &&
           (locGattValue[locCharIndex].len <= 
            CYBLE_GATT_DB_ATTR_GET_ATTR_GEN_MAX_LEN(cyBle_udss.charInfo[locCharIndex].charHandle)))
        {
            /* Check the execWriteFlag before execute or cancel write long operation */
            if(eventParam->execWriteFlag == CYBLE_GATT_EXECUTE_WRITE_EXEC_FLAG)
            {
                locCharValue[locCharIndex].gattErrorCode = CYBLE_GATT_ERR_NONE;
                locCharValue[locCharIndex].connHandle = eventParam->connHandle;
                locCharValue[locCharIndex].charIndex = locCharIndex;
                locCharValue[locCharIndex].value = &locGattValue[locCharIndex];
            
                CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSS_WRITE_CHAR, &locCharValue[locCharIndex]);
                           
                if(locCharValue[locCharIndex].gattErrorCode == CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED)
                {
                    eventParam->gattErrorCode = CYBLE_GATT_ERR_USER_DATA_ACCESS_NOT_PERMITTED;
                }
                else
                {
                    CYBLE_GATT_DB_ATTR_SET_ATTR_GEN_LEN(cyBle_udss.charInfo[locCharIndex].charHandle,
                                                            locGattValue[locCharIndex].len);    
                }
            }
            
            /* Indicate that request was handled */
            cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
        }
    }
}


#endif /* CYBLE_UDS_SERVER */

#ifdef CYBLE_UDS_CLIENT


/******************************************************************************
* Function Name: CyBle_UdscSetCharacteristicValue
***************************************************************************//**
* 
*  This function is used to write the characteristic (which is identified by
*  charIndex) value attribute in the server.
* 
*  The Write Response just confirms the operation success.
* 
*  \param connHandle: The connection handle.
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue: The pointer to the characteristic value data that should be
*                     sent to the server device.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_INVALID_STATE - Connection with the server is not established.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                              the particular characteristic.
*  * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this
*                                    characteristic.
*
* \events
*  In the case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSC_WRITE_CHAR_RESPONSE - If the requested attribute is
*                                successfully written on the peer device,
*                                the details (char index, etc.) are 
*                                provided with an event parameter structure
*                                of type CYBLE_UDS_CHAR_VALUE_T.
*  .
*   Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_WRITE_RSP - If the requested attribute is 
*                                successfully written on the peer device.
*  * CYBLE_EVT_GATTC_ERROR_RSP - If there is some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with an event parameter
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdscSetCharacteristicValue(CYBLE_CONN_HANDLE_T connHandle,
                                                        CYBLE_UDS_CHAR_INDEX_T charIndex,
                                                            uint8 attrSize, uint8 * attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    uint16 locMtu = CYBLE_GATT_MTU;
    (void) CyBle_GattGetMtuSize(&locMtu);
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udsc.charInfo[charIndex].valueHandle)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if(0u == (CYBLE_CHAR_PROP_WRITE & cyBle_udsc.charInfo[charIndex].properties))
    {
        apiResult = CYBLE_ERROR_INVALID_OPERATION;
    }
    else if((locMtu - 3u) < attrSize)
    {
        CYBLE_GATTC_PREP_WRITE_REQ_T prepWriteReqParam;
        
        prepWriteReqParam.handleValuePair.attrHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        prepWriteReqParam.offset = 0u;
        prepWriteReqParam.handleValuePair.value.val = attrValue;
        prepWriteReqParam.handleValuePair.value.len = attrSize;   
        
        apiResult = CyBle_GattcWriteLongCharacteristicValues(connHandle, &prepWriteReqParam);
        
        if(CYBLE_ERROR_OK == apiResult)
        {
            cyBle_udscReqHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        }
    }
    else 
    {
        CYBLE_GATTC_WRITE_REQ_T writeReqParam;
        
        writeReqParam.attrHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        writeReqParam.value.val = attrValue;
        writeReqParam.value.len = attrSize;

        apiResult = CyBle_GattcWriteCharacteristicValue(connHandle, &writeReqParam);
        if(CYBLE_ERROR_OK == apiResult)
        {
            cyBle_udscReqHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdscGetCharacteristicValue
***************************************************************************//**
* 
*  This function is used to read the characteristic Value from a server,
*  as identified by its charIndex
* 
*  The Read Response returns the characteristic Value in the Attribute Value
*  parameter.
* 
*  The Read Response only contains the characteristic Value that is less than or
*  equal to (MTU - 1) octets in length. If the characteristic Value is greater
*  than (MTU - 1) octets in length, the Read Long Characteristic Value procedure
*  may be used if the rest of the characteristic Value is required.
* 
*  \param connHandle: The connection handle.
*  \param charIndex:  The index of the service characteristic.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The read request was sent successfully.  
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                              the particular characteristic.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_INVALID_STATE - Connection with the server is not established.
*  * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                    characteristic.
*
* \events
*  In case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSC_READ_CHAR_RESPONSE - If the requested attribute is
*                                successfully written on the peer device,
*                                the details (char index , value, etc.) are 
*                                provided with an event parameter structure
*                                of type CYBLE_UDS_CHAR_VALUE_T.
*  .
*   Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_READ_RSP - If the requested attribute is 
*                                successfully read on the peer device,
*                                the details (handle, value, etc.) are 
*                                provided with an event parameter
*                                structure (CYBLE_GATTC_READ_RSP_PARAM_T).
*  * CYBLE_EVT_GATTC_ERROR_RSP - If there is some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with an event parameter
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdscGetCharacteristicValue(CYBLE_CONN_HANDLE_T connHandle, CYBLE_UDS_CHAR_INDEX_T charIndex)
{
    CYBLE_API_RESULT_T apiResult;

    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(charIndex >= CYBLE_UDS_CHAR_COUNT)
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udsc.charInfo[charIndex].valueHandle)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if(0u == (CYBLE_CHAR_PROP_READ & cyBle_udsc.charInfo[charIndex].properties))
    {
        apiResult = CYBLE_ERROR_INVALID_OPERATION;
    }
    else
    {
        apiResult = CyBle_GattcReadCharacteristicValue(connHandle, cyBle_udsc.charInfo[charIndex].valueHandle);
    }
    
    if(apiResult == CYBLE_ERROR_OK)
    {
        cyBle_udscReqHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdscGetLongCharacteristicValue
***************************************************************************//**
* 
*  Sends a request to read a long characteristic.
* 
*  \param connHandle: The connection handle.
*  \param charIndex:  The index of the service characteristic.
*  \param attrSize:   The size of the characteristic value attribute.
*  \param attrValue:  The pointer to the buffer where the read long characteristic 
*                     descriptor value should be stored.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The read request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                              the particular characteristic.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_INVALID_STATE - Connection with the server is not established.
*  * CYBLE_ERROR_INVALID_OPERATION - Operation is invalid for this 
*                                    characteristic
*
* \events
*  In the case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSC_READ_CHAR_RESPONSE - If the requested attribute is
*                                successfully written on the peer device,
*                                the details (char index , value, etc.) are 
*                                provided with an event parameter structure
*                                of type CYBLE_UDS_CHAR_VALUE_T.
*  .
*   Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_READ_BLOB_RSP - If the requested attribute is 
*                                successfully read on the peer device,
*                                the details (handle, value, etc.) are 
*                                provided with an event parameter
*                                structure (CYBLE_GATTC_READ_RSP_PARAM_T).
*  * CYBLE_EVT_GATTC_ERROR_RSP - If there is some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with an event parameter
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdscGetLongCharacteristicValue(CYBLE_CONN_HANDLE_T connHandle, 
                                                        CYBLE_UDS_CHAR_INDEX_T charIndex, 
                                                        uint16 attrSize,
                                                        uint8 *attrValue)
{
    CYBLE_API_RESULT_T apiResult;

    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if(((charIndex > CYBLE_UDS_EML) &&
             (charIndex != CYBLE_UDS_LNG)) ||
             (attrSize == 0u) ||
             (attrValue == NULL))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
	else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udsc.charInfo[charIndex].valueHandle)
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else if(0u == (CYBLE_CHAR_PROP_READ & cyBle_udsc.charInfo[charIndex].properties))
    {
        apiResult = CYBLE_ERROR_INVALID_OPERATION;
    }
    else
    {
        CYBLE_GATTC_READ_BLOB_REQ_T	readBlobReqParam;
        readBlobReqParam.attrHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        readBlobReqParam.offset = 0u;
        
        apiResult = CyBle_GattcReadLongCharacteristicValues(connHandle, &readBlobReqParam);
    }
    
    if(apiResult == CYBLE_ERROR_OK)
    {
        cyBle_udscReqHandle = cyBle_udsc.charInfo[charIndex].valueHandle;
        cyBle_udscRdLongBuffLen = attrSize;
        cyBle_udscRdLongBuffPtr = attrValue;
        cyBle_udscCurrLen = 0u;
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdscSetCharacteristicDescriptor
***************************************************************************//**
* 
*  This function is used to write the characteristic Value to the server,
*  as identified by its charIndex.
* 
*  \param connHandle: The connection handle.
*  \param charIndex:  The index of the service characteristic.
*  \param descrIndex: The index of the service characteristic descriptor.
*  \param attrSize:   The size of the characteristic descriptor value attribute.
*  \param attrValue: The pointer to the characteristic descriptor value data that
*                      should be sent to the server device.
*
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_INVALID_STATE - The state is not valid.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                              the particular characteristic.
*  * CYBLE_ERROR_INVALID_OPERATION - This operation is not permitted on 
*                                    the specified attribute
*
* \events
*  In the case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*   If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSC_WRITE_DESCR_RESPONSE - If the requested attribute is
*                                successfully written on the peer device,
*                                the details (char index, descr index etc.) are 
*                                provided with an event parameter structure
*                                of type CYBLE_UDS_DESCR_VALUE_T.
*  .
*   Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_WRITE_RSP - If the requested attribute is 
*                                successfully written on the peer device.
*  * CYBLE_EVT_GATTC_ERROR_RSP - If there is some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with an event parameter
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdscSetCharacteristicDescriptor(CYBLE_CONN_HANDLE_T connHandle,
    CYBLE_UDS_CHAR_INDEX_T charIndex, CYBLE_UDS_DESCR_INDEX_T descrIndex, uint8 attrSize, uint8 * attrValue)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if((charIndex >= CYBLE_UDS_CHAR_COUNT)
         || (descrIndex >= CYBLE_UDS_DESCR_COUNT)
         || (attrSize != CYBLE_CCCD_LEN))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udsc.charInfo[charIndex].descrHandle[descrIndex])
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else
    {
        CYBLE_GATTC_WRITE_REQ_T writeReqParam;
        
        /* Fill all fields of write request structure ... */
        writeReqParam.attrHandle = cyBle_udsc.charInfo[charIndex].descrHandle[descrIndex];
        writeReqParam.value.val = attrValue;
        writeReqParam.value.len = CYBLE_CCCD_LEN;

        /* ... and send request to server device. */
        apiResult = CyBle_GattcWriteCharacteristicDescriptors(connHandle, &writeReqParam);
        if(CYBLE_ERROR_OK == apiResult)
        {
            /* Save handle to support service specific read response from device */
            cyBle_udscReqHandle = writeReqParam.attrHandle;
        }
    }

    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdscGetCharacteristicDescriptor
***************************************************************************//**
* 
*  Gets the characteristic descriptor of the specified characteristic.
* 
*  \param connHandle: The connection handle.
*  \param charIndex:  The index of the service characteristic.
*  \param descrIndex: The index of the service characteristic descriptor.
* 
* \return
*  A return value is of type CYBLE_API_RESULT_T.
*  * CYBLE_ERROR_OK - The request was sent successfully.
*  * CYBLE_ERROR_INVALID_PARAMETER - Validation of the input parameters failed.
*  * CYBLE_ERROR_INVALID_STATE - The state is not valid.
*  * CYBLE_ERROR_MEMORY_ALLOCATION_FAILED - Memory allocation failed.
*  * CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE - The peer device doesn't have
*                                              the particular descriptor.
*  * CYBLE_ERROR_INVALID_OPERATION - This operation is not permitted on 
*                                    the specified attribute.
*
* \events
*  In the case of successful execution (return value = CYBLE_ERROR_OK)
*  the next events can appear: \n
*  If the UDS service-specific callback is registered 
*      (with CyBle_UdsRegisterAttrCallback):
*  * CYBLE_EVT_UDSC_READ_DESCR_RESPONSE - If the requested attribute is
*                                successfully written on the peer device,
*                                the details (char index, descr index, value, etc.) 
*                                are provided with an event parameter structure
*                                of type CYBLE_UDS_DESCR_VALUE_T. 
*  .
*  Otherwise (if the UDS service-specific callback is not registered):
*  * CYBLE_EVT_GATTC_READ_RSP - If the requested attribute is 
*                                successfully read on the peer device,
*                                the details (handle, value, etc.) are 
*                                provided with an event parameter
*                                structure (CYBLE_GATTC_READ_RSP_PARAM_T).
*  * CYBLE_EVT_GATTC_ERROR_RSP - If there is some trouble with the 
*                                requested attribute on the peer device,
*                                the details are provided with an event parameter
*                                structure (CYBLE_GATTC_ERR_RSP_PARAM_T).
*
******************************************************************************/
CYBLE_API_RESULT_T CyBle_UdscGetCharacteristicDescriptor(CYBLE_CONN_HANDLE_T connHandle,
                       CYBLE_UDS_CHAR_INDEX_T charIndex, CYBLE_UDS_DESCR_INDEX_T descrIndex)
{
    CYBLE_API_RESULT_T apiResult;
    
    /* Check parameters */
    if(CyBle_GetClientState() != CYBLE_CLIENT_STATE_DISCOVERED)
    {
        apiResult = CYBLE_ERROR_INVALID_STATE;
    }
    else if((charIndex >= CYBLE_UDS_CHAR_COUNT) || (descrIndex >= CYBLE_UDS_DESCR_COUNT))
    {
        apiResult = CYBLE_ERROR_INVALID_PARAMETER;
    }
    else if(CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE == cyBle_udsc.charInfo[charIndex].descrHandle[descrIndex])
    {
		apiResult = CYBLE_ERROR_GATT_DB_INVALID_ATTR_HANDLE;
	}
    else
    {
        apiResult = CyBle_GattcReadCharacteristicDescriptors(connHandle, cyBle_udsc.charInfo[charIndex].descrHandle[descrIndex]);
        if(CYBLE_ERROR_OK == apiResult)
        {
            cyBle_udscReqHandle = cyBle_udsc.charInfo[charIndex].descrHandle[descrIndex];
        }
    }
    
    return (apiResult);
}


/******************************************************************************
* Function Name: CyBle_UdscDiscoverCharacteristicsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a CYBLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param discCharInfo: The pointer to a characteristic information structure.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscDiscoverCharacteristicsEventHandler(CYBLE_DISC_CHAR_INFO_T *discCharInfo)
{
    /* User Data Service characteristics UUIDs */
    static const CYBLE_UUID16 cyBle_udscCharUuid[CYBLE_UDS_CHAR_COUNT] =
    {
        CYBLE_UUID_CHAR_FIRST_NAME,
        CYBLE_UUID_CHAR_LAST_NAME,
        CYBLE_UUID_CHAR_EMAIL_ADDRESS,
        CYBLE_UUID_CHAR_AGE,
        CYBLE_UUID_CHAR_DATE_OF_BIRTH,
        CYBLE_UUID_CHAR_GENDER,
        CYBLE_UUID_CHAR_WEIGHT,
        CYBLE_UUID_CHAR_HEIGHT,
        CYBLE_UUID_CHAR_VO2_MAX,
        CYBLE_UUID_CHAR_HEART_RATE_MAX,
        CYBLE_UUID_CHAR_RESTING_HEART_RATE,
        CYBLE_UUID_CHAR_MRH,
        CYBLE_UUID_CHAR_AEROBIC_THRESHOLD,
        CYBLE_UUID_CHAR_ANAEROBIC_THRESHOLD,
        CYBLE_UUID_CHAR_STP,
        CYBLE_UUID_CHAR_DATE_OF_THRESHOLD_ASSESSMENT,
        CYBLE_UUID_CHAR_WAIST_CIRCUMFERENCE,
        CYBLE_UUID_CHAR_HIP_CIRCUNFERENCE,
        CYBLE_UUID_CHAR_FBL,
        CYBLE_UUID_CHAR_FBU,
        CYBLE_UUID_CHAR_AEL,
        CYBLE_UUID_CHAR_AEU,
        CYBLE_UUID_CHAR_ANL,
        CYBLE_UUID_CHAR_ANU,
        CYBLE_UUID_CHAR_FIVE_ZONE_HEART_RATE_LIMITS,
        CYBLE_UUID_CHAR_THREE_ZONE_HEART_RATE_LIMITS,
        CYBLE_UUID_CHAR_TWO_ZONE_HEART_RATE_LIMIT,
        CYBLE_UUID_CHAR_DATABASE_CHANGE_INCREMENT,
        CYBLE_UUID_CHAR_USER_INDEX,
        CYBLE_UUID_CHAR_USER_CONTROL_POINT,
        CYBLE_UUID_CHAR_LANGUAGE
    };
    static CYBLE_GATT_DB_ATTR_HANDLE_T *lnsLastEndHandle = NULL;
    uint8 i;
    
    /* Update last characteristic endHandle to declaration handle of this characteristic */
    if(lnsLastEndHandle != NULL)
    {
        *lnsLastEndHandle = discCharInfo->charDeclHandle - 1u;
        lnsLastEndHandle = NULL;
    }
    
    for(i = 0u; i < (uint8) CYBLE_UDS_CHAR_COUNT; i++)
    {
        if(cyBle_udscCharUuid[i] == discCharInfo->uuid.uuid16)
        {
            if(cyBle_udsc.charInfo[i].valueHandle == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
            {
                cyBle_udsc.charInfo[i].valueHandle = discCharInfo->valueHandle;
                cyBle_udsc.charInfo[i].properties = discCharInfo->properties;
                lnsLastEndHandle = &cyBle_udsc.charInfo[i].endHandle;
            }
            else
            {
                CyBle_ApplCallback(CYBLE_EVT_GATTC_CHAR_DUPLICATION, &discCharInfo->uuid);
            }
        }
    }
    
    /* Init characteristic endHandle to Service endHandle.
       Characteristic endHandle will be updated to the declaration
       Handler of the following characteristic,
       in the following characteristic discovery procedure. */
    if(lnsLastEndHandle != NULL)
    {
        *lnsLastEndHandle = cyBle_serverInfo[CYBLE_SRVI_UDS].range.endHandle;
    }
}


/******************************************************************************
* Function Name: CyBle_UdscDiscoverCharDescriptorsEventHandler
***************************************************************************//**
* 
*  This function is called on receiving a CYBLE_EVT_GATTC_READ_BY_TYPE_RSP
*  event. Based on the service UUID, an appropriate data structure is populated
*  using the data received as part of the callback.
* 
*  \param discCharInfo: The pointer to the characteristic information structure.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscDiscoverCharDescriptorsEventHandler(CYBLE_DISC_DESCR_INFO_T * discDescrInfo)
{
    if(discDescrInfo->uuid.uuid16 == CYBLE_UUID_CHAR_CLIENT_CONFIG)
    {
        uint8 descrIdx;
        if(cyBle_disCount == (uint8)CYBLE_SCDI_UDS_DCI)
        {
            descrIdx = (uint8)CYBLE_UDS_DCI;
        }
        else
        {
            descrIdx = (uint8)CYBLE_UDS_UCP;
        }
        
        if(cyBle_udsc.charInfo[descrIdx].descrHandle[CYBLE_UDS_CCCD] == CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
        {
            cyBle_udsc.charInfo[descrIdx].descrHandle[CYBLE_UDS_CCCD] = discDescrInfo->descrHandle;
        }
        else    /* Duplication of descriptor */
        {
            CyBle_ApplCallback(CYBLE_EVT_GATTC_DESCR_DUPLICATION, &discDescrInfo->uuid);
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdscNotificationEventHandler
***************************************************************************//**
* 
*  Handles the Notification Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscNotificationEventHandler(CYBLE_GATTC_HANDLE_VALUE_NTF_PARAM_T *eventParam)
{
    if((NULL != CyBle_UdsApplCallback) &&
        (cyBle_udsc.charInfo[CYBLE_UDS_DCI].valueHandle == eventParam->handleValPair.attrHandle))
    { 
        CYBLE_UDS_CHAR_VALUE_T locCharValue;    
        locCharValue.connHandle = eventParam->connHandle;
        locCharValue.charIndex = CYBLE_UDS_DCI;
        locCharValue.value = &eventParam->handleValPair.value;

        CyBle_UdsApplCallback(CYBLE_EVT_UDSC_NOTIFICATION, &locCharValue);
        cyBle_eventHandlerFlag &= (uint8) ~CYBLE_CALLBACK;
    }
}


/******************************************************************************
* Function Name: CyBle_UdscIndicationEventHandler
***************************************************************************//**
* 
*  Handles the Indication Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscIndicationEventHandler(CYBLE_GATTC_HANDLE_VALUE_IND_PARAM_T *eventParam)
{
    if(NULL != CyBle_UdsApplCallback)
    {
        if(cyBle_udsc.charInfo[CYBLE_UDS_UCP].valueHandle == eventParam->handleValPair.attrHandle)
        {
            CYBLE_UDS_CHAR_VALUE_T locCharValue;
            locCharValue.charIndex = CYBLE_UDS_UCP;
            cyBle_eventHandlerFlag &= (uint8) ~CYBLE_CALLBACK;
            locCharValue.connHandle = eventParam->connHandle;       
            locCharValue.value = &eventParam->handleValPair.value;

            CyBle_UdsApplCallback(CYBLE_EVT_UDSC_INDICATION, &locCharValue);
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdscReadResponseEventHandler
***************************************************************************//**
* 
*  Handles the Read Response Event.
* 
*  \param eventParam - The pointer to the data structure.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscReadResponseEventHandler(CYBLE_GATTC_READ_RSP_PARAM_T *eventParam)
{
    if(cyBle_udscReqHandle != CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE)
    {
        if(CyBle_UdsApplCallback != NULL)
        {
            CYBLE_UDS_CHAR_INDEX_T i;
                
            for(i = CYBLE_UDS_FNM; i < CYBLE_UDS_CHAR_COUNT; i++)
            {
                if(cyBle_udsc.charInfo[i].valueHandle == cyBle_udscReqHandle)
                {
                    CYBLE_UDS_CHAR_VALUE_T locCharValue;
                    
                    locCharValue.connHandle = eventParam->connHandle;
                    locCharValue.charIndex = i;
                    locCharValue.value = &eventParam->value;
                    
                    CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSC_READ_CHAR_RESPONSE, &locCharValue);
                    cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                    break;
                }
            }
            
            if((cyBle_eventHandlerFlag & CYBLE_CALLBACK) != 0u)
            {
                for(i = CYBLE_UDS_FNM; i < CYBLE_UDS_CHAR_COUNT; i++)
                {
                    if(cyBle_udsc.charInfo[i].descrHandle[CYBLE_UDS_CCCD] == cyBle_udscReqHandle)
                    {
                        CYBLE_UDS_DESCR_VALUE_T locDescrValue;
                        
                        locDescrValue.connHandle = eventParam->connHandle;
                        locDescrValue.charIndex = i;
                        locDescrValue.descrIndex = CYBLE_UDS_CCCD;
                        locDescrValue.value = &eventParam->value;

                        CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSC_READ_DESCR_RESPONSE, &locDescrValue);
                        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                        break;
                    }
                }
            }
        }
        
        cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
    }
}


/******************************************************************************
* Function Name: CyBle_UdscReadLongRespEventHandler
***************************************************************************//**
* 
*  Handles a Read Long Response event.
* 
*  \param eventParam: The pointer to the data structure specified by an event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscReadLongRespEventHandler(const CYBLE_GATTC_READ_RSP_PARAM_T *eventParam)
{
    if((NULL != CyBle_UdsApplCallback) && (cyBle_udscReqHandle != CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE))
    {
        CYBLE_UDS_CHAR_VALUE_T locCharValue;
        CYBLE_GATT_VALUE_T locGattValue;
        /* Go trough all long characteristics */
        for(locCharValue.charIndex = CYBLE_UDS_FNM;
            locCharValue.charIndex < CYBLE_UDS_CHAR_COUNT;
            locCharValue.charIndex++)
        {
            if(locCharValue.charIndex == CYBLE_UDS_AGE)
            {
                locCharValue.charIndex = CYBLE_UDS_LNG;
            }
            
            if(cyBle_udsc.charInfo[locCharValue.charIndex].valueHandle == cyBle_udscReqHandle)
            {
                uint8 i;
                
                /* Update user buffer with received data */
                for(i = 0u; i < eventParam->value.len; i++)
                {
                    if(cyBle_udscCurrLen < cyBle_udscRdLongBuffLen)
                    {
                        cyBle_udscRdLongBuffPtr[cyBle_udscCurrLen] = eventParam->value.val[i];
                        cyBle_udscCurrLen++;
                    }
                    else
                    {
                        CyBle_GattcStopCmd();
                        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                        break;
                    }
                }
                
                if((cyBle_eventHandlerFlag & CYBLE_CALLBACK) != 0u)
                {
                    uint16 mtuSize;
                    (void) CyBle_GattGetMtuSize(&mtuSize);
                    
                    /* If received data length is less than MTU size, Read Long
                    * request is completed or provided user's buffer is full.
                    */
                    if(((mtuSize - 1u) > eventParam->value.len))
                    {
                        locGattValue.val = cyBle_udscRdLongBuffPtr;
                        locGattValue.len = cyBle_udscCurrLen;
                        locCharValue.value = &locGattValue;
                        locCharValue.connHandle = eventParam->connHandle;
                        CyBle_UdsApplCallback((uint32) CYBLE_EVT_UDSC_READ_CHAR_RESPONSE, &locCharValue);
                        cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                    }
                    
                    cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                }
                
                break;
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdscWriteResponseEventHandler
***************************************************************************//**
* 
*  Handles the Write Response Event.
* 
*  \param eventParam: The pointer to a data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscWriteResponseEventHandler(const CYBLE_CONN_HANDLE_T *eventParam)
{
    if((NULL != CyBle_UdsApplCallback) && (CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE != cyBle_udscReqHandle))
    {
        if(cyBle_udsc.charInfo[CYBLE_UDS_UCP].valueHandle == cyBle_udscReqHandle)
        {
            CYBLE_UDS_CHAR_VALUE_T locCharIndex;
            
            locCharIndex.connHandle = *eventParam;
            locCharIndex.charIndex = CYBLE_UDS_UCP;
            locCharIndex.value = NULL;
            
            cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
            cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
            CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSC_WRITE_CHAR_RESPONSE, &locCharIndex);
        }
        else
        {
            CYBLE_UDS_CHAR_INDEX_T i;
            
            for(i = CYBLE_UDS_FNM; i < CYBLE_UDS_CHAR_COUNT; i++)
            {
                if(cyBle_udsc.charInfo[i].descrHandle[CYBLE_UDS_CCCD] == cyBle_udscReqHandle)
                {
                    CYBLE_UDS_DESCR_VALUE_T locDescIndex;
                    
                    locDescIndex.connHandle = *eventParam;
                    locDescIndex.charIndex = i;
                    locDescIndex.descrIndex = CYBLE_UDS_CCCD;
                    locDescIndex.value = NULL;

                    cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                    cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                    CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSC_WRITE_DESCR_RESPONSE, &locDescIndex);
                    break;
                }
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdscExecuteWriteResponseEventHandler
***************************************************************************//**
* 
*  Handles a Execute Write Response event for the User Data Service.
* 
*  \param eventParam: The pointer to a data structure specified by an event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscExecuteWriteResponseEventHandler(const CYBLE_GATTC_EXEC_WRITE_RSP_T *eventParam)
{
    uint8 i;
    CYBLE_UDS_CHAR_VALUE_T locCharVal;

    if((NULL != CyBle_UdsApplCallback) && (CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE != cyBle_udscReqHandle))
    {
        for(i = 0u; i < ((uint8) CYBLE_UDS_CHAR_COUNT); i++)
        {
            if(cyBle_udsc.charInfo[i].valueHandle == cyBle_udscReqHandle)
            {
                locCharVal.connHandle = eventParam->connHandle;
                locCharVal.charIndex = (CYBLE_UDS_CHAR_INDEX_T) i;
                locCharVal.value = NULL;
                cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
                CyBle_UdsApplCallback((uint32) CYBLE_EVT_UDSC_WRITE_CHAR_RESPONSE, &locCharVal);
                cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
            }
        }
    }
}


/******************************************************************************
* Function Name: CyBle_UdscErrorResponseEventHandler
***************************************************************************//**
* 
*  Handles the Error Response Event.
* 
*  \param eventParam: The pointer to the data structure specified by the event.
* 
* \return
*  None.
* 
******************************************************************************/
void CyBle_UdscErrorResponseEventHandler(const CYBLE_GATTC_ERR_RSP_PARAM_T *eventParam)
{
    if((eventParam != NULL) && (eventParam->attrHandle == cyBle_udscReqHandle))
    {
        if((eventParam->opCode == CYBLE_GATT_READ_BLOB_REQ) &&
           (eventParam->errorCode == CYBLE_GATT_ERR_ATTRIBUTE_NOT_LONG))
        {
            (void)CyBle_GattcReadCharacteristicValue(eventParam->connHandle, eventParam->attrHandle);
            cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
        }
        else
        {   
            if(CyBle_UdsApplCallback != NULL)
            {
                CYBLE_UDS_CHAR_VALUE_T locGattError;
                locGattError.connHandle = eventParam->connHandle;
                locGattError.value = NULL;
                locGattError.gattErrorCode = eventParam->errorCode;
            
                for(locGattError.charIndex = CYBLE_UDS_FNM; 
                    locGattError.charIndex < CYBLE_UDS_CHAR_COUNT; 
                    locGattError.charIndex++)
                {
                    if(cyBle_udsc.charInfo[locGattError.charIndex].valueHandle == eventParam->attrHandle)
                    {
                        CyBle_UdsApplCallback((uint32)CYBLE_EVT_UDSC_ERROR_RESPONSE, &locGattError);
                        cyBle_eventHandlerFlag &= (uint8)~CYBLE_CALLBACK;
                        break;
                    }
                }
            }
            
            cyBle_udscReqHandle = CYBLE_GATT_INVALID_ATTR_HANDLE_VALUE;
        }
    }
}


#endif /* CYBLE_UDS_CLIENT */


/* [] END OF FILE */
