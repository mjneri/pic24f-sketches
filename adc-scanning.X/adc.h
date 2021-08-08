//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// adc.h -- ADC Driver Header file
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: adc.h
// Description:
//
// Revisions:
// Revision 0.01 - File Created 2021-06-26
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Header guards
#ifndef _ADC_H_
#define _ADC_H_

// Define Macros/Constants
#define ADCBUFSZ 16

// Define ADC Channels used
typedef enum
{
    channel_AN3_RB1 = 3,
    channel_AN4_RB2 = 4
} ADC_CHANNEL;

// Function prototypes
void ADC_Initialize(void);
void ADC_StartConversion(void);
void ADC_StopConversion(void);
bool ADC_IsConversionDone(void);
void ADC_GetBufferResult(uint16_t *buffer);

#endif /*_ADC_H_*/