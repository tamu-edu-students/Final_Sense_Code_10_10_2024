#include "soil_moisture.h"

#define ANALOG_PIN GPIO_NUM_35 // GPIO Pin for soil moisture sensor

void init_adc() {
    adc1_config_width(ADC_WIDTH_BIT_12); //Sets to 12 bits 
    adc1_config_channel_atten(ADC1_CHANNEL_7, ADC_ATTEN_DB_0); // ADC1 channel 7 -> GPIO35
}

float read_soil_moisture() {  //Function used to read moisture in soil we'll then save this data in a variable
    uint32_t adc_reading = adc1_get_raw(ADC1_CHANNEL_7); // Read from the GPIO35
    return (float)adc_reading * (3.3 / 4096.0); // Convert ADC reading to voltage 
}
