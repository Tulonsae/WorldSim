#ifndef CALENDAR_H
#define CALENDAR_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for calendar library.
 */

#include <sim.h>
#include <rng.h>

// constants
#define FIRST_VALID_YEAR 1
#define FIRST_VALID_DAY 1

// time - measures passage of time, in days
// epoch is 0.0, each day starts at .0, ends just before the next .0
typedef double Time;

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
// note: if time < 0, then UNDEFINED is returned
Time getStartOfDay(Time time);
Time getStartOfYear(Time time);
Time getSpringOfYear(Time time);		// vernal equinox for year
CalendarDate getDate(Time time);
Day getDay(Time time);				// equals CalendarDate.d
Year getYear(Time time);			// equals CalendarDate.y
Day getDayOfYear(Time time);			// equals CalendarDate.doy
CalendarYear getCalendarYear(Time time);
CalendarYear getCalendarYearForYear (Year year);

// convert age in years to days for beginning, middle, end, or random day of year
Day convertAgeInYearsToDays(enum Sequence when, Year years);

#endif /* CALENDAR_H */
