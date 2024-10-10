#ifndef DHT11_H
#define DHT11_H

#include "driver/gpio.h"  //Includes the gpio driver that allows us to use the gpio commands

// Structure to hold temperature and humidity values
typedef struct {
    float temperature;
    float humidity;
} DHT11_Data;


void init_dht11(void);   //Initializes function for the initialization of the DHT11 sensor
DHT11_Data read_dht11(void);   // Function used for reading the data recieved(Later we will put this info into a variable)

#endif //Ends conditional directive
