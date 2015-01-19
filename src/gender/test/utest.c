/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for gender library.
 */

#include <stdio.h>
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
    // TEST: are all return values a recognized GenderType?
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

    // TODO - genNewPersonByBirth()

    // TODO - genNewPersonByBirthByGender()
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
