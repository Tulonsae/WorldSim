/*
 * Copyright (c) 2014, Kathy Feller.
 */

#include "calendar.h"

/* local variables */

// tropical year, starts on northern vernal equinox
Time tropicalYear = 365.2422;


/* declare local functions */
Time getLastEquinox(Time time);
Year getNumWholeYears(Time time);
Day getNumWholeDays(Time time);
Day getNumWholeDaysOfYear(Time time);


/* local functions */

// get latest equinox
//   this returns the last occuring equinox, which includes the current
//   time if it exactly equals the equinox time
Time getLastEquinox(Time time) {
    Year years = (Year)(time / tropicalYear);

    return ((Time)years * tropicalYear);
}

// get the number of whole years
Year getNumWholeYears(Time time) {
    return (Year)(getSpringOfYear(time) / tropicalYear);
}

// get the number of whole days
Day getNumWholeDays(Time time) {
    return (Day)time;	// equivalent to getStartOfDay(time)
}

// get the number of whole days in the calendar (partial) year
Day getNumWholeDaysOfYear(Time time) {
    return (Day)(getStartOfDay(time) - getStartOfYear(time));
}


/* public functions */

// get length of tropical year
Time getTropicalYear() {
    return tropicalYear;
}

// get time of vernal equinox for year
//   by definition, the vernal equinox is the first day of the year,
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

// get starting time for day
Time getStartOfDay(Time time) {
    Day start = (Day)time;
    return (Time)start;
}

// get start time for year
Time getStartOfYear(Time time) {
    return getStartOfDay(getSpringOfYear(time));
}

// get (and initialize) new calendar date
Date getCalendarDate(Time time) {
    Date date;

    if (time < 0) {
        fprintf(stderr, "Warning: invalid calendar time, setting to 0\n");
        time = 0;
    }

    date.time = time;
    date.y = getCalendarYear(time);
    date.moy = 0;	// TBD
    date.dom = 0;	// TBD
    date.doy = getCalendarDayOfYear(time);
    date.numY = getNumWholeYears(time);
    date.numM = 0;	// TBD
    date.numD = getNumWholeDays(time);
    date.numMpy = 0;	// TBD
    date.numDpy = getNumWholeDaysOfYear(time);
    date.numDpm = 0;	// TBD

    return date;
}

// get calendar year for specified calendar date
Year getCalendarYear(Time time) {
    return getNumWholeYears(time) + 1;
}

// get calendar day of year for specified calendar date
Day getCalendarDayOfYear(Time time) {
    return getNumWholeDaysOfYear(time) + 1;
}

// convert years to days, to beginning of year
Day convertYearToBeginDay(Year years) {
    return (Day)(years * tropicalYear);
}

// convert years to days, to middle of year
Day convertYearToMidDay(Year years) {
    return (Day)((years * tropicalYear) + (int)(tropicalYear / 2));
}

// convert years to days, to end of year
Day convertYearToEndDay(Year years) {
    return (Day)(((years + 1) * tropicalYear) - 1);
}

// convert years to days, to random day in year
Day convertYearToRandomDay(Year years) {
    int first = (int)convertYearToBeginDay(years);
    int last = (int)convertYearToEndDay(years);
    return (Day)uRand(first, last);
}

/*
// convert days to ymd date, in earth calendar
YmdTime convertDayToYmd(Day days) {
    YmdTime ymd;

    ymd.y = (Year)(days / tropicalYear);
    Day remainder = days - (ymd.y * tropicalYear);
    ymd.m = (Month)(remainder / earthCal.dpM);
    ymd.d = (Day)(remainder - (ymd.m * earthCal.dpM));

    return ymd;
}
*/

// calculate birth Day, given day, age
Day calcBirthDayByAge(Day onDay, Day atAge) {

    int birthDay = onDay - atAge;
    if (birthDay < 0) {
        fprintf(stderr, "Warning: invalid birthDay (negative), setting to Day 0");
        birthDay = 0;
    }

    return birthDay;
}
