/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include "people.h"

/* private variables */


/* declare private functions */


/* private functions */


/* public functions */

// get a random age
Day genAgeRandomly(void) {
    int maxAge = (int)convertAgeInYearsToDays(END, MAX_AGE);

    return (Day)uRand(0, maxAge);
}
