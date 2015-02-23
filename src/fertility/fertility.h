#ifndef FERTILITY_H
#define FERTILITY_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for fertility data.  Currently, for humans only.
 */

#include <wstime.h>
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
    TimeDay startMin;		// minimum starting age, in days
    TimeDay startMax;		// maximum starting age, in days
    TimeDay startMedium;	// medium starting age, in days
    TimeDay endMin;		// minimum ending age, in days
    TimeDay endMax;		// maximum ending age, in days
    TimeDay endMedium;		// medium ending age, in days
} FertileRangeFactors;

// pregnancy factors
// - add miscarriage and such here?
typedef struct {
    TimeDay gestation;		// from conception to birth, in days
} PregnancyFactors;

// fertility params - used as general parameters when generating/processing
typedef struct {
    FertileRangeFactors fRange;		// female fertility range
    FertileRangeFactors mRange;		// male fertility range
    PregnancyFactors preg;		// pregnancy factors
} FertilityParams;

// get db codes and display names
char *getFertilityCode(enum FertilityType type);
char *getFertilityName(enum FertilityType type);

// get fertility params
FertilityParams getDefaultFertilityParams(void);

#endif /* FERTILITY_H */
