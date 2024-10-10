#ifndef UART_H
#define UART_H

#include "driver/uart.h"
#include "driver/gpio.h"
#include <string.h>

// Function prototypes
void initUART(void);  //Declares the function for initializing the UART port and the settings as set in the espressif idf website
void sendData(const char* data);

#endif 