#ifndef _PIN_CONNECT_H_
#define _PIN_CONNECT_H_

/* ------------------------------------------------------------------------- */
/*                                  LIBRARY                                  */
/* ------------------------------------------------------------------------- */

#include <Wire.h>

/* ------------------------------------------------------------------------- */
/*                DEBUG (uncomment to open the Debug function)               */
/* ------------------------------------------------------------------------- */

// #define ENABLE_DEBUG

#if defined(ENABLE_DEBUG)
#define Debug Serial
#define DEBUG_BEGIN(...) Debug.begin(__VA_ARGS__)
#define DEBUG_WRITE(...) Debug.write(__VA_ARGS__)
#define DEBUG_PRINT(...) Debug.print(__VA_ARGS__)
#define DEBUG_PRINTLN(...) Debug.println(__VA_ARGS__)
#else
#define DEBUG_BEGIN(...)
#define DEBUG_WRITE(...)
#define DEBUG_PRINT(...)
#define DEBUG_PRINTLN(...)
#endif

/* ------------------------------------------------------------------------- */
/*                                   RELAY                                   */
/* ------------------------------------------------------------------------- */

#define NUMBER_RELAY 4

#define INDEX_R1 0
#define INDEX_R2 1
#define INDEX_R3 2
#define INDEX_R4 3

#define ON_RELAY true   // Red
#define OFF_RELAY false // Green

#define COLOR_ON GSLC_COL_RED_LT1
#define COLOR_OFF GSLC_COL_GREEN_LT1

#define RELAY_TRIG_TIME 55 // Min 50 (ms)

/* ------------------------------------------------------------------------- */
/*                                    I/O                                    */
/* ------------------------------------------------------------------------- */

/**
 * Address I2C:  0011 1111 = 0x3F
 * Mask Address: 0011 1xxx
 * |                   |||
 * |                   ||A1(+)
 * |                   |A2(+)
 * |                   A3(+)
 */
#define IO_EXPAND_ADDR 0x3F

/**
 * Pinout PCF8574:
 * |
 * P7 - P6 - P5 - P4 - P3 - P2 - P1 - P0
 * |                                  |
 * |                                  LSB (Least Significant Byte)
 * MSB (Most Significant Byte)
 *
 * -------------------------------------------------------------------------- *
 *
 * Use pin common IN5 (+) ... [Positive Polarity]
 * |
 * IN3 (COM) ----- IN4 (NO) --> {SET}   : 1(-) 5(+) : ON  (Red)
 * IN3 (COM) --x-- IN4 (NO) --> {RESET} : 2(-) 5(+) : OFF (Green)
 */
#define NORMAL_STATE_OF_RELAY 0xFF // 1111 1111

/**
 * Pinout Relay 1:
 * |
 * P0 : IN2 (-)
 * P1 : IN1 (-)
 *
 * ON  = SET   : xxxx.xx01
 * OFF = RESET : xxxx.xx10
 */
#define ON_RL1 0xFD  // 1111 1101
#define OFF_RL1 0xFE // 1111 1110

/**
 * Pinout Relay 2:
 * |
 * P2 : IN2 (-)
 * P3 : IN1 (-)
 *
 * ON  = SET   : xxxx.01xx
 * OFF = RESET : xxxx.10xx
 */
#define ON_RL2 0xF7  // 1111 0111
#define OFF_RL2 0xFB // 1111 1011

/**
 * Pinout Relay 3:
 * |
 * P4 : IN2 (-)
 * P5 : IN1 (-)
 *
 * ON  = SET   : xx01.xxxx
 * OFF = RESET : xx10.xxxx
 */
#define ON_RL3 0xDF  // 1101 1111
#define OFF_RL3 0xEF // 1110 1111

/**
 * Pinout Relay 4:
 * |
 * P6 : IN2 (-)
 * P7 : IN1 (-)
 *
 * ON  = SET   : 01xx.xxxx
 * OFF = RESET : 10xx.xxxx
 */
#define ON_RL4 0x7F  // 0111 1111
#define OFF_RL4 0xBF // 1011 1111

/**
 * ON  = SET   : 1010.1010
 * OFF = RESET : 0101.0101
 */
#define ON_ALL_RELAY 0x55  // 0101 0101
#define OFF_ALL_RELAY 0xAA // 1010 1010

/* ------------------------------------------------------------------------- */
/*                                  MONITOR                                  */
/* ------------------------------------------------------------------------- */

#define LENGTH_PASS 4
#define PASS "1706"

#define BTN_ENA_FRA GSLC_COL_BLUE_DK2
#define BTN_ENA_FIL GSLC_COL_BLUE_DK4
#define BTN_ENA_SEL GSLC_COL_BLUE_DK1

#define BTN_DIS_FRA GSLC_COL_GRAY_DK1
#define BTN_DIS_FIL GSLC_COL_GRAY_DK3
#define BTN_DIS_SEL GSLC_COL_GRAY

/* ------------------------------------------------------------------------- */

#endif
