#ifndef CALENDAR_H
#define CALENDAR_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for calendar library.
 */

#include <math.h>
#include <sim.h>
#include <rng.h>
#include <wstime.h>

// constants
#define FIRST_VALID_YEAR 1
#define FIRST_VALID_DAY 1

// calendar units - start at 1
typedef int Day;
typedef int Week;
typedef int Month;
typedef int Year;

// date - information about a specific calendar date
// d, y, moy, dom, and doy start at 1, the rest start at 0
typedef struct {
    Time time;			// time since epoch
    Day d;			// day of the calendar
    Year y;			// year of the calendar
    Month moy;			// month of the year
    Day dom;			// day of the month
    Day doy;			// day of the year
    TimeYear numY;		// number of whole years
    int numM;			// number of whole months
    TimeDay numD;		// number of whole days
    int numMpy;			// number of whole months in partial year
    TimeDay numDpy;		// number of whole days in partial year
    TimeDay numDpm;		// number of whole days in partial month
} CalendarDate;

// calendar year - contains information about a specific calendar year
typedef struct {
    Year year;			// calendar year
    Time start;			// start of year
    Time spring;		// vernal equinox
    Day first;			// first day
    Day last;			// last day
    TimeDay length;		// number of days in this year
} CalendarYear;

// get calendar info for specified time
// note: if time < EPOCH, then UNDEFINED is returned
CalendarDate getDate(Time time);
Day getDay(Time time);				// equals CalendarDate.d
Year getYear(Time time);			// equals CalendarDate.y
Day getDayOfYear(Time time);			// equals CalendarDate.doy
CalendarYear getCalendarYear(Time time);
CalendarYear getCalendarYearForYear (Year year);

#endif /* CALENDAR_H */
