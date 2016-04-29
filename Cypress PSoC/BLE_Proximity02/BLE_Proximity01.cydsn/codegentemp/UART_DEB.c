/*******************************************************************************
* File Name: UART_DEB.c
* Version 3.10
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "UART_DEB_PVT.h"

#if (UART_DEB_SCB_MODE_I2C_INC)
    #include "UART_DEB_I2C_PVT.h"
#endif /* (UART_DEB_SCB_MODE_I2C_INC) */

#if (UART_DEB_SCB_MODE_EZI2C_INC)
    #include "UART_DEB_EZI2C_PVT.h"
#endif /* (UART_DEB_SCB_MODE_EZI2C_INC) */

#if (UART_DEB_SCB_MODE_SPI_INC || UART_DEB_SCB_MODE_UART_INC)
    #include "UART_DEB_SPI_UART_PVT.h"
#endif /* (UART_DEB_SCB_MODE_SPI_INC || UART_DEB_SCB_MODE_UART_INC) */


/***************************************
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for Unconfigured mode */
#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    uint8 UART_DEB_scbMode = UART_DEB_SCB_MODE_UNCONFIG;
    uint8 UART_DEB_scbEnableWake;
    uint8 UART_DEB_scbEnableIntr;

    /* I2C configuration variables */
    uint8 UART_DEB_mode;
    uint8 UART_DEB_acceptAddr;

    /* SPI/UART configuration variables */
    volatile uint8 * UART_DEB_rxBuffer;
    uint8  UART_DEB_rxDataBits;
    uint32 UART_DEB_rxBufferSize;

    volatile uint8 * UART_DEB_txBuffer;
    uint8  UART_DEB_txDataBits;
    uint32 UART_DEB_txBufferSize;

    /* EZI2C configuration variables */
    uint8 UART_DEB_numberOfAddr;
    uint8 UART_DEB_subAddrSize;
#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 UART_DEB_initVar = 0u;

#if (UART_DEB_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_UART_DEB_CUSTOM_INTR_HANDLER)
    void (*UART_DEB_customIntrHandler)(void) = NULL;
#endif /* !defined (CY_REMOVE_UART_DEB_CUSTOM_INTR_HANDLER) */
#endif /* (UART_DEB_SCB_IRQ_INTERNAL) */


/***************************************
*    Private Function Prototypes
***************************************/

static void UART_DEB_ScbEnableIntr(void);
static void UART_DEB_ScbModeStop(void);
static void UART_DEB_ScbModePostEnable(void);


/*******************************************************************************
* Function Name: UART_DEB_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected
*  configurations: I2C, SPI, UART or EZI2C.
*  When the configuration is set to "Unconfigured SCB", this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_DEB_Init(void)
{
#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
    if (UART_DEB_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UART_DEB_initVar = 0u;
    }
    else
    {
        /* Initialization was done before this function call */
    }

#elif (UART_DEB_SCB_MODE_I2C_CONST_CFG)
    UART_DEB_I2CInit();

#elif (UART_DEB_SCB_MODE_SPI_CONST_CFG)
    UART_DEB_SpiInit();

#elif (UART_DEB_SCB_MODE_UART_CONST_CFG)
    UART_DEB_UartInit();

#elif (UART_DEB_SCB_MODE_EZI2C_CONST_CFG)
    UART_DEB_EzI2CInit();

#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_DEB_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void UART_DEB_Enable(void)
{
#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if (!UART_DEB_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        UART_DEB_CTRL_REG |= UART_DEB_CTRL_ENABLED;

        UART_DEB_ScbEnableIntr();

        /* Call PostEnable function specific to current operation mode */
        UART_DEB_ScbModePostEnable();
    }
#else
    UART_DEB_CTRL_REG |= UART_DEB_CTRL_ENABLED;

    UART_DEB_ScbEnableIntr();

    /* Call PostEnable function specific to current operation mode */
    UART_DEB_ScbModePostEnable();
#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_DEB_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to "Unconfigured SCB", the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  UART_DEB_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void UART_DEB_Start(void)
{
    if (0u == UART_DEB_initVar)
    {
        UART_DEB_Init();
        UART_DEB_initVar = 1u; /* Component was initialized */
    }

    UART_DEB_Enable();
}


/*******************************************************************************
* Function Name: UART_DEB_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*  It also disables all TX interrupt sources so as not to cause an unexpected
*  interrupt trigger because after the component is enabled, the TX FIFO 
*  is empty.
*
* Parameters:
*  None
*
* Return:
*  None
* 
*******************************************************************************/
void UART_DEB_Stop(void)
{
#if (UART_DEB_SCB_IRQ_INTERNAL)
    UART_DEB_DisableInt();
#endif /* (UART_DEB_SCB_IRQ_INTERNAL) */

    /* Call Stop function specific to current operation mode */
    UART_DEB_ScbModeStop();

    /* Disable SCB IP */
    UART_DEB_CTRL_REG &= (uint32) ~UART_DEB_CTRL_ENABLED;

    /* Disable all TX interrupt sources so as not to cause an unexpected
    * interrupt trigger because after the component is enabled, the TX FIFO
    * is empty.
    * For SCB IP v0, it is critical as it does not mask-out interrupt
    * sources when they are disabled. This can cause a code lock-up in the
    * interrupt handler because TX FIFO cannot be loaded after the block
    * is disabled.
    */
    UART_DEB_SetTxInterruptMode(UART_DEB_NO_INTR_SOURCES);

#if (UART_DEB_SCB_IRQ_INTERNAL)
    UART_DEB_ClearPendingInt();
#endif /* (UART_DEB_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: UART_DEB_SetRxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the RX FIFO to generate a RX level interrupt.
*  When the RX FIFO has more entries than the RX FIFO level an RX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the RX FIFO to generate RX level interrupt.
*         The range of valid level values is between 0 and RX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void UART_DEB_SetRxFifoLevel(uint32 level)
{
    uint32 rxFifoCtrl;

    rxFifoCtrl = UART_DEB_RX_FIFO_CTRL_REG;

    rxFifoCtrl &= ((uint32) ~UART_DEB_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    rxFifoCtrl |= ((uint32) (UART_DEB_RX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    UART_DEB_RX_FIFO_CTRL_REG = rxFifoCtrl;
}


/*******************************************************************************
* Function Name: UART_DEB_SetTxFifoLevel
********************************************************************************
*
* Summary:
*  Sets level in the TX FIFO to generate a TX level interrupt.
*  When the TX FIFO has more entries than the TX FIFO level an TX level
*  interrupt request is generated.
*
* Parameters:
*  level: Level in the TX FIFO to generate TX level interrupt.
*         The range of valid level values is between 0 and TX FIFO depth - 1.
*
* Return:
*  None
*
*******************************************************************************/
void UART_DEB_SetTxFifoLevel(uint32 level)
{
    uint32 txFifoCtrl;

    txFifoCtrl = UART_DEB_TX_FIFO_CTRL_REG;

    txFifoCtrl &= ((uint32) ~UART_DEB_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK); /* Clear level mask bits */
    txFifoCtrl |= ((uint32) (UART_DEB_TX_FIFO_CTRL_TRIGGER_LEVEL_MASK & level));

    UART_DEB_TX_FIFO_CTRL_REG = txFifoCtrl;
}


#if (UART_DEB_SCB_IRQ_INTERNAL)
    /*******************************************************************************
    * Function Name: UART_DEB_SetCustomInterruptHandler
    ********************************************************************************
    *
    * Summary:
    *  Registers a function to be called by the internal interrupt handler.
    *  First the function that is registered is called, then the internal interrupt
    *  handler performs any operation such as software buffer management functions
    *  before the interrupt returns.  It is the user's responsibility not to break
    *  the software buffer operations. Only one custom handler is supported, which
    *  is the function provided by the most recent call.
    *  At the initialization time no custom handler is registered.
    *
    * Parameters:
    *  func: Pointer to the function to register.
    *        The value NULL indicates to remove the current custom interrupt
    *        handler.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_DEB_SetCustomInterruptHandler(void (*func)(void))
    {
    #if !defined (CY_REMOVE_UART_DEB_CUSTOM_INTR_HANDLER)
        UART_DEB_customIntrHandler = func; /* Register interrupt handler */
    #else
        if (NULL != func)
        {
            /* Suppress compiler warning */
        }
    #endif /* !defined (CY_REMOVE_UART_DEB_CUSTOM_INTR_HANDLER) */
    }
#endif /* (UART_DEB_SCB_IRQ_INTERNAL) */


/*******************************************************************************
* Function Name: UART_DEB_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void UART_DEB_ScbEnableIntr(void)
{
#if (UART_DEB_SCB_IRQ_INTERNAL)
    /* Enable interrupt in NVIC */
    #if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
        if (0u != UART_DEB_scbEnableIntr)
        {
            UART_DEB_EnableInt();
        }

    #else
        UART_DEB_EnableInt();

    #endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (UART_DEB_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: UART_DEB_ScbModePostEnable
********************************************************************************
*
* Summary:
*  Calls the PostEnable function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void UART_DEB_ScbModePostEnable(void)
{
#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
#if (!UART_DEB_CY_SCBIP_V1)
    if (UART_DEB_SCB_MODE_SPI_RUNTM_CFG)
    {
        UART_DEB_SpiPostEnable();
    }
    else if (UART_DEB_SCB_MODE_UART_RUNTM_CFG)
    {
        UART_DEB_UartPostEnable();
    }
    else
    {
        /* Unknown mode: do nothing */
    }
#endif /* (!UART_DEB_CY_SCBIP_V1) */

#elif (UART_DEB_SCB_MODE_SPI_CONST_CFG)
    UART_DEB_SpiPostEnable();

#elif (UART_DEB_SCB_MODE_UART_CONST_CFG)
    UART_DEB_UartPostEnable();

#else
    /* Unknown mode: do nothing */
#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: UART_DEB_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void UART_DEB_ScbModeStop(void)
{
#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
    if (UART_DEB_SCB_MODE_I2C_RUNTM_CFG)
    {
        UART_DEB_I2CStop();
    }
    else if (UART_DEB_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        UART_DEB_EzI2CStop();
    }
#if (!UART_DEB_CY_SCBIP_V1)
    else if (UART_DEB_SCB_MODE_SPI_RUNTM_CFG)
    {
        UART_DEB_SpiStop();
    }
    else if (UART_DEB_SCB_MODE_UART_RUNTM_CFG)
    {
        UART_DEB_UartStop();
    }
#endif /* (!UART_DEB_CY_SCBIP_V1) */
    else
    {
        /* Unknown mode: do nothing */
    }
#elif (UART_DEB_SCB_MODE_I2C_CONST_CFG)
    UART_DEB_I2CStop();

#elif (UART_DEB_SCB_MODE_EZI2C_CONST_CFG)
    UART_DEB_EzI2CStop();

#elif (UART_DEB_SCB_MODE_SPI_CONST_CFG)
    UART_DEB_SpiStop();

#elif (UART_DEB_SCB_MODE_UART_CONST_CFG)
    UART_DEB_UartStop();

#else
    /* Unknown mode: do nothing */
#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: UART_DEB_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartEnableMask: enables TX or RX direction and RTS and CTS signals.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_DEB_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask)
    {
        uint32 hsiomSel [UART_DEB_SCB_PINS_NUMBER];
        uint32 pinsDm   [UART_DEB_SCB_PINS_NUMBER];

    #if (!UART_DEB_CY_SCBIP_V1)
        uint32 pinsInBuf = 0u;
    #endif /* (!UART_DEB_CY_SCBIP_V1) */

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for (i = 0u; i < UART_DEB_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = UART_DEB_HSIOM_DEF_SEL;
            pinsDm[i]    = UART_DEB_PIN_DM_ALG_HIZ;
        }

        if ((UART_DEB_SCB_MODE_I2C   == mode) ||
           (UART_DEB_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_HSIOM_I2C_SEL;
            hsiomSel[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_HSIOM_I2C_SEL;

            pinsDm[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_PIN_DM_OD_LO;
            pinsDm[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_PIN_DM_OD_LO;
        }
    #if (!UART_DEB_CY_SCBIP_V1)
        else if (UART_DEB_SCB_MODE_SPI == mode)
        {
            hsiomSel[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
            hsiomSel[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
            hsiomSel[UART_DEB_CTS_SCLK_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;

            if (UART_DEB_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;
                pinsDm[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsDm[UART_DEB_CTS_SCLK_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;

            #if (UART_DEB_RTS_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
                pinsDm  [UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;
            #endif /* (UART_DEB_RTS_SS0_PIN) */

            #if (UART_DEB_TX_SCL_MISO_PIN)
                /* Disable input buffer */
                 pinsInBuf |= UART_DEB_TX_SCL_MISO_PIN_MASK;
            #endif /* (UART_DEB_TX_SCL_MISO_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsDm[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;
                pinsDm[UART_DEB_CTS_SCLK_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;

            #if (UART_DEB_RTS_SS0_PIN)
                hsiomSel [UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
                pinsDm   [UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsInBuf |= UART_DEB_RTS_SS0_PIN_MASK;
            #endif /* (UART_DEB_RTS_SS0_PIN) */

            #if (UART_DEB_SS1_PIN)
                hsiomSel [UART_DEB_SS1_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
                pinsDm   [UART_DEB_SS1_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsInBuf |= UART_DEB_SS1_PIN_MASK;
            #endif /* (UART_DEB_SS1_PIN) */

            #if (UART_DEB_SS2_PIN)
                hsiomSel [UART_DEB_SS2_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
                pinsDm   [UART_DEB_SS2_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsInBuf |= UART_DEB_SS2_PIN_MASK;
            #endif /* (UART_DEB_SS2_PIN) */

            #if (UART_DEB_SS3_PIN)
                hsiomSel [UART_DEB_SS3_PIN_INDEX] = UART_DEB_HSIOM_SPI_SEL;
                pinsDm   [UART_DEB_SS3_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;
                pinsInBuf |= UART_DEB_SS3_PIN_MASK;
            #endif /* (UART_DEB_SS3_PIN) */

                /* Disable input buffers */
            #if (UART_DEB_RX_SDA_MOSI_PIN)
                pinsInBuf |= UART_DEB_RX_SDA_MOSI_PIN_MASK;
            #endif /* (UART_DEB_RX_SDA_MOSI_PIN) */

             #if (UART_DEB_RX_WAKE_SDA_MOSI_PIN)
                pinsInBuf |= UART_DEB_RX_WAKE_SDA_MOSI_PIN_MASK;
            #endif /* (UART_DEB_RX_WAKE_SDA_MOSI_PIN) */

            #if (UART_DEB_CTS_SCLK_PIN)
                pinsInBuf |= UART_DEB_CTS_SCLK_PIN_MASK;
            #endif /* (UART_DEB_CTS_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if (UART_DEB_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_HSIOM_UART_SEL;
                pinsDm  [UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if (0u != (UART_DEB_UART_RX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_HSIOM_UART_SEL;
                    pinsDm  [UART_DEB_RX_SDA_MOSI_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;
                }

                if (0u != (UART_DEB_UART_TX_PIN_ENABLE & uartEnableMask))
                {
                    hsiomSel[UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_HSIOM_UART_SEL;
                    pinsDm  [UART_DEB_TX_SCL_MISO_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;

                #if (UART_DEB_TX_SCL_MISO_PIN)
                     pinsInBuf |= UART_DEB_TX_SCL_MISO_PIN_MASK;
                #endif /* (UART_DEB_TX_SCL_MISO_PIN) */
                }

            #if !(UART_DEB_CY_SCBIP_V0 || UART_DEB_CY_SCBIP_V1)
                if (UART_DEB_UART_MODE_STD == subMode)
                {
                    if (0u != (UART_DEB_UART_CTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* CTS input is multiplexed with SCLK */
                        hsiomSel[UART_DEB_CTS_SCLK_PIN_INDEX] = UART_DEB_HSIOM_UART_SEL;
                        pinsDm  [UART_DEB_CTS_SCLK_PIN_INDEX] = UART_DEB_PIN_DM_DIG_HIZ;
                    }

                    if (0u != (UART_DEB_UART_RTS_PIN_ENABLE & uartEnableMask))
                    {
                        /* RTS output is multiplexed with SS0 */
                        hsiomSel[UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_HSIOM_UART_SEL;
                        pinsDm  [UART_DEB_RTS_SS0_PIN_INDEX] = UART_DEB_PIN_DM_STRONG;

                    #if (UART_DEB_RTS_SS0_PIN)
                        /* Disable input buffer */
                        pinsInBuf |= UART_DEB_RTS_SS0_PIN_MASK;
                    #endif /* (UART_DEB_RTS_SS0_PIN) */
                    }
                }
            #endif /* !(UART_DEB_CY_SCBIP_V0 || UART_DEB_CY_SCBIP_V1) */
            }
        }
    #endif /* (!UART_DEB_CY_SCBIP_V1) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settings do not effect the pin output if HSIOM is other than GPIO */

    #if (UART_DEB_RX_WAKE_SDA_MOSI_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_RX_WAKE_SDA_MOSI_HSIOM_REG,
                                       UART_DEB_RX_WAKE_SDA_MOSI_HSIOM_MASK,
                                       UART_DEB_RX_WAKE_SDA_MOSI_HSIOM_POS,
                                       hsiomSel[UART_DEB_RX_WAKE_SDA_MOSI_PIN_INDEX]);

        UART_DEB_uart_rx_wake_i2c_sda_spi_mosi_SetDriveMode((uint8)
                                                               pinsDm[UART_DEB_RX_WAKE_SDA_MOSI_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_uart_rx_wake_i2c_sda_spi_mosi_INP_DIS,
                                     UART_DEB_uart_rx_wake_i2c_sda_spi_mosi_MASK,
                                     (0u != (pinsInBuf & UART_DEB_RX_WAKE_SDA_MOSI_PIN_MASK)));

         /* Set interrupt on falling edge */
        UART_DEB_SET_INCFG_TYPE(UART_DEB_RX_WAKE_SDA_MOSI_INTCFG_REG,
                                        UART_DEB_RX_WAKE_SDA_MOSI_INTCFG_TYPE_MASK,
                                        UART_DEB_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS,
                                        UART_DEB_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (UART_DEB_RX_WAKE_SDA_MOSI_PIN) */

    #if (UART_DEB_RX_SDA_MOSI_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_RX_SDA_MOSI_HSIOM_REG,
                                       UART_DEB_RX_SDA_MOSI_HSIOM_MASK,
                                       UART_DEB_RX_SDA_MOSI_HSIOM_POS,
                                        hsiomSel[UART_DEB_RX_SDA_MOSI_PIN_INDEX]);

        UART_DEB_uart_rx_i2c_sda_spi_mosi_SetDriveMode((uint8) pinsDm[UART_DEB_RX_SDA_MOSI_PIN_INDEX]);

    #if (!UART_DEB_CY_SCBIP_V1)
        UART_DEB_SET_INP_DIS(UART_DEB_uart_rx_i2c_sda_spi_mosi_INP_DIS,
                                     UART_DEB_uart_rx_i2c_sda_spi_mosi_MASK,
                                     (0u != (pinsInBuf & UART_DEB_RX_SDA_MOSI_PIN_MASK)));
    #endif /* (!UART_DEB_CY_SCBIP_V1) */
    #endif /* (UART_DEB_RX_SDA_MOSI_PIN) */

    #if (UART_DEB_TX_SCL_MISO_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_TX_SCL_MISO_HSIOM_REG,
                                       UART_DEB_TX_SCL_MISO_HSIOM_MASK,
                                       UART_DEB_TX_SCL_MISO_HSIOM_POS,
                                        hsiomSel[UART_DEB_TX_SCL_MISO_PIN_INDEX]);

        UART_DEB_uart_tx_i2c_scl_spi_miso_SetDriveMode((uint8) pinsDm[UART_DEB_TX_SCL_MISO_PIN_INDEX]);

    #if (!UART_DEB_CY_SCBIP_V1)
        UART_DEB_SET_INP_DIS(UART_DEB_uart_tx_i2c_scl_spi_miso_INP_DIS,
                                     UART_DEB_uart_tx_i2c_scl_spi_miso_MASK,
                                    (0u != (pinsInBuf & UART_DEB_TX_SCL_MISO_PIN_MASK)));
    #endif /* (!UART_DEB_CY_SCBIP_V1) */
    #endif /* (UART_DEB_RX_SDA_MOSI_PIN) */

    #if (UART_DEB_CTS_SCLK_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_CTS_SCLK_HSIOM_REG,
                                       UART_DEB_CTS_SCLK_HSIOM_MASK,
                                       UART_DEB_CTS_SCLK_HSIOM_POS,
                                       hsiomSel[UART_DEB_CTS_SCLK_PIN_INDEX]);

        UART_DEB_uart_cts_spi_sclk_SetDriveMode((uint8) pinsDm[UART_DEB_CTS_SCLK_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_uart_cts_spi_sclk_INP_DIS,
                                     UART_DEB_uart_cts_spi_sclk_MASK,
                                     (0u != (pinsInBuf & UART_DEB_CTS_SCLK_PIN_MASK)));
    #endif /* (UART_DEB_CTS_SCLK_PIN) */

    #if (UART_DEB_RTS_SS0_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_RTS_SS0_HSIOM_REG,
                                       UART_DEB_RTS_SS0_HSIOM_MASK,
                                       UART_DEB_RTS_SS0_HSIOM_POS,
                                       hsiomSel[UART_DEB_RTS_SS0_PIN_INDEX]);

        UART_DEB_uart_rts_spi_ss0_SetDriveMode((uint8) pinsDm[UART_DEB_RTS_SS0_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_uart_rts_spi_ss0_INP_DIS,
                                     UART_DEB_uart_rts_spi_ss0_MASK,
                                     (0u != (pinsInBuf & UART_DEB_RTS_SS0_PIN_MASK)));
    #endif /* (UART_DEB_RTS_SS0_PIN) */

    #if (UART_DEB_SS1_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_SS1_HSIOM_REG,
                                       UART_DEB_SS1_HSIOM_MASK,
                                       UART_DEB_SS1_HSIOM_POS,
                                       hsiomSel[UART_DEB_SS1_PIN_INDEX]);

        UART_DEB_spi_ss1_SetDriveMode((uint8) pinsDm[UART_DEB_SS1_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_spi_ss1_INP_DIS,
                                     UART_DEB_spi_ss1_MASK,
                                     (0u != (pinsInBuf & UART_DEB_SS1_PIN_MASK)));
    #endif /* (UART_DEB_SS1_PIN) */

    #if (UART_DEB_SS2_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_SS2_HSIOM_REG,
                                       UART_DEB_SS2_HSIOM_MASK,
                                       UART_DEB_SS2_HSIOM_POS,
                                       hsiomSel[UART_DEB_SS2_PIN_INDEX]);

        UART_DEB_spi_ss2_SetDriveMode((uint8) pinsDm[UART_DEB_SS2_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_spi_ss2_INP_DIS,
                                     UART_DEB_spi_ss2_MASK,
                                     (0u != (pinsInBuf & UART_DEB_SS2_PIN_MASK)));
    #endif /* (UART_DEB_SS2_PIN) */

    #if (UART_DEB_SS3_PIN)
        UART_DEB_SET_HSIOM_SEL(UART_DEB_SS3_HSIOM_REG,
                                       UART_DEB_SS3_HSIOM_MASK,
                                       UART_DEB_SS3_HSIOM_POS,
                                       hsiomSel[UART_DEB_SS3_PIN_INDEX]);

        UART_DEB_spi_ss3_SetDriveMode((uint8) pinsDm[UART_DEB_SS3_PIN_INDEX]);

        UART_DEB_SET_INP_DIS(UART_DEB_spi_ss3_INP_DIS,
                                     UART_DEB_spi_ss3_MASK,
                                     (0u != (pinsInBuf & UART_DEB_SS3_PIN_MASK)));
    #endif /* (UART_DEB_SS3_PIN) */
    }

#endif /* (UART_DEB_SCB_MODE_UNCONFIG_CONST_CFG) */


#if (UART_DEB_CY_SCBIP_V0 || UART_DEB_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: UART_DEB_I2CSlaveNackGeneration
    ********************************************************************************
    *
    * Summary:
    *  Sets command to generate NACK to the address or data.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void UART_DEB_I2CSlaveNackGeneration(void)
    {
        /* Check for EC_AM toggle condition: EC_AM and clock stretching for address are enabled */
        if ((0u != (UART_DEB_CTRL_REG & UART_DEB_CTRL_EC_AM_MODE)) &&
            (0u == (UART_DEB_I2C_CTRL_REG & UART_DEB_I2C_CTRL_S_NOT_READY_ADDR_NACK)))
        {
            /* Toggle EC_AM before NACK generation */
            UART_DEB_CTRL_REG &= ~UART_DEB_CTRL_EC_AM_MODE;
            UART_DEB_CTRL_REG |=  UART_DEB_CTRL_EC_AM_MODE;
        }

        UART_DEB_I2C_SLAVE_CMD_REG = UART_DEB_I2C_SLAVE_CMD_S_NACK;
    }
#endif /* (UART_DEB_CY_SCBIP_V0 || UART_DEB_CY_SCBIP_V1) */


/* [] END OF FILE */
