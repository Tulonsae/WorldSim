/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for cal library.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../wstime.h"

int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    char *desc = "";
    Time tropicalYear = 365.2422;
    Time time;
    TimeDay days;
    TimeYear years;
    Time invalidTime = -1.5;
    Time duringDay;
    Time duringDayResult;
    TimeYear invalidYear = -1;
    TimeYear ageInYears;
    TimeDay ageInDays;

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
        printf("    expected tropical year = %.5f, tropical year = %.5f\n", tropicalYear, tropical);
    }

    name = "getNumDays()";
    printf("Executing %s\n", name);
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getNumDays(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is correct number of days returned for a time?
    numTests++;
    desc = "return number of days";
    time = 365.3;
    days = getNumDays(time);
    if (days == 365) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    time = %.5f, days = %i\n", time, days);
    }

    name = "getNumYears()";
    printf("Executing %s\n", name);
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (getNumYears(invalidTime) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is correct number of years returned for a time within first year?
    numTests++;
    desc = "return number of years for 1st year";
    time = 360.3;
    years = getNumYears(time);
    if (years == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    time = %.5f, years = %i\n", time, years);
    }
    // TEST: is correct number of years returned for a time within second year?
    numTests++;
    desc = "return number of years for 2nd year";
    time = 650.25;
    years = getNumYears(time);
    if (years == 1) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    time = %.5f, years = %i\n", time, years);
    }

    name = "getStartOfDay()";
    printf("Executing %s\n", name);
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
    // TEST: does start of day return a whole number for a time during day?
    duringDay = 375.6;
    duringDayResult = getStartOfDay(duringDay);
    numTests++;
    desc = "returned as whole number";
    if (duringDayResult == (Time)floor(duringDayResult)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does start of day return the same day?
    duringDay = 375.6;
    duringDayResult = getStartOfDay(duringDay);
    numTests++;
    desc = "returned as same day";
    if (floor(duringDay) == floor(duringDayResult)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getStartOfYear()";
    printf("Executing %s\n", name);
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
    if (getStartOfYear(tropicalYear - .2) == floor(tropicalYear)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does a time after a leap year return the correct spring?
    numTests++;
    desc = "time after a leap year";
    if (getStartOfYear(6 * tropicalYear + 10) == floor(6 * tropicalYear)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getSpringOfYear()";
    printf("Executing %s\n", name);
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

    name = "convertAgeInYearsToDays()";
    printf("Executing %s\n", name);
    // TEST: does this routine return UNDEFINED for an invalid time?
    numTests++;
    desc = "returned UNDEFINED for invalid time";
    if (convertAgeInYearsToDays(BEGIN, invalidYear) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does this routine return UNDEFINED for an invalid sequence?
    numTests++;
    desc = "returned UNDEFINED for invalid sequence";
    if (convertAgeInYearsToDays(RANDOM + 1, FIRST_VALID_TIMEYEAR) == UNDEFINED) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is beginning of year at age 20 calculated correctly?
    numTests++;
    desc = "beginning of year for age";
    ageInYears = 20;
    ageInDays = convertAgeInYearsToDays(BEGIN, ageInYears);
    if (ageInDays == 7304) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    age in years = %i, age in days = %i\n", ageInYears, ageInDays);
    }
    // TEST: is end of year at age 20 calculated correctly?
    numTests++;
    desc = "end of year for age";
    ageInYears = 20;
    ageInDays = convertAgeInYearsToDays(END, ageInYears);
    if (ageInDays == 7669) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    age in years = %i, age in days = %i\n", ageInYears, ageInDays);
    }
    // TEST: is middle of year at age 20 calculated correctly?
    numTests++;
    desc = "middle of year for age";
    ageInYears = 20;
    ageInDays = convertAgeInYearsToDays(MIDDLE, ageInYears);
    if (ageInDays == 7487) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    age in years = %i, age in days = %i\n", ageInYears, ageInDays);
    }
    // TEST: is random day of year at age 20 within first and last days?
    numTests++;
    desc = "random day of year for age";
    ageInYears = 20;
    int count = 1000;
    int failures = 0;
    TimeDay lowAge = convertAgeInYearsToDays(BEGIN, ageInYears);
    TimeDay highAge = convertAgeInYearsToDays(END, ageInYears);
    for (int i = 0; i < count; i++) {
        ageInDays = convertAgeInYearsToDays(RANDOM, ageInYears);
        if ((ageInDays < lowAge) || (ageInDays > highAge))
            failures++;
    }
    if (failures == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    count = %i, failures = %i\n", count, failures);
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
