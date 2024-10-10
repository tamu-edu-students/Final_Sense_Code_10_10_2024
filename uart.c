#include "uart.h"

#define TXD_PIN (GPIO_NUM_2)  //defines out TX pin
#define RXD_PIN (GPIO_NUM_15)  //Defines the RX pin
#define UART_NUM UART_NUM_2 //Set the pin 2 to the UART

void initUART() {   //Parameters straight from the espressif website that can be used for initializing the chips UART comms in prep for the radio communication
    const uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .rx_flow_ctrl_thresh = 0
    };

    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM, 1024 * 2, 0, 0, NULL, 0);
}

void sendData(const char* data) {   //Function we use to actually send the data to the radio module
    uart_write_bytes(UART_NUM, data, strlen(data));  //Wrties the bytes of information to UART
}
