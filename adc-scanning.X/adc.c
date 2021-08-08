//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// adc.c -- ADC Drivers
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: adc.c
// Description:
//
// Revisions:
// Revision 0.01 - File Created 2021-06-26
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include Header files
#include "system.h"

// Global Variables
// ...

// Extern variables
// ...

// Functions
void ADC_Initialize(void)
{
    // ADON disabled, ADSIDL continue in idle mode, FORM integer,
    // SSRC internal counter starts conversion
    AD1CON1 = 0x00E0;
    
    // VCFG AVDD AVSS, CSCNA Scan Inputs, SMPI every 2nd convert,
    // BUFM one 16-word buffer, ALTS always MUXA
    AD1CON2 = 0x0404;
    
    // ADRC Internal RC clock, SAMC 15*Tad internal counter duration
    // Note: Internal RC period is 250ns
    AD1CON3 = 0x8F00;
    
    // CH0NA Negative input is Vr-, CH0SA AN3
    AD1CHS = 0x0003;
    
    // Select AN3 and AN4 for Channel scanning
    AD1CSSL = 0x0018;
    
    // Initialize Interrupt flag and enable
    #ifdef ADC_INTERRUPT
        IFS0bits.AD1IF = 0;         // Clear flag
        IEC0bits.AD1IE = 1;         // Enable Interrupts
    #endif

    AD1CON1bits.ADON = 1;
}

void ADC_StartConversion(void)
{
    // Start Auto-sampling
    IFS0bits.AD1IF = 0;
    AD1CON1bits.ASAM = 1;
}

void ADC_StopConversion(void)
{
    // Stop Auto-sampling
    AD1CON1bits.ASAM = 0;
}

bool ADC_IsConversionDone(void)
{
    #ifndef ADC_INTERRUPT
        return (bool) IFS0bits.AD1IF;
    #else
        return (bool) AD1CON1bits.DONE;
    #endif
}

void ADC_GetBufferResult(uint16_t *buffer)
{
    // Determine how many samples are needed
    uint8_t count = AD1CON2bits.SMPI;
    
    // Increment count; NOTE: SMPI = 0 indicates interrupts after every conversion
    count++;
    
    // Get ADC1BUF0 address
    uint16_t *ADCBufPtr = (uint16_t *)&(ADC1BUF0);
    
    // Store ADC results in the given buffer
    int i = 0;
    for(i = 0; i < count; i++)
    {
        buffer[i] = (uint16_t)*ADCBufPtr;
        ADCBufPtr++;
    }
    
    // Clear interrupt flag
    IFS0bits.AD1IF = 0;
    
    return;
}