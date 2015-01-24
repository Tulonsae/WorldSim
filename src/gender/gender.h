#ifndef GENDER_H
#define GENDER_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for gender data and routines.
 */

#include <sim.h>

// gender type
enum GenderType {
    GENDER_UNDEFINED,			// none assigned
    GENDER_UNKNOWN,			// not known
    GENDER_FEMALE,			// female
    GENDER_MALE,			// male
    GENDER_SIZE,			// number of gender types
};

// get db codes and display names
char *getGenderCode(enum GenderType gender);
char *getGenderName(enum GenderType gender);

// generate random values
enum GenderType getRandomGender(void);

#endif /* GENDER_H */
