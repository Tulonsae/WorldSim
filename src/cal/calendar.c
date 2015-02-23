/*
 * Copyright (c) 2014-2015, Kathy Feller.
 */

#include "calendar.h"

/* private variables */


/* declare private functions */

TimeDay getNumDaysForCurrentYear(Time time);


/* private functions */

// get number of days in this year
TimeDay getNumDaysForCurrentYear(Time time) {
    return getNumDays(getStartOfDay(time) - getStartOfYear(time));
}


/* public functions */

// get calendar year
Year getYear(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return (Year)(getNumYears(time) + 1);
}

// get calendar day
Day getDay(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return (Day)(getNumDays(time) + 1);
}

// get calendar day of year
Day getDayOfYear(Time time) {
    if (time < EPOCH)
        return UNDEFINED;

    return (Day)(getNumDaysForCurrentYear(time) + 1);
}

// get (and initialize) new date
CalendarDate getDate(Time time) {
    CalendarDate date;

    if (time < EPOCH) {
        date.time = UNDEFINED;
        return date;
    }

    date.time = time;
    date.d = getDay(time);
    date.y = getYear(time);
    date.moy = 0;	// TBD
    date.dom = 0;	// TBD
    date.doy = getDayOfYear(time);
    date.numY = getNumYears(time);
    date.numM = 0;	// TBD
    date.numD = getNumDays(time);
    date.numMpy = 0;	// TBD
    date.numDpy = getNumDaysForCurrentYear(time);
    date.numDpm = 0;	// TBD

    return date;
}

// get (and initialize) new calendar year, given the time
CalendarYear getCalendarYear(Time time) {
    CalendarYear calYear;

    if (time < EPOCH) {
        calYear.year = UNDEFINED;
        return calYear;
    }

    calYear.year = getYear(time);
    calYear.spring = getSpringOfYear(time);
    calYear.first = getDay(getStartOfYear(time));
    calYear.last = getDay(getStartOfDay(getSpringOfYear(time) + getTropicalYear() - 1));
    calYear.length = (TimeDay)(calYear.last - calYear.first) + 1;

    return calYear;
}

// get (and initialize) new calendar year, given the calendar year
CalendarYear getCalendarYearForYear(Year year) {
    if (year < FIRST_VALID_YEAR) {
        CalendarYear calYear;
        calYear.year = UNDEFINED;
        return calYear;
    }

    // since each year begins at spring
    Time time = (year - 1) * getTropicalYear();

    return getCalendarYear(time);
}
