#ifndef CALENDAR_H
#define CALENDAR_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for calendar library.
 */

#include <stdio.h>

// calendar units
typedef double Time;		// time since epoch, in days (.0 to <1.0)
typedef int Day;		// calendar day, 1+
typedef int Week;		// calendar week, 1+
typedef int Month;		// calendar month, 1+
typedef int Year;		// calendar year, 1+

// date - information about a specific calendar date (Time)
// d, y, moy, dom, and doy start at 1, the rest start at 0
typedef struct {
    Time time;			// date/time
    Day d;			// day of the calendar
    Year y;			// year of the calendar
    Month moy;			// month of the year
    Day dom;			// day of the month
    Day doy;			// day of the year
    int numY;			// number of whole years
    int numM;			// number of whole months
    int numD;			// number of whole days
    int numMpy;			// number of whole months in partial year
    int numDpy;			// number of whole days in partial year
    int numDpm;			// number of whole days in partial month
} CalendarDate;

// calendar year - contains information about a specific calendar year
typedef struct {
    Year year;			// calendar year
    Time start;			// start of year
    Time spring;		// vernal equinox
    Day first;			// first day
    Day last;			// last day
    int length;			// number of days in this year
} CalendarYear;

// get length of tropical year
Time getTropicalYear();

// get calendar info for specified time
Time getStartOfDay(Time time);
Time getStartOfYear(Time time);
Time getSpringOfYear(Time time);		// vernal equinox for year
CalendarDate getDate(Time time);
Day getDay(Time time);				// equals CalendarDate.d
Year getYear(Time time);			// equals CalendarDate.y
Day getDayOfYear(Time time);			// equals CalendarDate.doy
CalendarYear getCalendarYear(Time time);
CalendarYear getCalendarYearForYear (Year year);

#endif /* CALENDAR_H */
