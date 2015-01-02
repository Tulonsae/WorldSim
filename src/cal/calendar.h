#ifndef CALENDAR_H
#define CALENDAR_H
/*
 * All calendar arithmetic is done by this library.
 *
 * Calendar days must be positive integers or 0.  Negative numbers are used
 * for unknown, undefined, and so forth (see sim.h).
 *
 * For events before the calendar's 0th day, use a different calendar with
 * a conversion rule.
 *
 * Data is stored in days.  No current ability to work with hours.
 *
 * TODO - Separate functions by planetary rules (equinoxes, tropical year,
 * moon phases, etc.) and by calendar events (months, holidays, etc.).
 *
 * TODO - add moon phases.
 *
 * TODO - Setup the ability for various types of calendars, that can be
 * defined in data rules.  Same for planetary rules.
 *
 * Also handle holidays.
 */

#include <stdio.h>
#include <sim.h>
#include <rng.h>

// types of calendar units
typedef double Time;		// calendar time, measured in days
typedef int Day;
typedef int Week;
typedef int Month;
typedef int Year;

// date, using base calendar
// TODO - months are still TBI
typedef struct {
    Time time;			// date/time, measured in days
    Year y;			// calendar year
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

// get length of tropical year
Time getTropicalYear();

// get calendar info for specified calendar time
Time getStartOfDay(Time time);
Time getStartOfYear(Time time);
Time getSpringOfYear(Time time);		// vernal equinox for year
Date getCalendarDate(Time time);
Year getCalendarYear(Time time);		// equals Date.y
Day getCalendarDayOfYear(Time time);		// equals Date.doy

// convert earth years to days
Day convertYearToBeginDay(Year years);		// to beginning of year
Day convertYearToMidDay(Year years);		// to middle of year
Day convertYearToEndDay(Year years);		// to end of year
Day convertYearToRandomDay(Year years);		// to random day in year

/*
// convert days to ymd time, using earth calendar
YmdTime convertDayToYmd(Day days);
*/

// calculate birth Day
Day calcBirthDayByAge(Day onDay, Day atAge);

#endif /* CALENDAR_H */
