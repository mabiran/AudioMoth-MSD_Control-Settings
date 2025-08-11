/****************************************************************************
 * pinouts.h
 * openacousticdevices.info
 * June 2017
 *****************************************************************************/

#ifndef PINOUTS_WG380_H_
#define PINOUTS_WG380_H_

/* Mass Storage Device Enable GPIO - On  */

/* PF1/DBG_SWDIO#0,1,2,3/GPIO_EM4WU3/I2C0_SCL#5/LETIM0_OUT1#2/LEU0_RX#3/TIM0_CC1#5/US1_CS#2 */

#define MSD_EN_GPIOPORT                         gpioPortF
#define MSD_EN_PIN                              1

/* MIC VOLTAGE */

/* VREF Enable - Enables sampling of the current reference voltage, to determine if it is sufficient. */

/* PA11/EBI_HSNC#0,1,2 */

#define VREF_GPIOPORT                           gpioPortA
#define VREF_EN                                 11

/* BATTERY MONITORING */

#define BAT_MON_GPIOPORT                        gpioPortC
#define BAT_MON_EN                              3

/* LED GPIO */

#define LED_GPIOPORT                            gpioPortC
#define GREEN_PIN                               5
#define RED_PIN                                 4

/* Button GPIO */

#define SWITCH_GPIOPORT                         gpioPortC
#define SWITCH_PIN                              6

/* USB GPIO */

#define USB_GPIOPORT                            gpioPortD
#define USB_PIN                                 8

#define SRAMEN_GPIOPORT                         gpioPortD
#define SRAM_ENABLE_N                           11

/* SD GPIO */

#define MICROSD_HI_SPI_FREQ                     12000000
#define MICROSD_LO_SPI_FREQ                     100000

#define MICROSD_USART                           USART2
#define MICROSD_LOC                             USART_ROUTE_LOCATION_LOC1
#define MICROSD_CMUCLOCK                        cmuClock_USART2

#define SDEN_GPIOPORT                           gpioPortD
#define SD_ENABLE_N                             12

#define MICROSD_GPIOPORT                        gpioPortB
#define MICROSD_MOSIPIN                         3
#define MICROSD_MISOPIN                         4
#define MICROSD_CSPIN                           6
#define MICROSD_CLKPIN                          5

/* MIC VOLTAGE */

#define VMIC_GPIOPORT                           gpioPortE
#define VMIC_EN_N                               0

/* MIC VOLTAGE */

#define USB_DATA_GPIOPORT                       gpioPortF
#define USB_P                                   11

/* EBI Pinouts*/

#define EBI_GPIOPORT_A                          gpioPortA
#define EBI_AD08                                15
#define EBI_AD09                                0
#define EBI_AD10                                1
#define EBI_AD11                                2
#define EBI_AD12                                3
#define EBI_AD13                                4
#define EBI_AD14                                5
#define EBI_AD15                                6

#define EBI_GPIOPORT_E                          gpioPortE
#define EBI_AD00                                8
#define EBI_AD01                                9
#define EBI_AD02                                10
#define EBI_AD03                                11
#define EBI_AD04                                12
#define EBI_AD05                                13
#define EBI_AD06                                14
#define EBI_AD07                                15
#define EBI_A08                                 1
#define EBI_A11                                 4
#define EBI_A12                                 5
#define EBI_A13                                 6
#define EBI_A14                                 7

#define EBI_GPIOPORT_B                          gpioPortB
#define EBI_A16                                 0
#define EBI_A17                                 1
#define EBI_A18                                 2
#define EBI_A19                                 3
#define EBI_A20                                 4
#define EBI_A21                                 5
#define EBI_A22                                 6

#define EBI_GPIOPORT_C                          gpioPortC
#define EBI_A15                                 8
#define EBI_A09                                 9
#define EBI_A10                                 10
#define EBI_A23                                 0
#define EBI_A24                                 1

#define EBI_GPIOPORT_D                          gpioPortD
#define EBI_CSEL1                               9
#define EBI_CSEL2                               10

#define EBI_GPIOPORT_F                          gpioPortF
#define EBI_OE                                  9
#define EBI_WE                                  8


/*  GPIO pin signal entry*/
#define GPIO_GPIOPORT                           gpioPortB
#define GPIO_PIN_PB10                              10

#endif