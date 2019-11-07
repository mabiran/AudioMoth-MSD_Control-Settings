/****************************************************************************
 * usbconfig.h
 * openacousticdevices.info
 * June 2017
 *****************************************************************************/

#ifndef __USBCONFIG_H
#define __USBCONFIG_H

/* Compile stack for device mode */

#define USB_DEVICE

/* Select TIMER0 to be used by the USB stack. This timer must not be used by the application */

#define USB_TIMER               USB_TIMER0

/* Endpoint for USB data IN  (device to host) */

/****************************************************************************
**                                                                         **
** Specify total number of endpoints used (in addition to EP0).            **
**                                                                         **
*****************************************************************************/

/* Specify number of endpoints used (in addition to EP0) */
#define NUM_EP_USED_HID         2
#define NUM_EP_USED_MSD         2
#define NUM_EP_USED             (NUM_EP_USED_HID + NUM_EP_USED_MSD)

#define EP_IN_1                 0x81
#define EP_IN_2                 0x82

/* Endpoint for USB data OUT (host to device) */

#define EP_OUT_1                0x01
#define EP_OUT_2                0x02

#define MSD_INTERFACE_NO        1
#define MSD_BULK_IN             EP_IN_2
#define MSD_BULK_OUT            EP_OUT_2
#define MSD_FLUSH_TIMER_ID      ( 0 )

/* Select the clock used when USB is in low power mode */

#define USB_USBC_32kHz_CLK      USB_USBC_32kHz_CLK_LFXO

/* Select the power saving mode. Enter power save on Suspend and when losing power on VBUS. The application determines when it is save to enter EM2 */

#define USB_PWRSAVE_MODE        (USB_PWRSAVE_MODE_ONSUSPEND | USB_PWRSAVE_MODE_ONVBUSOFF)

#endif /* __USBCONFIG_H */
