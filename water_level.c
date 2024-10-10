#include "water_level.h"

#define WATER_LEVEL_PIN GPIO_NUM_34 // GPIO Pin for water level sensor

void init_water_level() {
    adc1_config_width(ADC_WIDTH_BIT_12);   //Sets to 12 bits of information
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_0); // ADC1 channel 6 for GPIO34
}

float read_water_level() {
    uint32_t adc_reading = adc1_get_raw(ADC1_CHANNEL_6); // Read from GPIO34
    return (float)adc_reading * (3.3 / 4096.0); // Convert ADC reading to voltage
}
