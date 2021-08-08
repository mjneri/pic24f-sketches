//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// interrupts.c -- Interrupt service routines
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: interrupts.c
// Description:
//
// Revisions:
// Revision 0.01 - File Created (DATE HERE)
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header files
#include "interrupts.h"
#include "system.h"

// Global variables
// ...

// Extern Variables
// ...

// ISRs
void INTERRUPT_Initialize(void)
{
    // Initialize priority levels
    #ifdef ADC_INTERRUPT
        IPC3bits.AD1IP = 6;
    #endif
}

void __attribute__ ((interrupt, no_auto_psv)) _ADC1Interrupt(void)
{
    // Clear interrupt flag
    IFS0bits.AD1IF = 0;
}