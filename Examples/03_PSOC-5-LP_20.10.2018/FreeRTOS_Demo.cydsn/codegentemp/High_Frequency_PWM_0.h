/*******************************************************************************
* File Name: High_Frequency_PWM_0.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_High_Frequency_PWM_0_H)
#define CY_PWM_High_Frequency_PWM_0_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 High_Frequency_PWM_0_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define High_Frequency_PWM_0_Resolution                     (16u)
#define High_Frequency_PWM_0_UsingFixedFunction             (0u)
#define High_Frequency_PWM_0_DeadBandMode                   (0u)
#define High_Frequency_PWM_0_KillModeMinTime                (0u)
#define High_Frequency_PWM_0_KillMode                       (0u)
#define High_Frequency_PWM_0_PWMMode                        (0u)
#define High_Frequency_PWM_0_PWMModeIsCenterAligned         (0u)
#define High_Frequency_PWM_0_DeadBandUsed                   (0u)
#define High_Frequency_PWM_0_DeadBand2_4                    (0u)

#if !defined(High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__REMOVED)
    #define High_Frequency_PWM_0_UseStatus                  (1u)
#else
    #define High_Frequency_PWM_0_UseStatus                  (0u)
#endif /* !defined(High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(High_Frequency_PWM_0_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define High_Frequency_PWM_0_UseControl                 (1u)
#else
    #define High_Frequency_PWM_0_UseControl                 (0u)
#endif /* !defined(High_Frequency_PWM_0_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define High_Frequency_PWM_0_UseOneCompareMode              (1u)
#define High_Frequency_PWM_0_MinimumKillTime                (1u)
#define High_Frequency_PWM_0_EnableMode                     (0u)

#define High_Frequency_PWM_0_CompareMode1SW                 (0u)
#define High_Frequency_PWM_0_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define High_Frequency_PWM_0__B_PWM__DISABLED 0
#define High_Frequency_PWM_0__B_PWM__ASYNCHRONOUS 1
#define High_Frequency_PWM_0__B_PWM__SINGLECYCLE 2
#define High_Frequency_PWM_0__B_PWM__LATCHED 3
#define High_Frequency_PWM_0__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define High_Frequency_PWM_0__B_PWM__DBMDISABLED 0
#define High_Frequency_PWM_0__B_PWM__DBM_2_4_CLOCKS 1
#define High_Frequency_PWM_0__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define High_Frequency_PWM_0__B_PWM__ONE_OUTPUT 0
#define High_Frequency_PWM_0__B_PWM__TWO_OUTPUTS 1
#define High_Frequency_PWM_0__B_PWM__DUAL_EDGE 2
#define High_Frequency_PWM_0__B_PWM__CENTER_ALIGN 3
#define High_Frequency_PWM_0__B_PWM__DITHER 5
#define High_Frequency_PWM_0__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define High_Frequency_PWM_0__B_PWM__LESS_THAN 1
#define High_Frequency_PWM_0__B_PWM__LESS_THAN_OR_EQUAL 2
#define High_Frequency_PWM_0__B_PWM__GREATER_THAN 3
#define High_Frequency_PWM_0__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define High_Frequency_PWM_0__B_PWM__EQUAL 0
#define High_Frequency_PWM_0__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!High_Frequency_PWM_0_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!High_Frequency_PWM_0_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!High_Frequency_PWM_0_PWMModeIsCenterAligned) */
        #if (High_Frequency_PWM_0_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (High_Frequency_PWM_0_UseStatus) */

        /* Backup for Deadband parameters */
        #if(High_Frequency_PWM_0_DeadBandMode == High_Frequency_PWM_0__B_PWM__DBM_256_CLOCKS || \
            High_Frequency_PWM_0_DeadBandMode == High_Frequency_PWM_0__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(High_Frequency_PWM_0_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (High_Frequency_PWM_0_KillModeMinTime) */

        /* Backup control register */
        #if(High_Frequency_PWM_0_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (High_Frequency_PWM_0_UseControl) */

    #endif /* (!High_Frequency_PWM_0_UsingFixedFunction) */

}High_Frequency_PWM_0_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    High_Frequency_PWM_0_Start(void) ;
void    High_Frequency_PWM_0_Stop(void) ;

#if (High_Frequency_PWM_0_UseStatus || High_Frequency_PWM_0_UsingFixedFunction)
    void  High_Frequency_PWM_0_SetInterruptMode(uint8 interruptMode) ;
    uint8 High_Frequency_PWM_0_ReadStatusRegister(void) ;
#endif /* (High_Frequency_PWM_0_UseStatus || High_Frequency_PWM_0_UsingFixedFunction) */

#define High_Frequency_PWM_0_GetInterruptSource() High_Frequency_PWM_0_ReadStatusRegister()

#if (High_Frequency_PWM_0_UseControl)
    uint8 High_Frequency_PWM_0_ReadControlRegister(void) ;
    void  High_Frequency_PWM_0_WriteControlRegister(uint8 control)
          ;
#endif /* (High_Frequency_PWM_0_UseControl) */

#if (High_Frequency_PWM_0_UseOneCompareMode)
   #if (High_Frequency_PWM_0_CompareMode1SW)
       void    High_Frequency_PWM_0_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (High_Frequency_PWM_0_CompareMode1SW) */
#else
    #if (High_Frequency_PWM_0_CompareMode1SW)
        void    High_Frequency_PWM_0_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (High_Frequency_PWM_0_CompareMode1SW) */
    #if (High_Frequency_PWM_0_CompareMode2SW)
        void    High_Frequency_PWM_0_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (High_Frequency_PWM_0_CompareMode2SW) */
#endif /* (High_Frequency_PWM_0_UseOneCompareMode) */

#if (!High_Frequency_PWM_0_UsingFixedFunction)
    uint16   High_Frequency_PWM_0_ReadCounter(void) ;
    uint16 High_Frequency_PWM_0_ReadCapture(void) ;

    #if (High_Frequency_PWM_0_UseStatus)
            void High_Frequency_PWM_0_ClearFIFO(void) ;
    #endif /* (High_Frequency_PWM_0_UseStatus) */

    void    High_Frequency_PWM_0_WriteCounter(uint16 counter)
            ;
#endif /* (!High_Frequency_PWM_0_UsingFixedFunction) */

void    High_Frequency_PWM_0_WritePeriod(uint16 period)
        ;
uint16 High_Frequency_PWM_0_ReadPeriod(void) ;

#if (High_Frequency_PWM_0_UseOneCompareMode)
    void    High_Frequency_PWM_0_WriteCompare(uint16 compare)
            ;
    uint16 High_Frequency_PWM_0_ReadCompare(void) ;
#else
    void    High_Frequency_PWM_0_WriteCompare1(uint16 compare)
            ;
    uint16 High_Frequency_PWM_0_ReadCompare1(void) ;
    void    High_Frequency_PWM_0_WriteCompare2(uint16 compare)
            ;
    uint16 High_Frequency_PWM_0_ReadCompare2(void) ;
#endif /* (High_Frequency_PWM_0_UseOneCompareMode) */


#if (High_Frequency_PWM_0_DeadBandUsed)
    void    High_Frequency_PWM_0_WriteDeadTime(uint8 deadtime) ;
    uint8   High_Frequency_PWM_0_ReadDeadTime(void) ;
#endif /* (High_Frequency_PWM_0_DeadBandUsed) */

#if ( High_Frequency_PWM_0_KillModeMinTime)
    void High_Frequency_PWM_0_WriteKillTime(uint8 killtime) ;
    uint8 High_Frequency_PWM_0_ReadKillTime(void) ;
#endif /* ( High_Frequency_PWM_0_KillModeMinTime) */

void High_Frequency_PWM_0_Init(void) ;
void High_Frequency_PWM_0_Enable(void) ;
void High_Frequency_PWM_0_Sleep(void) ;
void High_Frequency_PWM_0_Wakeup(void) ;
void High_Frequency_PWM_0_SaveConfig(void) ;
void High_Frequency_PWM_0_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define High_Frequency_PWM_0_INIT_PERIOD_VALUE          (500u)
#define High_Frequency_PWM_0_INIT_COMPARE_VALUE1        (250u)
#define High_Frequency_PWM_0_INIT_COMPARE_VALUE2        (63u)
#define High_Frequency_PWM_0_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    High_Frequency_PWM_0_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    High_Frequency_PWM_0_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    High_Frequency_PWM_0_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    High_Frequency_PWM_0_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define High_Frequency_PWM_0_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  High_Frequency_PWM_0_CTRL_CMPMODE2_SHIFT)
#define High_Frequency_PWM_0_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  High_Frequency_PWM_0_CTRL_CMPMODE1_SHIFT)
#define High_Frequency_PWM_0_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (High_Frequency_PWM_0_UsingFixedFunction)
   #define High_Frequency_PWM_0_PERIOD_LSB              (*(reg16 *) High_Frequency_PWM_0_PWMHW__PER0)
   #define High_Frequency_PWM_0_PERIOD_LSB_PTR          ( (reg16 *) High_Frequency_PWM_0_PWMHW__PER0)
   #define High_Frequency_PWM_0_COMPARE1_LSB            (*(reg16 *) High_Frequency_PWM_0_PWMHW__CNT_CMP0)
   #define High_Frequency_PWM_0_COMPARE1_LSB_PTR        ( (reg16 *) High_Frequency_PWM_0_PWMHW__CNT_CMP0)
   #define High_Frequency_PWM_0_COMPARE2_LSB            (0x00u)
   #define High_Frequency_PWM_0_COMPARE2_LSB_PTR        (0x00u)
   #define High_Frequency_PWM_0_COUNTER_LSB             (*(reg16 *) High_Frequency_PWM_0_PWMHW__CNT_CMP0)
   #define High_Frequency_PWM_0_COUNTER_LSB_PTR         ( (reg16 *) High_Frequency_PWM_0_PWMHW__CNT_CMP0)
   #define High_Frequency_PWM_0_CAPTURE_LSB             (*(reg16 *) High_Frequency_PWM_0_PWMHW__CAP0)
   #define High_Frequency_PWM_0_CAPTURE_LSB_PTR         ( (reg16 *) High_Frequency_PWM_0_PWMHW__CAP0)
   #define High_Frequency_PWM_0_RT1                     (*(reg8 *)  High_Frequency_PWM_0_PWMHW__RT1)
   #define High_Frequency_PWM_0_RT1_PTR                 ( (reg8 *)  High_Frequency_PWM_0_PWMHW__RT1)

#else
   #if (High_Frequency_PWM_0_Resolution == 8u) /* 8bit - PWM */

       #if(High_Frequency_PWM_0_PWMModeIsCenterAligned)
           #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (High_Frequency_PWM_0_PWMModeIsCenterAligned) */

       #define High_Frequency_PWM_0_COMPARE1_LSB        (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define High_Frequency_PWM_0_COMPARE1_LSB_PTR    ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define High_Frequency_PWM_0_COMPARE2_LSB        (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define High_Frequency_PWM_0_COMPARE2_LSB_PTR    ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define High_Frequency_PWM_0_COUNTERCAP_LSB      (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define High_Frequency_PWM_0_COUNTERCAP_LSB_PTR  ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define High_Frequency_PWM_0_COUNTER_LSB         (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define High_Frequency_PWM_0_COUNTER_LSB_PTR     ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define High_Frequency_PWM_0_CAPTURE_LSB         (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define High_Frequency_PWM_0_CAPTURE_LSB_PTR     ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(High_Frequency_PWM_0_PWMModeIsCenterAligned)
               #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (High_Frequency_PWM_0_PWMModeIsCenterAligned) */

            #define High_Frequency_PWM_0_COMPARE1_LSB       (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define High_Frequency_PWM_0_COMPARE1_LSB_PTR   ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define High_Frequency_PWM_0_COMPARE2_LSB       (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define High_Frequency_PWM_0_COMPARE2_LSB_PTR   ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define High_Frequency_PWM_0_COUNTERCAP_LSB     (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define High_Frequency_PWM_0_COUNTERCAP_LSB_PTR ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define High_Frequency_PWM_0_COUNTER_LSB        (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define High_Frequency_PWM_0_COUNTER_LSB_PTR    ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define High_Frequency_PWM_0_CAPTURE_LSB        (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define High_Frequency_PWM_0_CAPTURE_LSB_PTR    ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(High_Frequency_PWM_0_PWMModeIsCenterAligned)
               #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define High_Frequency_PWM_0_PERIOD_LSB      (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define High_Frequency_PWM_0_PERIOD_LSB_PTR  ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (High_Frequency_PWM_0_PWMModeIsCenterAligned) */

            #define High_Frequency_PWM_0_COMPARE1_LSB       (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define High_Frequency_PWM_0_COMPARE1_LSB_PTR   ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define High_Frequency_PWM_0_COMPARE2_LSB       (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define High_Frequency_PWM_0_COMPARE2_LSB_PTR   ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define High_Frequency_PWM_0_COUNTERCAP_LSB     (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define High_Frequency_PWM_0_COUNTERCAP_LSB_PTR ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define High_Frequency_PWM_0_COUNTER_LSB        (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define High_Frequency_PWM_0_COUNTER_LSB_PTR    ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define High_Frequency_PWM_0_CAPTURE_LSB        (*(reg16 *) High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define High_Frequency_PWM_0_CAPTURE_LSB_PTR    ((reg16 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define High_Frequency_PWM_0_AUX_CONTROLDP1          (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define High_Frequency_PWM_0_AUX_CONTROLDP1_PTR      ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (High_Frequency_PWM_0_Resolution == 8) */

   #define High_Frequency_PWM_0_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define High_Frequency_PWM_0_AUX_CONTROLDP0          (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define High_Frequency_PWM_0_AUX_CONTROLDP0_PTR      ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (High_Frequency_PWM_0_UsingFixedFunction) */

#if(High_Frequency_PWM_0_KillModeMinTime )
    #define High_Frequency_PWM_0_KILLMODEMINTIME        (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define High_Frequency_PWM_0_KILLMODEMINTIME_PTR    ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (High_Frequency_PWM_0_KillModeMinTime ) */

#if(High_Frequency_PWM_0_DeadBandMode == High_Frequency_PWM_0__B_PWM__DBM_256_CLOCKS)
    #define High_Frequency_PWM_0_DEADBAND_COUNT         (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define High_Frequency_PWM_0_DEADBAND_COUNT_PTR     ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define High_Frequency_PWM_0_DEADBAND_LSB_PTR       ((reg8 *)   High_Frequency_PWM_0_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define High_Frequency_PWM_0_DEADBAND_LSB           (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(High_Frequency_PWM_0_DeadBandMode == High_Frequency_PWM_0__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (High_Frequency_PWM_0_UsingFixedFunction)
        #define High_Frequency_PWM_0_DEADBAND_COUNT         (*(reg8 *)  High_Frequency_PWM_0_PWMHW__CFG0)
        #define High_Frequency_PWM_0_DEADBAND_COUNT_PTR     ((reg8 *)   High_Frequency_PWM_0_PWMHW__CFG0)
        #define High_Frequency_PWM_0_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << High_Frequency_PWM_0_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define High_Frequency_PWM_0_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define High_Frequency_PWM_0_DEADBAND_COUNT         (*(reg8 *)  High_Frequency_PWM_0_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define High_Frequency_PWM_0_DEADBAND_COUNT_PTR     ((reg8 *)   High_Frequency_PWM_0_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define High_Frequency_PWM_0_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << High_Frequency_PWM_0_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define High_Frequency_PWM_0_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (High_Frequency_PWM_0_UsingFixedFunction) */
#endif /* (High_Frequency_PWM_0_DeadBandMode == High_Frequency_PWM_0__B_PWM__DBM_256_CLOCKS) */



#if (High_Frequency_PWM_0_UsingFixedFunction)
    #define High_Frequency_PWM_0_STATUS                 (*(reg8 *) High_Frequency_PWM_0_PWMHW__SR0)
    #define High_Frequency_PWM_0_STATUS_PTR             ((reg8 *) High_Frequency_PWM_0_PWMHW__SR0)
    #define High_Frequency_PWM_0_STATUS_MASK            (*(reg8 *) High_Frequency_PWM_0_PWMHW__SR0)
    #define High_Frequency_PWM_0_STATUS_MASK_PTR        ((reg8 *) High_Frequency_PWM_0_PWMHW__SR0)
    #define High_Frequency_PWM_0_CONTROL                (*(reg8 *) High_Frequency_PWM_0_PWMHW__CFG0)
    #define High_Frequency_PWM_0_CONTROL_PTR            ((reg8 *) High_Frequency_PWM_0_PWMHW__CFG0)
    #define High_Frequency_PWM_0_CONTROL2               (*(reg8 *) High_Frequency_PWM_0_PWMHW__CFG1)
    #define High_Frequency_PWM_0_CONTROL3               (*(reg8 *) High_Frequency_PWM_0_PWMHW__CFG2)
    #define High_Frequency_PWM_0_GLOBAL_ENABLE          (*(reg8 *) High_Frequency_PWM_0_PWMHW__PM_ACT_CFG)
    #define High_Frequency_PWM_0_GLOBAL_ENABLE_PTR      ( (reg8 *) High_Frequency_PWM_0_PWMHW__PM_ACT_CFG)
    #define High_Frequency_PWM_0_GLOBAL_STBY_ENABLE     (*(reg8 *) High_Frequency_PWM_0_PWMHW__PM_STBY_CFG)
    #define High_Frequency_PWM_0_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) High_Frequency_PWM_0_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define High_Frequency_PWM_0_BLOCK_EN_MASK          (High_Frequency_PWM_0_PWMHW__PM_ACT_MSK)
    #define High_Frequency_PWM_0_BLOCK_STBY_EN_MASK     (High_Frequency_PWM_0_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define High_Frequency_PWM_0_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define High_Frequency_PWM_0_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define High_Frequency_PWM_0_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define High_Frequency_PWM_0_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define High_Frequency_PWM_0_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define High_Frequency_PWM_0_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define High_Frequency_PWM_0_CTRL_ENABLE            (uint8)((uint8)0x01u << High_Frequency_PWM_0_CTRL_ENABLE_SHIFT)
    #define High_Frequency_PWM_0_CTRL_RESET             (uint8)((uint8)0x01u << High_Frequency_PWM_0_CTRL_RESET_SHIFT)
    #define High_Frequency_PWM_0_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << High_Frequency_PWM_0_CTRL_CMPMODE2_SHIFT)
    #define High_Frequency_PWM_0_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << High_Frequency_PWM_0_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define High_Frequency_PWM_0_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define High_Frequency_PWM_0_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << High_Frequency_PWM_0_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define High_Frequency_PWM_0_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define High_Frequency_PWM_0_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define High_Frequency_PWM_0_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define High_Frequency_PWM_0_STATUS_TC_INT_EN_MASK_SHIFT            (High_Frequency_PWM_0_STATUS_TC_SHIFT - 4u)
    #define High_Frequency_PWM_0_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define High_Frequency_PWM_0_STATUS_CMP1_INT_EN_MASK_SHIFT          (High_Frequency_PWM_0_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define High_Frequency_PWM_0_STATUS_TC              (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_TC_SHIFT)
    #define High_Frequency_PWM_0_STATUS_CMP1            (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define High_Frequency_PWM_0_STATUS_TC_INT_EN_MASK              (uint8)((uint8)High_Frequency_PWM_0_STATUS_TC >> 4u)
    #define High_Frequency_PWM_0_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)High_Frequency_PWM_0_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define High_Frequency_PWM_0_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define High_Frequency_PWM_0_RT1_MASK              (uint8)((uint8)0x03u << High_Frequency_PWM_0_RT1_SHIFT)
    #define High_Frequency_PWM_0_SYNC                  (uint8)((uint8)0x03u << High_Frequency_PWM_0_RT1_SHIFT)
    #define High_Frequency_PWM_0_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define High_Frequency_PWM_0_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << High_Frequency_PWM_0_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define High_Frequency_PWM_0_SYNCDSI_EN            (uint8)((uint8)0x0Fu << High_Frequency_PWM_0_SYNCDSI_SHIFT)


#else
    #define High_Frequency_PWM_0_STATUS                (*(reg8 *)   High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define High_Frequency_PWM_0_STATUS_PTR            ((reg8 *)    High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define High_Frequency_PWM_0_STATUS_MASK           (*(reg8 *)   High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__MASK_REG)
    #define High_Frequency_PWM_0_STATUS_MASK_PTR       ((reg8 *)    High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__MASK_REG)
    #define High_Frequency_PWM_0_STATUS_AUX_CTRL       (*(reg8 *)   High_Frequency_PWM_0_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define High_Frequency_PWM_0_CONTROL               (*(reg8 *)   High_Frequency_PWM_0_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define High_Frequency_PWM_0_CONTROL_PTR           ((reg8 *)    High_Frequency_PWM_0_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define High_Frequency_PWM_0_CTRL_ENABLE_SHIFT      (0x07u)
    #define High_Frequency_PWM_0_CTRL_RESET_SHIFT       (0x06u)
    #define High_Frequency_PWM_0_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define High_Frequency_PWM_0_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define High_Frequency_PWM_0_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define High_Frequency_PWM_0_CTRL_ENABLE            (uint8)((uint8)0x01u << High_Frequency_PWM_0_CTRL_ENABLE_SHIFT)
    #define High_Frequency_PWM_0_CTRL_RESET             (uint8)((uint8)0x01u << High_Frequency_PWM_0_CTRL_RESET_SHIFT)
    #define High_Frequency_PWM_0_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << High_Frequency_PWM_0_CTRL_CMPMODE2_SHIFT)
    #define High_Frequency_PWM_0_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << High_Frequency_PWM_0_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define High_Frequency_PWM_0_STATUS_KILL_SHIFT          (0x05u)
    #define High_Frequency_PWM_0_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define High_Frequency_PWM_0_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define High_Frequency_PWM_0_STATUS_TC_SHIFT            (0x02u)
    #define High_Frequency_PWM_0_STATUS_CMP2_SHIFT          (0x01u)
    #define High_Frequency_PWM_0_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define High_Frequency_PWM_0_STATUS_KILL_INT_EN_MASK_SHIFT          (High_Frequency_PWM_0_STATUS_KILL_SHIFT)
    #define High_Frequency_PWM_0_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (High_Frequency_PWM_0_STATUS_FIFONEMPTY_SHIFT)
    #define High_Frequency_PWM_0_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (High_Frequency_PWM_0_STATUS_FIFOFULL_SHIFT)
    #define High_Frequency_PWM_0_STATUS_TC_INT_EN_MASK_SHIFT            (High_Frequency_PWM_0_STATUS_TC_SHIFT)
    #define High_Frequency_PWM_0_STATUS_CMP2_INT_EN_MASK_SHIFT          (High_Frequency_PWM_0_STATUS_CMP2_SHIFT)
    #define High_Frequency_PWM_0_STATUS_CMP1_INT_EN_MASK_SHIFT          (High_Frequency_PWM_0_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define High_Frequency_PWM_0_STATUS_KILL            (uint8)((uint8)0x00u << High_Frequency_PWM_0_STATUS_KILL_SHIFT )
    #define High_Frequency_PWM_0_STATUS_FIFOFULL        (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_FIFOFULL_SHIFT)
    #define High_Frequency_PWM_0_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_FIFONEMPTY_SHIFT)
    #define High_Frequency_PWM_0_STATUS_TC              (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_TC_SHIFT)
    #define High_Frequency_PWM_0_STATUS_CMP2            (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_CMP2_SHIFT)
    #define High_Frequency_PWM_0_STATUS_CMP1            (uint8)((uint8)0x01u << High_Frequency_PWM_0_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define High_Frequency_PWM_0_STATUS_KILL_INT_EN_MASK            (High_Frequency_PWM_0_STATUS_KILL)
    #define High_Frequency_PWM_0_STATUS_FIFOFULL_INT_EN_MASK        (High_Frequency_PWM_0_STATUS_FIFOFULL)
    #define High_Frequency_PWM_0_STATUS_FIFONEMPTY_INT_EN_MASK      (High_Frequency_PWM_0_STATUS_FIFONEMPTY)
    #define High_Frequency_PWM_0_STATUS_TC_INT_EN_MASK              (High_Frequency_PWM_0_STATUS_TC)
    #define High_Frequency_PWM_0_STATUS_CMP2_INT_EN_MASK            (High_Frequency_PWM_0_STATUS_CMP2)
    #define High_Frequency_PWM_0_STATUS_CMP1_INT_EN_MASK            (High_Frequency_PWM_0_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define High_Frequency_PWM_0_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define High_Frequency_PWM_0_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define High_Frequency_PWM_0_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define High_Frequency_PWM_0_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define High_Frequency_PWM_0_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* High_Frequency_PWM_0_UsingFixedFunction */

#endif  /* CY_PWM_High_Frequency_PWM_0_H */


/* [] END OF FILE */
