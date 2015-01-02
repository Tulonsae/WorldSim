#ifndef FERTILITY_H
#define FERTILITY_H
/*
 * This is for humans.
 */

#include <sim.h>
#include <calendar.h>

// fertility type
enum FertilityType {
    FERTILE,			// fertile
    INFERTILE,			// infertile
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
typedef struct {
    Day gestation;		// days from conception to birth
} PregnancyFactors;

#endif /* FERTILITY_H */
