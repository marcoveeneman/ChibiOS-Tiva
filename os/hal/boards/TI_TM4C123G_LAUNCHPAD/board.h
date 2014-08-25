#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for Texas Instruments TM4C123G Launchpad Board.
 */

/*
 * Board identifier.
 */
#define BOARD_TI_TM4C123G_LAUNCHPAD
#define BOARD_NAME              "Texas Instruments TM4C123G Launchpad"

/*
 * MCU type
 */
#define TM4C123G

/*
 * Board oscillators-related settings.
 */
#define TIVA_XTAL_VALUE         16000000

/*
 * IO pins assignments.
 */
#define GPIOA_UART0_RX          0
#define GPIOA_UART0_TX          1
#define GPIOA_PIN2              2
#define GPIOA_PIN3              3
#define GPIOA_PIN4              4
#define GPIOA_PIN5              5
#define GPIOA_PIN6              6
#define GPIOA_PIN7              7

#define GPIOB_PIN0              0
#define GPIOB_PIN1              1
#define GPIOB_PIN2              2
#define GPIOB_PIN3              3
#define GPIOB_PIN4              4
#define GPIOB_PIN5              5
#define GPIOB_PIN6              6
#define GPIOB_PIN7              7

#define GPIOC_TCK_SWCLK         0
#define GPIOC_TMS_SWDIO         1
#define GPIOC_TDI               2
#define GPIOC_TDO_SWO           3
#define GPIOC_PIN4              4
#define GPIOC_PIN5              5
#define GPIOC_PIN6              6
#define GPIOC_PIN7              7

#define GPIOD_PIN0              0
#define GPIOD_PIN1              1
#define GPIOD_PIN2              2
#define GPIOD_PIN3              3
#define GPIOD_PIN4              4
#define GPIOD_PIN5              5
#define GPIOD_PIN6              6
#define GPIOD_PIN7              7

#define GPIOE_PIN0              0
#define GPIOE_PIN1              1
#define GPIOE_PIN2              2
#define GPIOE_PIN3              3
#define GPIOE_PIN4              4
#define GPIOE_PIN5              5
#define GPIOE_PIN6              6
#define GPIOE_PIN7              7

#define GPIOF_SW2               0
#define GPIOF_LED_RED           1
#define GPIOF_LED_BLUE          2
#define GPIOF_LED_GREEN         3
#define GPIOF_SW1               4
#define GPIOF_PIN5              5
#define GPIOF_PIN6              6
#define GPIOF_PIN7              7

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 */
#define VAL_GPIOA_DATA          0b00000000
#define VAL_GPIOA_DIR           0b00000000
#define VAL_GPIOA_AFSEL         0b00000011
#define VAL_GPIOA_DR2R          0b11111111
#define VAL_GPIOA_DR4R          0b00000000
#define VAL_GPIOA_DR8R          0b00000000
#define VAL_GPIOA_ODR           0b00000000
#define VAL_GPIOA_PUR           0b00000000
#define VAL_GPIOA_PDR           0b00000000
#define VAL_GPIOA_SLR           0b00000000
#define VAL_GPIOA_DEN           0b11111111
#define VAL_GPIOA_AMSEL         0b0000
#define VAL_GPIOA_PCTL          0x00000011

#define VAL_GPIOB_DATA          0b00000000
#define VAL_GPIOB_DIR           0b00000000
#define VAL_GPIOB_AFSEL         0b00001100
#define VAL_GPIOB_DR2R          0b11111111
#define VAL_GPIOB_DR4R          0b00000000
#define VAL_GPIOB_DR8R          0b00000000
#define VAL_GPIOB_ODR           0b00001000
#define VAL_GPIOB_PUR           0b00000000
#define VAL_GPIOB_PDR           0b00000000
#define VAL_GPIOB_SLR           0b00000000
#define VAL_GPIOB_DEN           0b11111111
#define VAL_GPIOB_AMSEL         0b0000
#define VAL_GPIOB_PCTL          0x00003300

#define VAL_GPIOC_DATA          0b00000000
#define VAL_GPIOC_DIR           0b00001000
#define VAL_GPIOC_AFSEL         0b00001111
#define VAL_GPIOC_DR2R          0b11111111
#define VAL_GPIOC_DR4R          0b00000000
#define VAL_GPIOC_DR8R          0b00000000
#define VAL_GPIOC_ODR           0b00000000
#define VAL_GPIOC_PUR           0b00001111
#define VAL_GPIOC_PDR           0b00000000
#define VAL_GPIOC_SLR           0b00000000
#define VAL_GPIOC_DEN           0b11111111
#define VAL_GPIOC_AMSEL         0b0000
#define VAL_GPIOC_PCTL          0x00001111

#define VAL_GPIOD_DATA          0b00000000
#define VAL_GPIOD_DIR           0b00000000
#define VAL_GPIOD_AFSEL         0b00000000
#define VAL_GPIOD_DR2R          0b11111111
#define VAL_GPIOD_DR4R          0b00000000
#define VAL_GPIOD_DR8R          0b00000000
#define VAL_GPIOD_ODR           0b00000000
#define VAL_GPIOD_PUR           0b00000000
#define VAL_GPIOD_PDR           0b00000000
#define VAL_GPIOD_SLR           0b00000000
#define VAL_GPIOD_DEN           0b11111111
#define VAL_GPIOD_AMSEL         0b0000
#define VAL_GPIOD_PCTL          0x00000000

#define VAL_GPIOE_DATA          0b00000000
#define VAL_GPIOE_DIR           0b00000000
#define VAL_GPIOE_AFSEL         0b00000000
#define VAL_GPIOE_DR2R          0b11111111
#define VAL_GPIOE_DR4R          0b00000000
#define VAL_GPIOE_DR8R          0b00000000
#define VAL_GPIOE_ODR           0b00000000
#define VAL_GPIOE_PUR           0b00000000
#define VAL_GPIOE_PDR           0b00000000
#define VAL_GPIOE_SLR           0b00000000
#define VAL_GPIOE_DEN           0b11111111
#define VAL_GPIOE_AMSEL         0b0000
#define VAL_GPIOE_PCTL          0x00000000

#define VAL_GPIOF_DATA          0b00000000
#define VAL_GPIOF_DIR           0b00001110
#define VAL_GPIOF_AFSEL         0b00000000
#define VAL_GPIOF_DR2R          0b11111111
#define VAL_GPIOF_DR4R          0b00000000
#define VAL_GPIOF_DR8R          0b00000000
#define VAL_GPIOF_ODR           0b00000000
#define VAL_GPIOF_PUR           0b00010001
#define VAL_GPIOF_PDR           0b00000000
#define VAL_GPIOF_SLR           0b00000000
#define VAL_GPIOF_DEN           0b11111111
#define VAL_GPIOF_AMSEL         0b0000
#define VAL_GPIOF_PCTL          0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
