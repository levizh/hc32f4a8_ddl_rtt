/**
 *******************************************************************************
 * @file  hc32_ll_sram.h
 * @brief This file contains all the functions prototypes of the SRAM driver
 *        library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2024-09-13       CDT             First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2022-2025, Xiaohua Semiconductor Co., Ltd. All rights reserved.
 *
 * This software component is licensed by XHSC under BSD 3-Clause license
 * (the "License"); You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                    opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#ifndef __HC32_LL_SRAM_H__
#define __HC32_LL_SRAM_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ll_def.h"

#include "hc32f4xx.h"
#include "hc32f4xx_conf.h"
/**
 * @addtogroup LL_Driver
 * @{
 */

/**
 * @addtogroup LL_SRAM
 * @{
 */

#if (LL_SRAM_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup SRAM_Global_Types SRAM Global Types
 * @{
 */

/**
 * @brief SRAM ECC error inject bits structure definition
 */
typedef struct {
    uint32_t u32DataBit0_31;            /*!< data bits 0~31 */
    uint32_t u32DataBit32_63;           /*!< data bits 32~63 */
    uint32_t u32DataBit64_95;           /*!< data bits 64~95 */
    uint32_t u32DataBit96_127;          /*!< data bits 96~127 */
    uint32_t u32ECCDataBit0_8;          /*!< ECC value bits 0-8 */
} stc_sram_ecc_err_inject_bit_t;
/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup SRAM_Global_Macros SRAM Global Macros
 * @{
 */

/**
 * @defgroup SRAM_Sel SRAM Selection
 * @{
 */
#define SRAM_SRAMH              (1UL << 2U)                 /*!< SRAMH: 0x1FFE0000~0x1FFFFFFF, 128KB */
#define SRAM_SRAM123            (1UL << 0U)                 /*!< SRAM1: 0x20000000~0x2001FFFF, 128KB
                                                                 SRAM2: 0x20020000~0x2003FFFF, 128KB
                                                                 SRAM3: 0x20040000~0x20057FFF, 96KB */
#define SRAM_SRAM4              (1UL << 1U)                 /*!< SRAM4: 0x20058000~0x2005FFFF, 32KB */
#define SRAM_SRAMB              (1UL << 3U)                 /*!< SRAMB: 0x200F0000~0x200F0FFF, 4KB */
#define SRAM_SRAM_ALL           (SRAM_SRAMH | SRAM_SRAM123 | SRAM_SRAM4 | SRAM_SRAMB)
/**
 * @}
 */

/**
 * @defgroup SRAM_ECC_SRAM ECC SRAM Definition
 * @{
 */
#define SRAM_ECC_SRAM1          (1UL << 0U)
#define SRAM_ECC_SRAM2          (1UL << 1U)
#define SRAM_ECC_SRAM3          (1UL << 2U)
#define SRAM_ECC_SRAM4          (1UL << 3U)
#define SRAM_ECC_SRAMB          (1UL << 4U)
#define SRAM_ECC_SRAMH          (1UL << 5U)
#define SRAM_ECC_CACHE_RAM      (1UL << 6U)
#define SRAM_ECC_39EIBIT_ALL    (SRAM_ECC_SRAM1 | SRAM_ECC_SRAM2 | SRAM_ECC_SRAM3 | SRAM_ECC_SRAM4 | SRAM_ECC_SRAMB | \
                                 SRAM_ECC_SRAMH)
#define SRAM_ECC_137EIBIT_ALL   (SRAM_ECC_CACHE_RAM)
#define SRAM_ECC_SRAM_ALL       (SRAM_ECC_39EIBIT_ALL | SRAM_ECC_137EIBIT_ALL)
/**
 * @}
 */

/**
 * @defgroup SRAM_Access_Wait_Cycle SRAM Access Wait Cycle
 * @{
 */
#define SRAM_WAIT_CYCLE0        (0U)                        /*!< Wait 0 CPU cycle. */
#define SRAM_WAIT_CYCLE1        (1U)                        /*!< Wait 1 CPU cycle. */
#define SRAM_WAIT_CYCLE2        (2U)                        /*!< Wait 2 CPU cycles. */
#define SRAM_WAIT_CYCLE3        (3U)                        /*!< Wait 3 CPU cycles. */
#define SRAM_WAIT_CYCLE4        (4U)                        /*!< Wait 4 CPU cycles. */
#define SRAM_WAIT_CYCLE5        (5U)                        /*!< Wait 5 CPU cycles. */
#define SRAM_WAIT_CYCLE6        (6U)                        /*!< Wait 6 CPU cycles. */
#define SRAM_WAIT_CYCLE7        (7U)                        /*!< Wait 7 CPU cycles. */
/**
 * @}
 */

/**
 * @defgroup SRAM_Exception_Type SRAM exception type
 * @note Even-parity check error, ECC check error.
 * @{
 */
#define SRAM_EXP_TYPE_NMI               (0UL)
#define SRAM_EXP_TYPE_RST               (1UL)
/**
 * @}
 */

/**
 * @defgroup SRAM_Check_SRAM SRAM check sram
 * @{
 */
#define SRAM_CHECK_SRAM1                (SRAMC_CKCR_SRAM1_ECCOAD)
#define SRAM_CHECK_SRAM2                (SRAMC_CKCR_SRAM2_ECCOAD)
#define SRAM_CHECK_SRAM3                (SRAMC_CKCR_SRAM3_ECCOAD)
#define SRAM_CHECK_SRAM4                (SRAMC_CKCR_SRAM4_ECCOAD)
#define SRAM_CHECK_SRAMB                (SRAMC_CKCR_SRAMB_ECCOAD)
#define SRAM_CHECK_SRAMH                (SRAMC_CKCR_SRAMH_ECCOAD)
#define SRAM_CHECK_CACHE_RAM            (SRAMC_CKCR_CACHE_ECCOAD)
#define SRAM_CHECK_SRAM_ALL             (SRAM_CHECK_SRAMB | SRAM_CHECK_SRAM4 | SRAM_CHECK_SRAM3 | SRAM_CHECK_SRAM2 | \
                                         SRAM_CHECK_SRAM1 | SRAM_CHECK_SRAMH | SRAM_CHECK_CACHE_RAM)
/**
 * @}
 */

/**
 * @defgroup SRAM_ECC_Mode SRAM ECC Mode
 * @note     XX_INVD: The ECC mode is invalid
 *           XX_MD1:  When 1-bit error occurs, ECC error corrects. No 1-bit-error status flag setting, no interrupt or reset.
 *                    When 2-bit error occurs, ECC error detects. 2-bit-error status flag sets and interrupt or reset occurs.
 *           XX_MD2:  When 1-bit error occurs, ECC error corrects. 1-bit-error status flag sets, no interrupt or reset.
 *                    When 2-bit error occurs, ECC error detects. 2-bit-error status flag sets and interrupt or reset occurs.
 *           XX_MD3:  When 1-bit error occurs, ECC error corrects. 1-bit-error status flag sets and interrupt or reset occurs.
 *                    When 2-bit error occurs, ECC error detects. 2-bit-error status flag sets and interrupt or reset occurs.
 * @{
 */
#define SRAM_SRAM1_ECC_INVD             (0x0UL)
#define SRAM_SRAM1_ECC_MD1              (SRAMC_CKCR_SRAM1_ECCMOD_0)
#define SRAM_SRAM1_ECC_MD2              (SRAMC_CKCR_SRAM1_ECCMOD_1)
#define SRAM_SRAM1_ECC_MD3              (SRAMC_CKCR_SRAM1_ECCMOD)
#define SRAM_SRAM2_ECC_INVD             (0x0UL)
#define SRAM_SRAM2_ECC_MD1              (SRAMC_CKCR_SRAM2_ECCMOD_0)
#define SRAM_SRAM2_ECC_MD2              (SRAMC_CKCR_SRAM2_ECCMOD_1)
#define SRAM_SRAM2_ECC_MD3              (SRAMC_CKCR_SRAM2_ECCMOD)
#define SRAM_SRAM3_ECC_INVD             (0x0UL)
#define SRAM_SRAM3_ECC_MD1              (SRAMC_CKCR_SRAM3_ECCMOD_0)
#define SRAM_SRAM3_ECC_MD2              (SRAMC_CKCR_SRAM3_ECCMOD_1)
#define SRAM_SRAM3_ECC_MD3              (SRAMC_CKCR_SRAM3_ECCMOD)
#define SRAM_SRAM4_ECC_INVD             (0x0UL)
#define SRAM_SRAM4_ECC_MD1              (SRAMC_CKCR_SRAM4_ECCMOD_0)
#define SRAM_SRAM4_ECC_MD2              (SRAMC_CKCR_SRAM4_ECCMOD_1)
#define SRAM_SRAM4_ECC_MD3              (SRAMC_CKCR_SRAM4_ECCMOD)
#define SRAM_SRAMB_ECC_INVD             (0x0UL)
#define SRAM_SRAMB_ECC_MD1              (SRAMC_CKCR_SRAMB_ECCMOD_0)
#define SRAM_SRAMB_ECC_MD2              (SRAMC_CKCR_SRAMB_ECCMOD_1)
#define SRAM_SRAMB_ECC_MD3              (SRAMC_CKCR_SRAMB_ECCMOD)
#define SRAM_SRAMH_ECC_INVD             (0x0UL)
#define SRAM_SRAMH_ECC_MD1              (SRAMC_CKCR_SRAMH_ECCMOD_0)
#define SRAM_SRAMH_ECC_MD2              (SRAMC_CKCR_SRAMH_ECCMOD_1)
#define SRAM_SRAMH_ECC_MD3              (SRAMC_CKCR_SRAMH_ECCMOD)
#define SRAM_CACHE_ECC_INVD             (0x0UL)
#define SRAM_CACHE_ECC_MD1              (SRAMC_CKCR_CACHE_ECCMOD_0)
#define SRAM_CACHE_ECC_MD2              (SRAMC_CKCR_CACHE_ECCMOD_1)
#define SRAM_CACHE_ECC_MD3              (SRAMC_CKCR_CACHE_ECCMOD)
#define SRAM_ECC_MD_INVD                (SRAM_SRAM1_ECC_INVD & SRAM_SRAM2_ECC_INVD & SRAM_SRAM3_ECC_INVD & \
                                         SRAM_SRAM4_ECC_INVD & SRAM_SRAMB_ECC_INVD & SRAM_SRAMH_ECC_INVD & \
                                         SRAM_CACHE_ECC_INVD)
/**
 * @}
 */

/**
 * @defgroup SRAM_Err_Status_Flag SRAM Error Status Flag
 * @{
 */
#define SRAM_FLAG_SRAM1_1ERR            (SRAMC_CKSR_SRAM1_1ERR)     /*!< SRAM1 ECC 1-bit error. */
#define SRAM_FLAG_SRAM1_2ERR            (SRAMC_CKSR_SRAM1_2ERR)     /*!< SRAM1 ECC 2-bit error. */
#define SRAM_FLAG_SRAM2_1ERR            (SRAMC_CKSR_SRAM2_1ERR)     /*!< SRAM2 ECC 1-bit error. */
#define SRAM_FLAG_SRAM2_2ERR            (SRAMC_CKSR_SRAM2_2ERR)     /*!< SRAM2 ECC 2-bit error. */
#define SRAM_FLAG_SRAM3_1ERR            (SRAMC_CKSR_SRAM3_1ERR)     /*!< SRAM3 ECC 1-bit error. */
#define SRAM_FLAG_SRAM3_2ERR            (SRAMC_CKSR_SRAM3_2ERR)     /*!< SRAM3 ECC 2-bit error. */
#define SRAM_FLAG_SRAM4_1ERR            (SRAMC_CKSR_SRAM4_1ERR)     /*!< SRAM4 ECC 1-bit error. */
#define SRAM_FLAG_SRAM4_2ERR            (SRAMC_CKSR_SRAM4_2ERR)     /*!< SRAM4 ECC 2-bit error. */
#define SRAM_FLAG_SRAMH_1ERR            (SRAMC_CKSR_SRAMH_1ERR)     /*!< SRAMH ECC 1-bit error. */
#define SRAM_FLAG_SRAMH_2ERR            (SRAMC_CKSR_SRAMH_2ERR)     /*!< SRAMH ECC 2-bit error. */
#define SRAM_FLAG_SRAMB_1ERR            (SRAMC_CKSR_SRAMB_1ERR)     /*!< SRAMB ECC 1-bit error. */
#define SRAM_FLAG_SRAMB_2ERR            (SRAMC_CKSR_SRAMB_2ERR)     /*!< SRAMB ECC 2-bit error. */
#define SRAM_FLAG_CACHE_1ERR            (SRAMC_CKSR_CACHE_1ERR)     /*!< Cache ECC 1-bit error. */
#define SRAM_FLAG_CACHE_2ERR            (SRAMC_CKSR_CACHE_2ERR)     /*!< Cache ECC 2-bit error. */
#define SRAM_FLAG_ALL                   (0x0007FEF0UL)
/**
 * @}
 */

/**
 * @defgroup SRAM_Reg_Protect_Key SRAM Register Protect Key
 * @{
 */
#define SRAM_REG_LOCK_KEY               (0x76U)
#define SRAM_REG_UNLOCK_KEY             (0x77U)
/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup SRAM_Global_Functions
 * @{
 */

/**
 * @brief  Lock SRAM registers, write protect.
 * @param  None
 * @retval None
 */
__STATIC_INLINE void SRAM_REG_Lock(void)
{
    WRITE_REG32(CM_SRAMC->WTPR, SRAM_REG_LOCK_KEY);
    WRITE_REG32(CM_SRAMC->CKPR, SRAM_REG_LOCK_KEY);
}

/**
 * @brief  Unlock SRAM registers, write enable.
 * @param  None
 * @retval None
 */
__STATIC_INLINE void SRAM_REG_Unlock(void)
{
    WRITE_REG32(CM_SRAMC->WTPR, SRAM_REG_UNLOCK_KEY);
    WRITE_REG32(CM_SRAMC->CKPR, SRAM_REG_UNLOCK_KEY);
}

void SRAM_Init(void);
void SRAM_DeInit(void);

void SRAM_REG_Lock(void);
void SRAM_REG_Unlock(void);

void SRAM_SetWaitCycle(uint32_t u32SramSel, uint32_t u32WriteCycle, uint32_t u32ReadCycle);
void SRAM_SetEccMode(uint32_t u32EccSram, uint32_t u32EccMode);
void SRAM_SetExceptionType(uint32_t u32CheckSram, uint32_t u32ExceptionType);

en_flag_status_t SRAM_GetStatus(uint32_t u32Flag);
void SRAM_ClearStatus(uint32_t u32Flag);

void SRAM_ErrorInjectCmd(uint32_t u32EccSram, en_functional_state_t enNewState);
void SRAM_ErrorInjectBitCmd(uint32_t u32EccSram, uint64_t u64BitSel, en_functional_state_t enNewState);
uint32_t SRAM_GetEccErrorAddr(uint32_t u32EccSram);

int32_t SRAM_Cache_ErrorInjectBitStructInit(stc_sram_ecc_err_inject_bit_t *pstcBitSel);
void SRAM_Cache_ErrorInjectBitCmd(const stc_sram_ecc_err_inject_bit_t *pstcBitSel, en_functional_state_t enNewState);

/**
 * @}
 */

#endif /* LL_SRAM_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32_LL_SRAM_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
