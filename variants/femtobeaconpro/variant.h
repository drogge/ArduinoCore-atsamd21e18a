/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ATSAMR21E18A_
#define _VARIANT_ATSAMR21E18A_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC     (32768ul)
// #define VARIANT_MAINOSC     (8000000ul)
// #define VARIANT_MAINOSC     (12000000ul)

/** Master clock frequency */
//#define VARIANT_MCK           (32000000ul)
#define VARIANT_MCK           (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (22u)
#define NUM_DIGITAL_PINS     (21u)
#define NUM_ANALOG_INPUTS    (1u)
#define NUM_ANALOG_OUTPUTS   (0u)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// Interrupts
#define digitalPinToInterrupt(P)   ( g_APinDescription[P].ulExtInt )

// LEDs
// #define PIN_LED_10           (10u)
// #define PIN_LED_RXL          (25u)
// #define PIN_LED_TXL          (26u)
#define PIN_LED              (6u)
// #define PIN_LED2             PIN_LED_RXL
// #define PIN_LED3             PIN_LED_TXL
// #define LED_BUILTIN          PIN_LED_10

/*
 * Analog pins
 */
#define PIN_A0               (5ul)
#define PIN_A1               (6ul)
// #define PIN_A2               (13ul)
// #define PIN_A3               (14ul)
// #define PIN_A4               (15ul)
// #define PIN_A5               (19ul)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
// static const uint8_t A2  = PIN_A2 ;
// static const uint8_t A3  = PIN_A3 ;
// static const uint8_t A4  = PIN_A4 ;
// static const uint8_t A5  = PIN_A5 ;
#define ADC_RESOLUTION      12

// Other pins
//#define PIN_ATN              (38ul)
//static const uint8_t ATN = PIN_ATN;

/*
 * Serial interfaces
 */
// Serial (EDBG)
// #define PIN_SERIAL_RX       (31ul)
// #define PIN_SERIAL_TX       (30ul)
// #define PAD_SERIAL_TX       (UART_TX_PAD_2)
// #define PAD_SERIAL_RX       (SERCOM_RX_PAD_3)

// Serial1
// #define PIN_SERIAL1_RX       (0ul)
// #define PIN_SERIAL1_TX       (1ul)
// #define PAD_SERIAL1_TX       (UART_TX_PAD_2)
// #define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

// Serial
#define PIN_SERIAL_RX       (7ul)//(0ul)
#define PIN_SERIAL_TX       (8ul)//(1ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_0)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_1)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MOSI         ( 9u) // Tx, PAD 2
#define PIN_SPI_MISO         (10u) // Rx, PAD 0
#define PIN_SPI_SCK          (11u) //     PAD 3
#define PIN_SPI_SS           (12u) //     PAD 1
#define PERIPH_SPI           sercom4
#define PAD_SPI_TX           SPI_PAD_2_SCK_3
#define PAD_SPI_RX           SERCOM_RX_PAD_0

#define PIN_SPI_IRQ         (13u)
#define PIN_SPI_SLEEP_TR    (14u)
#define PIN_SPI_RESET       (15u)

static const uint8_t SS   = PIN_SPI_SS  ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (0u)//(7u)
#define PIN_WIRE_SCL         (1u)//(8u)
#define PERIPH_WIRE          sercom1
#define WIRE_IT_HANDLER      SERCOM1_Handler

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (18ul)
#define PIN_USB_DM          (17ul)
#define PIN_USB_DP          (16ul)
#define PIN_USB_VBUS         PIN_USB_HOST_ENABLE

 /*
  * SWD
  */
// #define PIN_SWCLK           (22u)
// #define PIN_SWDIO           (23u)

 /*
 * 802.15.4/ATRF233
 */
#define PIN_ATRF233_MOSI    PIN_SPI_MOSI
#define PIN_ATRF233_MISO    PIN_SPI_MISO
#define PIN_ATRF233_SCK     PIN_SPI_SCK
#define PIN_ATRF233_SS      PIN_SPI_SS

#define PIN_ATRF233_IRQ     (13u)
#define PIN_ATRF233_SLP_TR  (14u)
#define PIN_ATRF233_RST     (15u)
#define PIN_ATRF233_SEL     PIN_ATRF233_SS
#define PIN_RF1             (19u)
#define PIN_RF2             (20u)

#define PERIPH_ATRF233      PERIPH_SPI
#define PAD_ATRF233_TX      PAD_SPI_TX
#define PAD_ATRF233_RX      PAD_SPI_RX

#define MODULE_AT86RF233        0x01
#define MODULE_AT86RF233_CLOCK (2000000ul)

// #define PIN_SPI1_MOSI        PIN_ATRF233_MOSI
// #define PIN_SPI1_MISO        PIN_ATRF233_MISO
// #define PIN_SPI1_SCK         PIN_ATRF233_SCK
// #define PIN_SPI1_SS          PIN_ATRF233_SS
// #define PERIPH_SPI1          PERIPH_ATRF233
// #define PAD_SPI1_TX          PAD_ATRF233_TX
// #define PAD_SPI1_RX          PAD_ATRF233_RX


#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*  =========================
 *  ===== SERCOM DEFINITION
 *  =========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
// extern SERCOM sercom5;

extern Uart Serial;
// extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
// #define SERIAL_PORT_MONITOR         Serial
// // Serial has no physical pins broken out, so it's not listed as HARDWARE port
// #define SERIAL_PORT_HARDWARE        Serial1
// #define SERIAL_PORT_HARDWARE_OPEN   Serial1

#define SERIAL_PORT_MONITOR        Serial
// #define SERIAL_PORT_HARDWARE        Serial1
// #define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ATSAMR21E18A_ */

