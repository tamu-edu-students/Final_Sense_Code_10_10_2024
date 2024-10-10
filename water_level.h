#ifndef WATER_LEVEL_H
#define WATER_LEVEL_H

#include "driver/adc.h"  //allows us to use the ads analogue data commands

// Function prototypes
void init_water_level(void);
float read_water_level(void);

#endif // WATER_LEVEL_H
