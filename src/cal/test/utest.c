/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for cal library.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../calendar.h"

int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    char *desc = "";
    Time tropicalYear = getTropicalYear();
    Time time = 0.0;
    CalendarDate date = getDate(time);
    CalendarYear cYear = getCalendarYear(time);
    Time invalidTime = -1.5;
    Year invalidYearZero = 0;
    Year invalidYearNegative = -1;

    char *libName = "libcal.a";

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
            && (date.numDpy == 0)
            ) {
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
            && (date.numDpy == 365)
            ) {
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
            && (date.numDpy == 0)
            ) {
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

    /* test result totals */
    printf("Results:\n");
    printf("  total tests: %i\n", numTests);
    printf("  tests passed: %i\n", numPass);
    printf("  tests failed: %i\n", numFail);
    if ((numFail + numPass) != numTests)
        printf("  !! Internal issue - test count is wrong\n");
    if (numFail > 0)
        printf("  UNIT TESTS FAILED (%s)\n", libName);
    else
        printf("  UNIT TESTS PASSED (%s)\n", libName);
}
