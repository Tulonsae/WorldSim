#ifndef FERTILITY_H
#define FERTILITY_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for fertility data.  Currently, for humans only.
 */

#include <calendar.h>

// fertility type
enum FertilityType {
    FERTILITY_UNDEFINED,	// not assigned
    FERTILITY_UNKNOWN,		// not known
    FERTILITY_YES,		// fertile
    FERTILITY_NO,		// infertile
    FERTILITY_SIZE,		// number of fertility types
};

// fertility range
typedef struct {
    Year first;			// starting age, in years
    Year last;			// ending age, in years
    Year firstVar;		// variance for starting age, in years
    Year lastVar;		// variance for ending age, in years
    Day firstMin;		// min starting age, in days (calculated)
    Day firstMax;		// max starting age, in days (calculated)
    Day lastMin;		// min ending age, in days (calculated)
    Day lastMax;		// max ending age, in days (calculated)
} FertilityRange;

// pregnancy factors
// - add miscarriage and such here?
typedef struct {
    Day gestation;		// days from conception to birth
} PregnancyFactors;

// fertility params - used as general parameters when generating/processing
typedef struct {
    FertilityRange fRange;	// female fertility range
    FertilityRange mRange;	// male fertility range
    PregnancyFactors preg;	// pregnancy factors
} FertilityParams;

// get db codes and display names
char *getFertilityCode(enum FertilityType type);
char *getFertilityName(enum FertilityType type);

#endif /* FERTILITY_H */
