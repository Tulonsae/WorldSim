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

// check if specified gender type is valid
bool isValidGenderType(enum GenderType gender) {
    if ((gender == GENDER_UNDEFINED)
            || (gender == GENDER_UNKNOWN)
            || (gender == GENDER_FEMALE)
            || (gender == GENDER_MALE)
            ) {
        return true;
    } else {
        return false;
    }
}

// get a random gender
enum GenderType genGenderRandomly(void) {
    if (coinflip() == ODD)
        return GENDER_FEMALE;
    else
        return GENDER_MALE;
}

// get the db code for a gender type
char *getGenderCode(enum GenderType gender) {
    if (isValidGenderType(gender)) {
        return genderCode[gender];
    } else {
        return "";
    }
}

// get the name for a gender type
char *getGenderName(enum GenderType gender) {
    if (isValidGenderType(gender)) {
        return genderName[gender];
    } else {
        return "";
    }
}
