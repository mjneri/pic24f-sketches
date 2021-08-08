//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// system.h -- Header file for system.c
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: system.h
// Description:
//
// Revisions:
// Revision 0.01 - File Created 2021-06-26
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header Guards
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

// Project File includes (like stdio.h, etc.)
#include <xc.h>
#include <stdint.h>             // For integer type definitions
#include <stdbool.h>            // For bool definition
#include <stdio.h>              // For printf()
#include <string.h>             // For sprintf()

// Other header files
#include "adc.h"
#include "interrupts.h"
#include "uart.h"

#define FCY 16000000UL           // Fcy = Fosc/2 at reset
#include <libpic30.h>            // For __delay32() Function

// Define Macros
//#define ADC_INTERRUPT   // determines if ADC interrupts are used

// IO Pin Macros
#define LED1            LATAbits.LATA0
#define LED1_SetLow()   (LATAbits.LATA0 = 0)
#define LED1_SetHigh()  (LATAbits.LATA0 = 1)
#define LED1_Toggle()   (LATAbits.LATA0 = PORTAbits.RA0 ^ 1)

// Define System level constants
// ...

// Function prototypes
void SYSTEM_Initialize(void);
void CLOCK_Initialize(void);
void PIN_Initialize(void);

#endif /*_SYSTEM_H_*/