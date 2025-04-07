/**
 *******************************************************************************
 * @file  hc32_ll_crc.h
 * @brief This file contains all the functions prototypes of the CRC driver
 *        library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2024-09-13       CDT             First version
   2024-11-08       CDT             Modify interface of AccumulateData and Calculate functions
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
#ifndef __HC32_LL_CRC_H__
#define __HC32_LL_CRC_H__

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
 * @addtogroup LL_CRC
 * @{
 */

#if (LL_CRC_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup CRC_Global_Types CRC Global Types
 * @{
 */

/**
 * @brief CRC initialization structure definition
 */
typedef struct {
    uint32_t u32Protocol;   /*!< Specifies CRC Protocol.
                                 This parameter can be a value of @ref CRC_Protocol_Control_Bit */
    uint64_t u64InitValue;  /*!< Specifies initial CRC value.
                                 This parameter can be CRC_INIT_VALUE_DEFAULT @ref CRC_Init_Value_Default */
} stc_crc_init_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup CRC_Global_Macros CRC Global Macros
 * @{
 */

/**
 * @defgroup CRC_Protocol_Control_Bit CRC Protocol Control Bit
 * @{
 */
#define CRC_CRC16                   (0x0UL)
#define CRC_CRC32                   (CRC_CR_CR)
#define CRC_CRC16_CCITT             (0x1UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_CCITT_FALSE       (0x2UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_XMODE             (0x3UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_IBM               (0x4UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_MAXIM             (0x5UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_USB               (0x6UL << CRC_CR_SELECT_POS)
#define CRC_CRC16_MODBUS            (0x7UL << CRC_CR_SELECT_POS)
#define CRC_CRC32_MPEG2             ((0x1UL << CRC_CR_SELECT_POS) | CRC_CR_CR)
#define CRC_CRC64_ISO               ((0x2UL << CRC_CR_SELECT_POS) | CRC_CR_CR)
/**
 * @}
 */

/**
 * @defgroup CRC_DATA_Bit_Width CRC Data Bit Width
 * @{
 */
#define CRC_DATA_WIDTH_8BIT         (1U)
#define CRC_DATA_WIDTH_16BIT        (2U)
#define CRC_DATA_WIDTH_32BIT        (4U)
/**
 * @}
 */

/**
 * @defgroup CRC_Init_Value_Default CRC Default Computation Initialization Value
 * @{
 */
#define CRC_INIT_VALUE_DEFAULT      (0xFFFFFFFFUL)
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
 * @addtogroup CRC_Global_Functions
 * @{
 */
int32_t CRC_StructInit(stc_crc_init_t *pstcCrcInit);
int32_t CRC_Init(const stc_crc_init_t *pstcCrcInit);
int32_t CRC_DeInit(void);

uint64_t CRC_GetResult(void);
void CRC_SetInitValue(uint64_t u64Value);

en_flag_status_t CRC_GetResultStatus(void);

int32_t CRC_CRC16_AccumulateData(uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint16_t *pu16Out);
int32_t CRC_CRC16_Calculate(uint16_t u16InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint16_t *pu16Out);
en_flag_status_t CRC_CRC16_CheckData(uint16_t u16InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint16_t u16ExpectValue);
en_flag_status_t CRC_CRC16_GetCheckResult(uint16_t u16ExpectValue);

int32_t CRC_CRC32_AccumulateData(uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint32_t *pu32Out);
int32_t CRC_CRC32_Calculate(uint32_t u32InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint32_t *pu32Out);
en_flag_status_t CRC_CRC32_CheckData(uint32_t u32InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint32_t u32ExpectValue);
en_flag_status_t CRC_CRC32_GetCheckResult(uint32_t u32ExpectValue);

int32_t CRC_CRC64_AccumulateData(uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint64_t *pu64Out);
int32_t CRC_CRC64_Calculate(uint64_t u64InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint64_t *pu64Out);
en_flag_status_t CRC_CRC64_CheckData(uint64_t u64InitValue, uint8_t u8DataWidth, const void *pvData, uint32_t u32Len, uint64_t u64ExpectValue);
en_flag_status_t CRC_CRC64_GetCheckResult(uint64_t u64ExpectValue);

/**
 * @}
 */

#endif /* LL_CRC_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32_LL_CRC_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
