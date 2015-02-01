/*
 * Copyright (c) 2014-2015, Kathy Feller.
 */

#include "calendar.h"

/* private variables */

// tropical year, starts on northern vernal equinox
Time tropicalYear = 365.2422;


/* declare private functions */

Day getMinDaysInYear();
Time getLastEquinox(Time time);
int getNumWholeDays(Time time);
int getNumWholeDaysOfYear(Time time);
int getNumWholeYears(Time time);


/* private functions */

// get minimum number of days in a calendar year
int getMinDaysInYear() {
    return (int)tropicalYear;
}

// get latest equinox
//   this returns the last occuring equinox
//   if the time is exactly an equinox time, then it is returned
Time getLastEquinox(Time time) {
    int years = (int)(time / tropicalYear);

    return ((Time)years * tropicalYear);
}

// get the number of whole days since beginning
int getNumWholeDays(Time time) {
    return (int)time;	// equivalent to getStartOfDay(time)
}

// get the number of whole days in this (partial) calendar year
int getNumWholeDaysOfYear(Time time) {
    return (int)(getStartOfDay(time) - getStartOfYear(time));
}

// get the first day of this calendar year
Day getFirstDayOfYear(Time time) {
    return getDay(getStartOfYear(time));
}

// get the last day of this calendar year
Day getLastDayOfYear(Time time) {
    // get the spring, add a tropical year, subtract 1 day to get
    // the last day, get the start of that day, then return the Day
    return getDay(getStartOfDay(getSpringOfYear(time) + tropicalYear - 1));
}

// get the number of whole calendar years since beginning
int getNumWholeYears(Time time) {
    return (int)(getSpringOfYear(time) / tropicalYear);
}


/* public functions */

// get length of tropical year
Time getTropicalYear() {
    return tropicalYear;
}

// get starting time for the day that contains this time
Time getStartOfDay(Time time) {
    int start = (int)time;
    return (Time)start;
}

// get time of vernal equinox for this calendar year
//   by definition, the vernal equinox occurs in the first day of the year,
//   therefore, the part of the day just before the actual equinox event is
//   part of this year's spring day, not the previous year
Time getSpringOfYear(Time time) {
    Time start = getStartOfDay(time);
    Time equinox = getLastEquinox(time + 1);

    // if time is on same day as equinox
    if (getStartOfDay(equinox) == start)
        return equinox;

    // if time is later in the year
    return getLastEquinox(time);
}

// get start time for this calendar year
Time getStartOfYear(Time time) {
    return getStartOfDay(getSpringOfYear(time));
}

// get calendar year
Year getYear(Time time) {
    return (Year)(getNumWholeYears(time) + 1);
}

// get calendar day
Day getDay(Time time) {
    return (Day)(getNumWholeDays(time) + 1);
}

// get calendar day of year
Day getDayOfYear(Time time) {
    return (Day)(getNumWholeDaysOfYear(time) + 1);
}

// get (and initialize) new date
CalendarDate getDate(Time time) {
    CalendarDate date;

    if (time < 0) {
        fprintf(stderr, "Warning: invalid time, setting to 0\n");
        time = 0;
    }

    date.time = time;
    date.d = getDay(time);
    date.y = getYear(time);
    date.moy = 0;	// TBD
    date.dom = 0;	// TBD
    date.doy = getDayOfYear(time);
    date.numY = getNumWholeYears(time);
    date.numM = 0;	// TBD
    date.numD = getNumWholeDays(time);
    date.numMpy = 0;	// TBD
    date.numDpy = getNumWholeDaysOfYear(time);
    date.numDpm = 0;	// TBD

    return date;
}

// get (and initialize) new calendar year, given the time
CalendarYear getCalendarYear(Time time) {
    CalendarYear calYear;

    if (time < 0) {
        fprintf(stderr, "Warning: invalid time, setting time to 0\n");
        time = 0;
    }

    calYear.year = getYear(time);
    calYear.spring = getSpringOfYear(time);
    calYear.first = getFirstDayOfYear(time);
    calYear.last = getLastDayOfYear(time);
    calYear.length = (int)(calYear.last - calYear.first) + 1;

    return calYear;
}

// get (and initialize) new calendar year, given the calendar year
CalendarYear getCalendarYearForYear(Year year) {
    if (year < 1) {
        fprintf(stderr, "Warning: invalid year, setting year to 1\n");
        year = 1;
    }

    // since each year begins at spring
    Time time = (year - 1) * tropicalYear;
    if (getYear(time) != year) {
        fprintf(stderr, "Warning: internal (logic) error, setting year to 1\n");
        time = 0.0;
    }

    return getCalendarYear(time);
}

// convert age in years to days at beginning, middle, end, or random day of year
// note: this is approximate since it assumes age from epoch
Day convertAgeInYearsToDays(enum Sequence when, Year years) {
    Time time = years * tropicalYear;

    if (when == BEGIN)
        return getFirstDayOfYear(time);
    else if (when == END)
        return getLastDayOfYear(time);
    else if (when == MIDDLE)
        return getDay(time + (tropicalYear / 2));
    else if (when == RANDOM)
        return getDay(uRand(getFirstDayOfYear(time), getLastDayOfYear(time)));

    fprintf(stderr, "Warning: invalid sequence, returning day as 1\n");
    return 1;
}
