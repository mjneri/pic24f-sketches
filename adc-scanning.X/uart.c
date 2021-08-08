//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// uart.c -- UART Drivers
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Author: mjneri
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// Module Name: uart.c
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
void UART_Initialize(void)
{
    // UARTEN disabled, UEN U1TX and U1RX enabled, BRGH highspeed mode
    U1MODE = 0x0008;
    
    // UTXISEL default, UTXINV TX idle high, UTXEN disabled
    U1STA = 0x0000;
    
    // 115200 bps baud rate
    U1BRG = 34;
    
    // Enable UART1
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}

void UART_WriteByte(uint8_t c)
{
    while(!U1STAbits.TRMT);
    U1TXREG = c;
}

void _mon_putc(char c)
{
    while(!U1STAbits.TRMT);
    U1TXREG = c;
}