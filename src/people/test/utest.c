/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for people library.
 */

#include <stdio.h>
#include <string.h>
#include "../person.h"


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
    Person person;

    name = "createNewPerson()";
    printf("Executing %s\n", name);
    // TEST: is person data for default unknown person correct?
    numTests++;
    desc = "default unknown person data";
    person = createNewPerson();
    if ((person.id == UNKNOWN)
            && (person.gender == GENDER_UNKNOWN)
            && (person.birth == UNKNOWN)
            && (person.death == UNKNOWN)
            && (person.firstFertileDay == UNKNOWN)
            && (person.lastFertileDay == UNKNOWN)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    person data: id=%i, gender=%s, birth=%i, death=%i, firstFertileDay=%i, lastFertileDay=%i\n", person.id, getGenderName(person.gender), person.birth, person.death, person.firstFertileDay, person.lastFertileDay);
    }

    name = "createNewPersonWithId()";
    printf("Executing %s\n", name);
    // TEST: is person data for default unknown person and id correct?
    numTests++;
    desc = "default unknown person data with id";
    person = createNewPersonWithId(3);
    if ((person.id == 3)
            && (person.gender == GENDER_UNKNOWN)
            && (person.birth == UNKNOWN)
            && (person.death == UNKNOWN)
            && (person.firstFertileDay == UNKNOWN)
            && (person.lastFertileDay == UNKNOWN)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    person data: id=%i, gender=%s, birth=%i, death=%i, firstFertileDay=%i, lastFertileDay=%i\n", person.id, getGenderName(person.gender), person.birth, person.death, person.firstFertileDay, person.lastFertileDay);
    }

    name = "assignIdToPerson()";
    printf("Executing %s\n", name);
    // TEST: does person get specified id assigned?
    numTests++;
    desc = "assign an id to a person";
    person = createNewPerson();
    person = assignIdToPerson(person, 7);
    if (person.id == 7) {
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
