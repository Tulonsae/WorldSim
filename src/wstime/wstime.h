#ifndef WSTIME_H
#define WSTIME_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for wstime library.
 */

#include <sim.h>
#include <math.h>
#include <rng.h>

// constants
#define FIRST_VALID_TIMEYEAR 0
#define FIRST_VALID_TIMEDAY 0
#define EPOCH 0.0
// max age for people
#define MAX_AGE 120

// time - measures passage of time, in days
// epoch is 0.0, each day starts at .0, ends just before the next .0
typedef double Time;

// whole units of time
typedef int TimeDay;		// whole number of days
typedef int TimeYear;		// whole number of years

// get length of tropical year
Time getTropicalYear();

// get number of days since epoch for specified time
TimeDay getNumDays(Time time);
// get number of years since epoch for specified time
TimeYear getNumYears(Time time);

// significant events in time
// note: if time < EPOCH, then UNDEFINED is returned
Time getStartOfDay(Time time);
Time getStartOfYear(Time time);
Time getSpringOfYear(Time time);		// vernal equinox for year

// convert age in years to days at beginning, middle, end, or randomly during the year
TimeDay convertAgeInYearsToDays(enum Sequence at, TimeYear years);

#endif /* WSTIME_H */
