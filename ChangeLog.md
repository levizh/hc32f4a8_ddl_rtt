# Update History
------
## V1.0.0  Jan 20, 2025
#### documents
#### drivers
- ##### bsp/ev_hc32f4a8_lqfp176
  - Modify XTAL/XTAL32 pins definition
  - Add rtl8201 bsp
  - Optimize BSP_TCA9539_Reset function
- ##### cmsis/Device
  - Modify TMR6 registers
- ##### hc32_ll_driver
  - **generic**
    - Modify version as Rev1.0.0
  - **clk**
    - Delete group definition for CLK_FREQ
  - **crc**
    - Modify interface of AccumulateData and Calculate functions
  - **dmc**
    - Remove sample clock
  - **efm**
    - Add const before buffer pointer to cater top-level calls
    - Bug Fixed # judge the EFM_FLAG_OPTEND whether set o not before clear EFM_FLAG_OPTEND
    - Remap the sector number parameter of EFM_SingleSectorOperateCmd based on SWAP and OTP status
  - **emb**
    - Delete duplicate macro-condition
  - **eth**
    - Extract the relevant code of PHY
  - **hash**
    - Fixed HASH_HMAC_Calculate function
    - Optimize HASH_DoCalc function
  - **i2c**
    - Rename related to SMBus Alert Response Address
  - **icg**
    - Set ICG3 reserved bit to 1
    -
  - **interrupts**
    - Add INTC_IrqInstallHandle()
  - **nfc**
    - Optimize function EXMC_NFC_ReadId
  - **pwc**
    - Add macros for PWC VBAT flag
    - Modify PWC_VBAT_GetVoltageStatus() to PWC_VBAT_GetStatus(), add PWC_VBAT_ClearStatus()
  - **qspi**
    - Fix QSPI_ClearStatus()
  - **usart**
    - Add assert for pvBuf pointer alignment for data width 9bit
  - **usb**
    - Modify API usb_wrpkt & usb_rdpkt for C-STAT
    - Add API usb_deinit()
#### midwares
- ##### hc32/iap
  - Modify u8FrameData to 4-byte alignment
  - Fix cppcheck warning
- ##### hc32/iec60730_class_b_stl
  - Add compiler macros pre-processor: GCC and AC6
  - Refined STL_ConsoleOutputChar()
  - Assign m_pu32MarchRAM using the variable m_au32MarchRAM
- ##### hc32/ring_buffer
  - Add function: BUF_UpdateInputIndex
#### projects
- ##### ev_hc32f4a8_lqfp176/applications
  - **functional_safety/iec60730_class_b**
    - Add BSP clock initialization
    - Replace peripheral WDT with SWDT to avoid dependencies on the system clock
  - **iap/iap_boot**
    - Modify XTAL pins definition
  - **iap/iap_ymodem_boot**
    - Modify XTAL pins definition
  - **usb/usb_dev_cdc**
    - Optimize print information
  - **usb/usb_dev_cdc_msc**
    - Add usb_dev_cdc_msc application
    - Optimize print information
    - Update for new SDIOC midwares
  - **usb/usb_dev_hid_cdc**
    - Optimize print information
  - **usb/usb_dev_hid_custom**
    - Optimize print information
  - **usb/usb_dev_hid_msc**
    - Add usb_dev_hid_msc application
    - Optimize print information
    - Update for new SDIOC midwares
  - **usb/usb_dev_mouse**
    - Optimize print information
  - **usb/usb_dev_msc**
    - Add usb_dev_msc application
    - Optimize print information
    - Update for new SDIOC midwares
  - **usb/usb_host_cdc**
    - Optimize print information
  - **usb/usb_host_mouse_kb**
    - Optimize print information
  - **usb/usb_host_msc**
    - Optimize print information
- ##### ev_hc32f4a8_lqfp176/examples
  - **adc/adc_awd**
    - Modify macro TMR0_CMP_VAL value
  - **adc/adc_hard_trigger**
    - Modify macro TMR0_CMP_VAL value
  - **can/can_fd**
    - Example optimized.
  - **crc/crc_hw_encode_sw_check**
    - Fix cppcheck warning
  - **dac/dac_base**
    - Increase the amplitude of sine
  - **dac/dac_sync_mode**
    - Increase the amplitude of sine
  - **dmac/dmac_channel_reconfig**
    - Optimize example for flow timing
  - **dvp/dvp_camera_display**
    - Delete the initialization of key and led
  - **eth/eth_loopback**
    - Strip PHY operation code into BSP file
    - Add high driver for ETH output pin
    - Delete interrupt codes of RMII interface
  - **eth/eth_pps_output**
    - Strip PHY operation code into BSP file
  - **eth/eth_twoboards**
    - Optimize the init process of ETH
    - Add high driver for ETH output pin
    - Strip PHY operation code into BSP file
  - **exmc/exmc_dmc_sdram_w9825g6kh_dma**
    - Add exmc_dmc_sdram_w9825g6kh_dma example
  - **exmc/exmc_sdram_sram**
    - Add led toggle for Indicative function
  - **exmc/exmc_smc_sram_is62wv51216_dma**
    - Add exmc_smc_sram_is62wv51216_dma example
  - **gpio/gpio_input**
    - Init KEY5 pin to PIN_PU_ON
  - **gpio/gpio_output**
    - Modify TMR6 registers
  - **hash/hash_hmac**
    - Delete interrupt mode
  - **i2s/i2s_play_audio**
    - Remove the configuration of unused pin
  - **intc/intc_extint_key**
    - Integrate global, group, share interrupt in one project
  - **rtc/rtc_calendar**
    - Use PWC_VBAT_GetStatus() judge VBAT area status
  - **spi/spi_dma**
    - Change SPI1 to SPI6
  - **spi/spi_dma_llp**
    - Add spi_dma_llp example
  - **spi/spi_int**
    - Change SPI1 to SPI6
  - **spi/spi_polling**
    - Change SPI1 to SPI6
  - **sram/sram_cache_error_check**
    - Fix bug for high optimization
  - **timer0/timer0_capture**
    - Change Timer0 interrupt priority to (DDL_IRQ_PRIO_DEFAULT - 1U)
  - **usart/usart_uart_dma**
    - Refine example
    - Add usart_uart_dma example
#### utils
------
## Beta1.0.0  Sep 13, 2024
- Initial release.
