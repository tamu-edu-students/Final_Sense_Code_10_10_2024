#include <stdio.h>              // Standard C library for input/output functions
#include "freertos/FreeRTOS.h"   // FreeRTOS for task management and timing functions
#include "freertos/task.h"       // FreeRTOS task functions
#include "uart.h"                // Custom UART communication functions
#include "soil_moisture.h"       // Header file for soil moisture sensor functions
#include "dht11.h"               // Header file for DHT11 temperature and humidity sensor
#include "water_level.h"         // Header file for water level sensor functions

void app_main() {
    // Initialize UART for sending data
    initUART(); 

    // Initialize the ADC for reading soil moisture
    init_adc(); 
    
    // Initialize DHT11 sensor for temperature and humidity data
    init_dht11(); 
    
    // Initialize water level sensor 
    init_water_level(); 

    while (1) {
        // Read the soil moisture value from the sensor (returns a float)
        float soil_moisture = read_soil_moisture(); 
        
        // Read the temperature and humidity from DHT11 sensor (returns a struct with both values)
        DHT11_Data dht11_data = read_dht11(); 
        
        // Read the water level value from the water level sensor (returns a float)
        float water_level = read_water_level(); 

        // Create a string to hold the message that will be sent via UART; we set the thing to 128 as the max amount in bits
        // Includes the zone, location (front lawn), and sensor readings (soil moisture, temp, humidity, water level)
        char message[128]; 
        
        // Format the string to include sensor data with two decimal precision
        snprintf(message, sizeof(message), //The snprintf() function formats and stores a series of characters and values in the array buffer
                 "Zone: 1, Front Lawn, Soil Moisture: %.2f, Temperature: %.2f°C, Humidity: %.2f%%, Water Level: %.2f cm",
                 soil_moisture, dht11_data.temperature, dht11_data.humidity, water_level);
        
        // Send the formatted string via UART to the receiver (Robins HUB)
        //SendData command is from the UART driver
        sendData(message); 

        // Pause the loop for 1 second (1000 ms) for now till we get to one hour (3600000 ms)
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Adjust the delay as needed
    }
}
