#ifndef SOIL_MOISTURE_H
#define SOIL_MOISTURE_H

#include "driver/adc.h"  //Lets us use the Analog ADC commands

// Function prototypes that get declared and used in the main c file
void init_adc(void);
float read_soil_moisture(void);

#endif 
