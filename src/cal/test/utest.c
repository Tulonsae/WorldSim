/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for cal library.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../calendar.h"

// private functions
bool isTimeWholeNumber(Time time);
Time getTimeAsWholeNumber(Time time);

int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    char *desc = "";
    Time tropicalYear = 365.2422;
    Time time = 0.0;
    CalendarDate date = getDate(time);
    CalendarYear cYear = getCalendarYear(time);
    Day day = 0;
    int age = 0;
    Time invalidTime = -1.5;
    Year invalidYearZero = 0;
    Year invalidYearNegative = -1;
    enum Sequence invalidSequence = RANDOM + 1;

    name = "getTropicalYear()";
    printf("Executing %s\n", name);
    Time tropical = getTropicalYear();
    // TEST: is tropical year the expected constant?
    numTests++;
    desc = "value of tropical year";
    if (tropical == tropicalYear) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getStartOfDay()";
    printf("Executing %s\n", name);
    Time duringDay = 375.6;
    Time duringDayResult = getStartOfDay(duringDay);
    // TEST: does start of day return a whole number for a time during day?
    numTests++;
    desc = "returned as whole number";
    if (isTimeWholeNumber(duringDayResult)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does start of day return the same day?
    numTests++;
    desc = "returned as same day";
    if ((int)duringDay == (int)duringDayResult) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getStartOfDay(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getSpringOfYear()";
    printf("Executing %s\n", name);
    // TEST: does a time within the first year return the first spring of 0?
    numTests++;
    desc = "first year spring";
    if (getSpringOfYear(tropicalYear - 50) == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does a time between the start of the day and a spring return
    //       the spring on that day rather than the previous spring?
    numTests++;
    desc = "time before and on same day as spring";
    if (getSpringOfYear(tropicalYear - .2) == tropicalYear) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does a time after a leap year return the correct spring?
    numTests++;
    desc = "time after a leap year";
    if (getSpringOfYear(6 * tropicalYear + 10) == (6 * tropicalYear)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getSpringOfYear(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getStartOfYear()";
    printf("Executing %s\n", name);
    // TEST: does a time within the first year return 0?
    numTests++;
    desc = "start of first year";
    if (getStartOfYear(tropicalYear - 50) == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does a time between the start of the day and a spring return
    //       the start of year on that day rather than the previous spring?
    numTests++;
    desc = "time before and on same day as spring";
    if (getStartOfYear(tropicalYear - .2) == getTimeAsWholeNumber(tropicalYear)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does a time after a leap year return the correct spring?
    numTests++;
    desc = "time after a leap year";
    if (getStartOfYear(6 * tropicalYear + 10) == getTimeAsWholeNumber(6 * tropicalYear)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getStartOfYear(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getYear()";
    printf("Executing %s\n", name);
    // TEST: does a time within the first year return 1?
    numTests++;
    desc = "first calendar year";
    if (getYear(tropicalYear - 50) == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first full tropical year show as year 2?
    numTests++;
    desc = "first complete tropical year";
    if (getYear(tropicalYear) == 2) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the last day of the first leap year return 5?
    numTests++;
    desc = "last day of first leap year";
    if (getYear(1825.5) == 5) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the first leap year return 6?
    numTests++;
    desc = "first day of year after first leap year";
    if (getYear(1826.0) == 6) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the third leap year return 14?
    numTests++;
    desc = "first day of year after third leap year";
    if (getYear(4748.0) == 14) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getYear(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getDay()";
    printf("Executing %s\n", name);
    // TEST: does a time within the first year return properly?
    numTests++;
    desc = "first calendar year";
    if (getDay(50.5) == 51) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first full tropical year show as day 366?
    numTests++;
    desc = "first complete tropical year";
    if (getDay(tropicalYear) == 366) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the last day of the first leap year return 1826?
    numTests++;
    desc = "last day of first leap year";
    if (getDay(1825.5) == 1826) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the first leap year return 1827?
    numTests++;
    desc = "first day of year after first leap year";
    if (getDay(1826.0) == 1827) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the third leap year return 4749?
    numTests++;
    desc = "first day of year after third leap year";
    if (getDay(4748.0) == 4749) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getDay(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getDayOfYear()";
    printf("Executing %s\n", name);
    // TEST: does first day of first year return 1?
    numTests++;
    desc = "first day of first year";
    if (getDayOfYear(0.5) == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does last day of first year return 365?
    numTests++;
    desc = "last day of first year";
    if (getDayOfYear(tropicalYear - 1) == 365) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first full tropical year show as day of year 1?
    numTests++;
    desc = "first complete tropical year";
    if (getDayOfYear(tropicalYear) == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the last day of the first leap year return 366?
    numTests++;
    desc = "last day of first leap year";
    if (getDayOfYear((tropicalYear * 5) - 1) == 366) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the first leap year return 1?
    numTests++;
    desc = "first day of year after first leap year";
    if (getDayOfYear(tropicalYear * 5) == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does the first day of the year after the third leap year return 1?
    numTests++;
    desc = "first day of year after third leap year";
    if (getDayOfYear(tropicalYear * 13) == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getDayOfYear(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getDate()";
    printf("Executing %s\n", name);
    // TEST: is day of first full tropical year calculated correctly?
    numTests++;
    desc = "day of first full tropical year";
    date = getDate(tropicalYear);
    if ((date.time == tropicalYear)
            && (date.d == 366)
            && (date.y == 2)
            && (date.doy == 1)
            && (date.numY == 1)
            && (date.numD == 365)
            && (date.numDpy == 0)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is last day of first leap year calculated correctly?
    numTests++;
    desc = "last day of first leap year";
    time = (tropicalYear * 5) - 1;
    date = getDate(time);
    if ((date.time == time)
            && (date.d == 1826)
            && (date.y == 5)
            && (date.doy == 366)
            && (date.numY == 4)
            && (date.numD == 1825)
            && (date.numDpy == 365)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is first day of year after first leap year calculated correctly?
    numTests++;
    desc = "first day of year after first leap year";
    time = tropicalYear * 5;
    date = getDate(time);
    if ((date.time == time)
            && (date.d == 1827)
            && (date.y == 6)
            && (date.doy == 1)
            && (date.numY == 5)
            && (date.numD == 1826)
            && (date.numDpy == 0)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    date = getDate(invalidTime);
    if (date.time == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getCalendarYear()";
    printf("Executing %s\n", name);
    // TEST: is first calendar year calculated correctly?
    numTests++;
    desc = "first calendar year";
    cYear = getCalendarYear(50.0);
    if ((cYear.spring == 0.0)
            && (cYear.year == 1)
            && (cYear.first == 1)
            && (cYear.last == 365)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is second calendar year at equinox calculated correctly?
    numTests++;
    desc = "second calendar year at equinox";
    cYear = getCalendarYear(tropicalYear);
    if ((cYear.spring == tropicalYear)
            && (cYear.year == 2)
            && (cYear.first == 366)
            && (cYear.last == 730)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is second calendar year calculated correctly?
    numTests++;
    desc = "second calendar year";
    cYear = getCalendarYear(tropicalYear + 25.9);
    if ((cYear.spring == tropicalYear)
            && (cYear.year == 2)
            && (cYear.first == 366)
            && (cYear.last == 730)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is first leap year at equinox calculated correctly?
    numTests++;
    desc = "first leap year at equinox";
    cYear = getCalendarYear(tropicalYear * 4);
    if ((cYear.spring == (tropicalYear * 4))
            && (cYear.year == 5)
            && (cYear.first == 1461)
            && (cYear.last == 1826)
            && (cYear.length == 366)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: last day of first leap year calculated correctly?
    numTests++;
    desc = "last day of first leap year";
    cYear = getCalendarYear((tropicalYear * 5) - 1);
    if ((cYear.spring == (tropicalYear * 4))
            && (cYear.year == 5)
            && (cYear.first == 1461)
            && (cYear.last == 1826)
            && (cYear.length == 366)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is year after third leap year calculated correctly?
    numTests++;
    desc = "year after third leap year";
    cYear = getCalendarYear(tropicalYear * 13);
    if ((cYear.spring == (tropicalYear * 13))
            && (cYear.year == 14)
            && (cYear.first == 4749)
            && (cYear.last == 5113)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    cYear = getCalendarYear(invalidTime);
    if (cYear.year == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getCalendarYearForYear()";
    printf("Executing %s\n", name);
    // TEST: is first calendar year calculated correctly?
    numTests++;
    desc = "first calendar year";
    cYear = getCalendarYearForYear(1);
    if ((cYear.spring == 0.0)
            && (cYear.year == 1)
            && (cYear.first == 1)
            && (cYear.last == 365)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is second calendar year calculated correctly?
    numTests++;
    desc = "second calendar year";
    cYear = getCalendarYearForYear(2);
    if ((cYear.spring == tropicalYear)
            && (cYear.year == 2)
            && (cYear.first == 366)
            && (cYear.last == 730)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is first leap year calculated correctly?
    numTests++;
    desc = "first leap year";
    cYear = getCalendarYearForYear(5);
    if ((cYear.spring == (tropicalYear * 4))
            && (cYear.year == 5)
            && (cYear.first == 1461)
            && (cYear.last == 1826)
            && (cYear.length == 366)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: is year after third leap year calculated correctly?
    numTests++;
    desc = "year after third leap year";
    cYear = getCalendarYearForYear(14);
    if ((cYear.spring == (tropicalYear * 13))
            && (cYear.year == 14)
            && (cYear.first == 4749)
            && (cYear.last == 5113)
            && (cYear.length == 365)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    spring = %.6f, year = %i, first = %i, last = %i, length = %i\n", cYear.spring, cYear.year, cYear.first, cYear.last, cYear.length);
    }
    // TEST: does this routine return UNDEFINED for a (zero) invalid year?
    numTests++;
    desc = "returned UNDEFINED for invalid year 0";
    cYear = getCalendarYearForYear(invalidYearZero);
    if (cYear.year == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for a (negative) invalid year?
    numTests++;
    desc = "returned UNDEFINED for invalid year negative";
    cYear = getCalendarYearForYear(invalidYearNegative);
    if (cYear.year == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "convertAgeInYearsToDays()";
    printf("Executing %s\n", name);
    // for age 13
    age = 13;
    // TEST: is beginning of year at age 13 calculated correctly?
    numTests++;
    desc = "beginning of year for age";
    day = convertAgeInYearsToDays(BEGIN, age);
    if (day == 4749) {
        numPass++;
        printf("  %s: %s: %s %i okay\n", name, PASS, desc, age);
    } else {
        numFail++;
        printf("  %s: %s: %s %i wrong\n", name, FAIL, desc, age);
        printf("    age = %i, day = %i\n", age, day);
    }
    // TEST: is end of year at age 13 calculated correctly?
    numTests++;
    desc = "end of year for age";
    day = convertAgeInYearsToDays(END, age);
    if (day == 5113) {
        numPass++;
        printf("  %s: %s: %s %i okay\n", name, PASS, desc, age);
    } else {
        numFail++;
        printf("  %s: %s: %s %i wrong\n", name, FAIL, desc, age);
        printf("    age = %i, day = %i\n", age, day);
    }
    // TEST: is middle of year at age 13 calculated correctly?
    numTests++;
    desc = "middle of year for age";
    day = convertAgeInYearsToDays(MIDDLE, age);
    if (day == 4931) {
        numPass++;
        printf("  %s: %s: %s %i okay\n", name, PASS, desc, age);
    } else {
        numFail++;
        printf("  %s: %s: %s %i wrong\n", name, FAIL, desc, age);
        printf("    age = %i, day = %i\n", age, day);
    }
    // TEST: is random day of year at age 13 within first and last days?
    numTests++;
    desc = "random day of year for age";
    day = convertAgeInYearsToDays(RANDOM, age);
    if ((day >= convertAgeInYearsToDays(BEGIN, age)) 
            && (day <= convertAgeInYearsToDays(END, age))
            ) {
        numPass++;
        printf("  %s: %s: %s %i (day=%i) okay\n", name, PASS, desc, age, day);
    } else {
        numFail++;
        printf("  %s: %s: %s %i wrong\n", name, FAIL, desc, age);
        printf("    age = %i, day = %i\n", age, day);
    }
    // TEST: does this routine return UNDEFINED for an invalid sequence?
    numTests++;
    desc = "returned UNDEFINED for invalid sequence";
    day = convertAgeInYearsToDays(invalidSequence, age);
    if (day == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    /* test result totals */
    printf("Results:\n");
    printf("  total tests: %i\n", numTests);
    printf("  tests passed: %i\n", numPass);
    printf("  tests failed: %i\n", numFail);
    if ((numFail + numPass) != numTests)
        printf("  !! Internal issue - test count is wrong\n");
    if (numFail > 0)
        printf("  UNIT TESTS FAILED\n");
    else
        printf("  UNIT TESTS PASSED\n");
}

/* private functions */

// check if the time is a whole number
bool isTimeWholeNumber(Time time) {

    if (time == getTimeAsWholeNumber(time))
        return true;

    return false;
}

Time getTimeAsWholeNumber(Time time) {
    int truncated = (int)time;
    Time wholeTime = (Time)truncated;

    return wholeTime;
}
