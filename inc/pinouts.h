/****************************************************************************
 * pinouts.h
 * openacousticdevices.info
 * June 2017
 *****************************************************************************/

#ifndef PINOUTS_H_
#define PINOUTS_H_

#if defined (EFM32WG990F256)    // EFM32WG Starter Kit
  #include "pinouts_EFM32WG990.h"
#elif defined (EFM32WG380F256)  // AudioMoth
  #include "pinouts_EFM32WG380.h"
#endif

#define PIN_DEF(port,pin) void __##port##_##pin##__(){}
#define PIN_SANITY(port, pin) PIN_DEF(port, pin)

#endif /* PINOUTS_H_ */
