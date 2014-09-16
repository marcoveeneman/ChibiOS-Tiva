/*
 * TM4C123x drivers configuration.
 * The following settings override the default settings present in
 * the various device driver implementation headers.
 * Note that the settings for each driver only have effect if the whole
 * driver is enabled in halconf.h.
 *
 * IRQ priorities:
 * 7...0       Lowest...Highest.
 */

#define TM4C123x_MCUCONF

/*
 * HAL driver system settings.
 */
#define TIVA_OSCSRC                         TIVA_RCC2_OSCSRC2_MOSC
#define TIVA_MOSC_ENABLE                    TRUE
#define TIVA_DIV400_VALUE                   1
#define TIVA_SYSDIV_VALUE                   2
#define TIVA_USESYSDIV_ENABLE               FALSE
#define TIVA_SYSDIV2LSB_ENABLE              FALSE
#define TIVA_BYPASS_VALUE                   0

/*
 * GPIO Lock register password: "LOCK"
 */
#define TIVA_GPIO_LOCK_PWD                  0x4C4F434B

/*
 * SERIAL driver system settings.
 */
#define TIVA_SERIAL_USE_UART0               TRUE
#define TIVA_SERIAL_USE_UART1               FALSE
#define TIVA_SERIAL_USE_UART2               FALSE
#define TIVA_SERIAL_USE_UART3               FALSE
#define TIVA_SERIAL_USE_UART4               FALSE
#define TIVA_SERIAL_USE_UART5               FALSE
#define TIVA_SERIAL_USE_UART6               FALSE
#define TIVA_SERIAL_USE_UART7               FALSE
#define TIVA_SERIAL_UART0_PRIORITY          5
#define TIVA_SERIAL_UART1_PRIORITY          5
#define TIVA_SERIAL_UART2_PRIORITY          5
#define TIVA_SERIAL_UART3_PRIORITY          5
#define TIVA_SERIAL_UART4_PRIORITY          5
#define TIVA_SERIAL_UART5_PRIORITY          5
#define TIVA_SERIAL_UART6_PRIORITY          5
#define TIVA_SERIAL_UART7_PRIORITY          5

/*
 * ST driver system settings.
 */
#define TIVA_ST_IRQ_PRIORITY                2
#define TIVA_ST_USE_WIDE_TIMER              TRUE
#define TIVA_ST_TIMER_NUMBER                5
#define TIVA_ST_TIMER_LETTER                A
