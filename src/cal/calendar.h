#ifndef CALENDAR_H
#define CALENDAR_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for calendar library.
 */

#include <stdio.h>

// calendar units
typedef double Time;		// calendar time, measured in days (.0 to .9_)
typedef int Day;
typedef int Week;
typedef int Month;
typedef int Year;

// date - information about a specific date (Time)
// d, y, moy, dom, and doy start at 1, the rest start at 0
typedef struct {
    Time time;			// date/time
    Day d;			// day of the calendar
    Year y;			// year of the calendar
    Month moy;			// month of the year
    Day dom;			// day of the month
    Day doy;			// day of the year
    Year numY;			// number of whole years
    Month numM;			// number of whole months
    Day numD;			// number of whole days
    Month numMpy;		// number of whole months in partial year
    Day numDpy;			// number of whole days in partial year
    Day numDpm;			// number of whole days in partial month
} Date;

// calendar year - contains information about a specific calendar year
typedef struct {
    Year year;			// calendar year
    Time start;			// start of year
    Time spring;		// vernal equinox
    Day first;			// first day
    Day last;			// last day
    Day length;			// number of days in this year
} CalendarYear;

// get length of tropical year
Time getTropicalYear();

// get calendar info for specified time
Time getStartOfDay(Time time);
Time getStartOfYear(Time time);
Time getSpringOfYear(Time time);		// vernal equinox for year
Date getDate(Time time);
Day getDay(Time time);				// equals Date.d
Year getYear(Time time);			// equals Date.y
Day getDayOfYear(Time time);			// equals Date.doy
CalendarYear getCalendarYear(Time time);
CalendarYear getCalendarYearForYear (Year year);

#endif /* CALENDAR_H */
