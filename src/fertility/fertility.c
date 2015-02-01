/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include <stdbool.h>
#include "fertility.h"

/* private variables */

// fertility factors - initial data in years for convenience
// - modify this when data is loaded from db
typedef struct {
    Year startMinYears;		// minimum starting age, in years
    Year startMaxYears;		// maximum starting age, in years
    Year startMediumYears;	// medium starting age, in years
    Year endMinYears;		// minimum ending age, in years
    Year endMaxYears;		// maximum ending age, in years
    Year endMediumYears;	// medium ending age, in years
    bool loaded;		// flag for if days data calculated/loaded
    Day startMin;		// minimum starting age, in days (calculated)
    Day startMax;		// maximum starting age, in days (calculated)
    Day startMedium;		// medium starting age, in days (calculated)
    Day endMin;			// minimum ending age, in days (calculated)
    Day endMax;			// maximum ending age, in days (calculated)
    Day endMedium;		// medium ending age, in days (calculated)
} RangeFactors;

// fertility names and codes
char *fertilityName[FERTILITY_SIZE] = { "tbd", "unknown", "fertile", "infertile" };
char *fertilityCode[FERTILITY_SIZE] = { "-", "?", "f", "i" };

// default fertility range for females (start 8-16, end 45-55)
RangeFactors fRange = {
    .startMinYears = 8,
    .startMaxYears = 16,
    .startMediumYears = 12,
    .endMinYears = 45,
    .endMaxYears = 55,
    .endMediumYears = 50,
    .loaded = false
};

// default fertility range for males (start 10-18, end 55-75)
RangeFactors mRange = {
    .startMinYears = 10,
    .startMaxYears = 18,
    .startMediumYears = 14,
    .endMinYears = 55,
    .endMaxYears = 75,
    .endMediumYears = 64,
    .loaded = false
};

// default pregnancy factors
PregnancyFactors pFactors = {
    .gestation = 266
};


/* declare private functions */
void loadRangeFactors(RangeFactors *factors);


/* private functions */


/* public functions */

// get the db code for a fertility type
char *getFertilityCode(enum FertilityType type) {
    return fertilityCode[type];
}

// get the name for a fertility type
char *getFertilityName(enum FertilityType type) {
    return fertilityName[type];
}

// get default fertility parameters
FertilityParams getDefaultFertilityParams(void) {
    FertilityParams params;
    FertileRangeFactors paramsF;
    FertileRangeFactors paramsM;

    // make sure that days have been calculated/loaded
    if (fRange.loaded == false)
        loadRangeFactors(&fRange);
    if (mRange.loaded == false)
        loadRangeFactors(&mRange);

    // set params.fRange
    paramsF.startMin = fRange.startMin;
    paramsF.startMax = fRange.startMax;
    paramsF.startMedium = fRange.startMedium;
    paramsF.endMin = fRange.endMin;
    paramsF.endMax = fRange.endMax;
    paramsF.endMedium = fRange.endMedium;
    params.fRange = paramsF;

    // set params.mRange
    paramsM.startMin = mRange.startMin;
    paramsM.startMax = mRange.startMax;
    paramsM.startMedium = mRange.startMedium;
    paramsM.endMin = mRange.endMin;
    paramsM.endMax = mRange.endMax;
    paramsM.endMedium = mRange.endMedium;
    params.mRange = paramsM;

    // set params.preg
    params.preg = pFactors;

    return params;
}


/* private functions */

// load/calculate days data for range factors
void loadRangeFactors(RangeFactors *factors) {
    factors->startMin = convertAgeInYearsToDays(BEGIN, factors->startMinYears);
    factors->startMax = convertAgeInYearsToDays(END, factors->startMaxYears);
    factors->startMedium = convertAgeInYearsToDays(MIDDLE, factors->startMediumYears);
    factors->endMin = convertAgeInYearsToDays(BEGIN, factors->endMinYears);
    factors->endMax = convertAgeInYearsToDays(END, factors->endMaxYears);
    factors->endMedium = convertAgeInYearsToDays(MIDDLE, factors->endMediumYears);
    factors->loaded = true;
}
