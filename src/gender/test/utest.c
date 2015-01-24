/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for gender library.
 */

#include <stdio.h>
#include <string.h>
#include "../gender.h"


// declare private functions
double absD(double number);
double getPerDiff(int expected, int actual);

int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    char *desc = "";
    int count = 0;

    name = "getRandomGender()";
    printf("Executing %s\n", name);
    // generate data
    int female = 0;
    int male = 0;
    int error = 0;
    count = 1000;
    for (int i = 0; i < count; i++) {
        enum GenderType gender = getRandomGender();
        if (gender == GENDER_FEMALE)
            female++;
        else if (gender == GENDER_MALE)
            male++;
        else
            error++;
    }
    // TEST: are all return values a recognized defined GenderType?
    numTests++;
    desc = "valid genders";
    if (error > 0) {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    // TEST: is distribution of genders in an acceptable range?
    numTests++;
    desc = "acceptable distribution";
    int expected = count / 2;
    int acceptable = 5;
    if ((getPerDiff(expected, female) > acceptable) || (getPerDiff(expected, male) > acceptable)) {
        numFail++;
        printf("  %s: %s: %s greater than %i%%\n", name, FAIL, desc, acceptable);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    printf("    female: %i (%f), male: %i (%f)\n", female, (double)female/expected, male, (double)male/expected);

    name = "getGenderName()";
    printf("Executing %s\n", name);
    // TEST: is the correct gender name for GENDER_UNDEFINED returned?
    numTests++;
    desc = "gender name for GENDER_UNDEFINED";
    if (strcmp(getGenderName(GENDER_UNDEFINED), "tbd") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender name for GENDER_UNKNOWN returned?
    numTests++;
    desc = "gender name for GENDER_UNKNOWN";
    if (strcmp(getGenderName(GENDER_UNKNOWN), "unknown") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender name for GENDER_FEMALE returned?
    numTests++;
    desc = "gender name for GENDER_FEMALE";
    if (strcmp(getGenderName(GENDER_FEMALE), "female") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender name for GENDER_MALE returned?
    numTests++;
    desc = "gender name for GENDER_MALE";
    if (strcmp(getGenderName(GENDER_MALE), "male") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getGenderCode()";
    printf("Executing %s\n", name);
    // TEST: is the correct gender code for GENDER_UNDEFINED returned?
    numTests++;
    desc = "gender code for GENDER_UNDEFINED";
    if (strcmp(getGenderCode(GENDER_UNDEFINED), "-") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender code for GENDER_UNKNOWN returned?
    numTests++;
    desc = "gender code for GENDER_UNKNOWN";
    if (strcmp(getGenderCode(GENDER_UNKNOWN), "?") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender code for GENDER_FEMALE returned?
    numTests++;
    desc = "gender code for GENDER_FEMALE";
    if (strcmp(getGenderCode(GENDER_FEMALE), "f") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct gender code for GENDER_MALE returned?
    numTests++;
    desc = "gender code for GENDER_MALE";
    if (strcmp(getGenderCode(GENDER_MALE), "m") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
}

/* private functions */

// get the percentage difference between expected and actual values
double getPerDiff(int expected, int actual) {
    return absD((double)actual/expected - 1) * 100;
}

// get the absolute value of a double
double absD(double number) {
    if (number < 0)
        return -1 * number;
    else
        return number;
}
