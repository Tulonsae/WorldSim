/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include <rng.h>
#include "gender.h"

/* private variables */


/* declare private functions */


/* private functions */


/* public functions */

enum GenderType getRandomGender(void) {
    if (coinflip() == ODD)
        return GENDER_FEMALE;
    else
        return GENDER_MALE;
}
