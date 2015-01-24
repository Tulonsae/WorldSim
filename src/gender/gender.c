/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include <rng.h>
#include "gender.h"

/* private variables */

// gender names and codes
char *genderName[GENDER_SIZE] = { "tbd", "unknown", "female", "male" };
char *genderCode[GENDER_SIZE] = { "-", "?", "f", "m" };


/* declare private functions */


/* private functions */


/* public functions */

// get a random gender
enum GenderType getRandomGender(void) {
    if (coinflip() == ODD)
        return GENDER_FEMALE;
    else
        return GENDER_MALE;
}

// get the db code for a gender type
char *getGenderCode(enum GenderType gender) {
    return genderCode[gender];
}

// get the name for a gender type
char *getGenderName(enum GenderType gender) {
    return genderName[gender];
}
