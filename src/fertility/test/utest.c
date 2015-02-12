/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for fertility library.
 */

#include <stdio.h>
#include <string.h>
#include "../fertility.h"


// declare private functions


// main
int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    char *desc = "";
    int count = 0;

    name = "getFertilityName()";
    printf("Executing %s\n", name);
    // TEST: does this routine return empty string for an invalid FertiliyType?
    numTests++;
    desc = "invalid fertility type";
    if (strcmp(getFertilityName(FERTILITY_SIZE), "") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility name for FERTILITY_UNDEFINED returned?
    numTests++;
    desc = "fertility name for FERTILITY_UNDEFINED";
    if (strcmp(getFertilityName(FERTILITY_UNDEFINED), "tbd") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility name for FERTILITY_UNKNOWN returned?
    numTests++;
    desc = "fertility name for FERTILITY_UNKNOWN";
    if (strcmp(getFertilityName(FERTILITY_UNKNOWN), "unknown") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility name for FERTILITY_YES returned?
    numTests++;
    desc = "fertility name for FERTILITY_YES";
    if (strcmp(getFertilityName(FERTILITY_YES), "fertile") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility name for FERTILITY_NO returned?
    numTests++;
    desc = "fertility name for FERTILITY_NO";
    if (strcmp(getFertilityName(FERTILITY_NO), "infertile") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getFertilityCode()";
    printf("Executing %s\n", name);
    // TEST: does this routine return empty string for an invalid FertiliyType?
    numTests++;
    desc = "invalid fertility type";
    if (strcmp(getFertilityCode(FERTILITY_SIZE), "") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility code for FERTILITY_UNDEFINED returned?
    numTests++;
    desc = "fertility code for FERTILITY_UNDEFINED";
    if (strcmp(getFertilityCode(FERTILITY_UNDEFINED), "-") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility code for FERTILITY_UNKNOWN returned?
    numTests++;
    desc = "fertility code for FERTILITY_UNKNOWN";
    if (strcmp(getFertilityCode(FERTILITY_UNKNOWN), "?") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility code for FERTILITY_YES returned?
    numTests++;
    desc = "fertility code for FERTILITY_YES";
    if (strcmp(getFertilityCode(FERTILITY_YES), "f") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is the correct fertility code for FERTILITY_NO returned?
    numTests++;
    desc = "fertility code for FERTILITY_NO";
    if (strcmp(getFertilityCode(FERTILITY_NO), "i") == 0) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "getDefaultFertilityParams()";
    printf("Executing %s\n", name);
    // TEST: are default fertility parameters correct?
    numTests++;
    desc = "default fertility parameters";
    FertilityParams params = getDefaultFertilityParams();
    if ((params.preg.gestation == 266)
            && (params.fRange.startMin == 2922)
            && (params.fRange.startMax == 6209)
            && (params.fRange.startMedium == 4566)
            && (params.fRange.endMin == 16436)
            && (params.fRange.endMax == 20453)
            && (params.fRange.endMedium == 18445)
            && (params.mRange.startMin == 3653)
            && (params.mRange.startMax == 6939)
            && (params.mRange.startMedium == 5297)
            && (params.mRange.endMin == 20089)
            && (params.mRange.endMax == 27758)
            && (params.mRange.endMedium == 23559)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    female fertility range: %i/%i/%i, %i/%i/%i\n", params.fRange.startMin, params.fRange.startMedium, params.fRange.startMax, params.fRange.endMin, params.fRange.endMedium, params.fRange.endMax);
        printf("    male fertility range: %i/%i/%i, %i/%i/%i\n", params.mRange.startMin, params.mRange.startMedium, params.mRange.startMax, params.mRange.endMin, params.mRange.endMedium, params.mRange.endMax);
        printf("    gestation: %i\n", params.preg.gestation);
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
