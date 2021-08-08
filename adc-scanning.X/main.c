
#include "system.h"

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// main.c -- Main C Firmware code
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: main.c
// Description: This is a simple demo of ADC channel scanning to sample two potentiometers
//              using the PIC24F's ADC.
//
//              Hardware pins used:
//                  + RB1: Potentiometer
//                  + RB2: Potentiometer
//                  + RB15: UART TX
//                  + RA0: LED
//
//              Display ADC data to MPLAB Data Visualizer
//
// Revisions:
// Revision 0.01 - File Created 2021-06-26
// Additional Comments:
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Include header files here
#include "system.h"

// Global Variables
// Define variables that will be accessed by ISRs as 'volatile'
uint16_t adcBuffer[ADCBUFSZ];

// Extern Variables
// ...

// Private variables
static const uint8_t dv_sof = 0x03;             // Can be any arbitrary number
static const uint8_t dv_eof = 0xFC;             // Must be one's complement of dv_eof

int main(void)
{
    // Initialize all modules
    SYSTEM_Initialize();
    
    // Initialize the buffer
    memset(adcBuffer, 0, sizeof(adcBuffer));
    
    // Print Initialization code
    printf("\033\143");         // Clear terminal
    __delay_ms(10);             // Wait for terminal clear to finish   
    printf("PIC24FJ64GB002 initialized.\r\n");
    LED1_SetLow();              // Turn on LED1
    __delay_ms(2000);
    LED1_SetHigh();             // Turn off LED1

    while(1)
    {
        // Write application code here
        ADC_StartConversion();
        while(!ADC_IsConversionDone());
        ADC_StopConversion();
        ADC_GetBufferResult(adcBuffer);
        
        //printf("\033[4;0HAN3 = %04u\r\n", adcBuffer[0]);
        //printf("AN4 = %04u\r\n", adcBuffer[1]);
        
        // Display data in MPLAB DV Plot
        UART_WriteByte(dv_sof);
        UART_WriteByte((uint8_t)(adcBuffer[0] & 0xFF));
        UART_WriteByte((uint8_t)(adcBuffer[0] >> 8));
        UART_WriteByte((uint8_t)(adcBuffer[1] & 0xFF));
        UART_WriteByte((uint8_t)(adcBuffer[1] >> 8));
        UART_WriteByte(dv_eof);
    }
}