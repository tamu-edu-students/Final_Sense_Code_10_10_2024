#include "dht11.h"  //Includes the dht11.h file  

#define DHT11_PIN GPIO_NUM_4 // GPIO Pin for DHT11 sensor

void init_dht11() {   //Written out function for initialzing the dht11 sensor
    gpio_set_direction(DHT11_PIN, GPIO_MODE_INPUT_OUTPUT); // Set as input/output
}

DHT11_Data read_dht11() {
    DHT11_Data data;
    // Placeholder for DHT11 reading logic
    data.temperature = 23.5;  // Example using for now till i fgure out how to program it
    data.humidity = 45.0;
    return data;
}
