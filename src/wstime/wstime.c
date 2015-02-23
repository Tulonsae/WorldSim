/*
 * Copyright (c) 2014-2015, Kathy Feller.
 */

#include "wstime.h"

/* private variables */

// tropical year, starts on northern vernal equinox
Time tropicalYear = 365.2422;


/* declare private functions */

Time getLatestEquinox(Time time);
TimeDay getNumDaysForAgeYearAtStart(TimeYear years);
TimeDay getNumDaysForAgeYearAtEnd(TimeYear years);
TimeDay getNumDaysForAgeYearAtMiddle(TimeYear years);
TimeDay getNumDaysForAgeYearAtRandom(TimeYear years);


/* private functions */

// get latest equinox
//   this returns the latest occuring equinox for the time specified
//   if the time is exactly an equinox time, then time is returned
Time getLatestEquinox(Time time) {
    return floor(time / tropicalYear) * tropicalYear;
}

// given an age in years, get the number of days for the start of the "age year"
TimeDay getNumDaysForAgeYearAtStart(TimeYear years) {
    return getNumDays(years * tropicalYear);
}

// given an age in years, get the number of days for the end of the "age year"
TimeDay getNumDaysForAgeYearAtEnd(TimeYear years) {
    return getNumDays((years + 1) * tropicalYear) - 1;
}

// given an age in years, get the number of days for the middle of the "age year"
TimeDay getNumDaysForAgeYearAtMiddle(TimeYear years) {
    return getNumDays((years * tropicalYear) + (tropicalYear / 2));
}

// given an age in years, get the number of days randomly during the "age year"
TimeDay getNumDaysForAgeYearAtRandom(TimeYear years) {
    return (TimeDay)uRand(getNumDaysForAgeYearAtStart(years), getNumDaysForAgeYearAtEnd(years));
}


/* public functions */

// get length of tropical year
Time getTropicalYear() {
    return tropicalYear;
}

// get number of days since epoch for specified time
TimeDay getNumDays(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return (TimeDay)getStartOfDay(time);
}

// get starting time for the day that contains this time
Time getStartOfDay(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return (Time)floor(time);
}

// get starting time for the beginning of the year that contains this time
Time getStartOfYear(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return getStartOfDay(getSpringOfYear(time));
}

// get time of vernal equinox for the year containing the specified time
//   Note: since, by definition, the vernal equinox occurs during the first
//   day of the year, the part of the day just before the actual equinox event
//   is part of this year's spring day, not the previous year
Time getSpringOfYear(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    Time start = getStartOfDay(time);
    Time equinox = getLatestEquinox(time + 1);

    // if time is on same day as equinox
    if (getStartOfDay(equinox) == start)
        return equinox;

    // if time is later in the year
    return getLatestEquinox(time);
}

// convert age in years to days at beginning, middle, end, or randomly during
// the year; note: this is approximate since it assumes birth at epoch
TimeDay convertAgeInYearsToDays(enum Sequence at, TimeYear years) {
    if (years < FIRST_VALID_TIMEYEAR)
        return UNDEFINED;

    if (at == BEGIN)
        return getNumDaysForAgeYearAtStart(years);
    else if (at == END)
        return getNumDaysForAgeYearAtEnd(years);
    else if (at == MIDDLE)
        return getNumDaysForAgeYearAtMiddle(years);
    else if (at == RANDOM)
        return getNumDaysForAgeYearAtRandom(years);
    else
        return UNDEFINED;
}
