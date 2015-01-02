/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include "fertility.h"

// default fertility range for females (start 8-16, end 45-55)
FertilityRange fFertilityRange = {
    .first = 12,
    .firstVar = 4,
    .last = 50,
    .lastVar = 5
};

// default fertility range for males (start 10-18, end 55-75)
FertilityRange mFertilityRange = {
    .first = 14,
    .firstVar = 4,
    .last = 64,
    .lastVar = 10,
};

// default pregnancy factors
PregnancyFactors pFactors = {
    .gestation = 266
};


/* local functions */


/* publich functions */
