/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for people library.
 */

#include <stdio.h>
#include <string.h>
#include "../people.h"


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
    Day age;
    bool okFlag;

    char *libName = "libpeople.a";

    name = "createNewPerson()";
    printf("Executing %s\n", name);
    // TEST: is person data for initial person correct?
    numTests++;
    desc = "initial person";
    person = createNewPerson();
    if ((person.id == UNDEFINED)
            && (person.gender == GENDER_UNDEFINED)
            && (person.birth == UNDEFINED)
            && (person.death == UNDEFINED)
            && (person.firstFertileDay == UNDEFINED)
            && (person.lastFertileDay == UNDEFINED)
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
    // TEST: is person data for initial person with specified id correct?
    numTests++;
    desc = "initial person with specified id";
    person = createNewPersonWithId(3);
    if ((person.id == 3)
            && (person.gender == GENDER_UNDEFINED)
            && (person.birth == UNDEFINED)
            && (person.death == UNDEFINED)
            && (person.firstFertileDay == UNDEFINED)
            && (person.lastFertileDay == UNDEFINED)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    person data: id=%i, gender=%s, birth=%i, death=%i, firstFertileDay=%i, lastFertileDay=%i\n", person.id, getGenderName(person.gender), person.birth, person.death, person.firstFertileDay, person.lastFertileDay);
    }
    // TEST: is person data for initial person with (invalid) id 0 correct?
    numTests++;
    desc = "initial person with invalid (0) specified id";
    person = createNewPersonWithId(0);
    if ((person.id == UNDEFINED)
            && (person.gender == GENDER_UNDEFINED)
            && (person.birth == UNDEFINED)
            && (person.death == UNDEFINED)
            && (person.firstFertileDay == UNDEFINED)
            && (person.lastFertileDay == UNDEFINED)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
        printf("    person data: id=%i, gender=%s, birth=%i, death=%i, firstFertileDay=%i, lastFertileDay=%i\n", person.id, getGenderName(person.gender), person.birth, person.death, person.firstFertileDay, person.lastFertileDay);
    }
    // TEST: is person data for initial person with (invalid) negative id correct?
    numTests++;
    desc = "initial person with invalid (negative) specified id";
    person = createNewPersonWithId(-2);
    if ((person.id == UNDEFINED)
            && (person.gender == GENDER_UNDEFINED)
            && (person.birth == UNDEFINED)
            && (person.death == UNDEFINED)
            && (person.firstFertileDay == UNDEFINED)
            && (person.lastFertileDay == UNDEFINED)
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
    // TEST: is false returned for invalid id?
    numTests++;
    desc = "boolean result for invalid id";
    person = createNewPerson();
    if (assignIdToPerson(-1, &person)) {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    // TEST: is true returned for valid id?
    numTests++;
    desc = "boolean result for valid id";
    person = createNewPerson();
    if (assignIdToPerson(FIRST_VALID_ID, &person)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: does person get specified id assigned?
    numTests++;
    desc = "valid id assigned to a person";
    person = createNewPerson();
    if ((assignIdToPerson(7, &person))
            && (person.id == 7)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "assignGenderToPerson()";
    printf("Executing %s\n", name);
    // TEST: is false returned for invalid gender?
    numTests++;
    desc = "boolean result for invalid gender";
    person = createNewPerson();
    if (assignGenderToPerson(GENDER_SIZE, &person)) {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    // TEST: is true returned for valid gender?
    numTests++;
    desc = "boolean result for valid gender";
    person = createNewPerson();
    if (assignIdToPerson(GENDER_UNKNOWN, &person)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned gender type of undefined?
    numTests++;
    desc = "assign undefined gender";
    person = createNewPerson();
    if ((assignGenderToPerson(GENDER_UNDEFINED, &person))
            && (person.gender == GENDER_UNDEFINED)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned gender type of unknown?
    numTests++;
    desc = "assign unknown gender";
    person = createNewPerson();
    if ((assignGenderToPerson(GENDER_UNKNOWN, &person))
            && (person.gender == GENDER_UNKNOWN)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned gender type of female?
    numTests++;
    desc = "assign female gender";
    person = createNewPerson();
    if ((assignGenderToPerson(GENDER_FEMALE, &person))
            && (person.gender == GENDER_FEMALE)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned gender type of male?
    numTests++;
    desc = "assign male gender";
    person = createNewPerson();
    if ((assignGenderToPerson(GENDER_MALE, &person))
            && (person.gender == GENDER_MALE)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "assignBirthDayToPerson()";
    printf("Executing %s\n", name);
    // TEST: is false returned for invalid day?
    numTests++;
    desc = "boolean result for invalid day";
    person = createNewPerson();
    if (assignBirthDayToPerson(-1, &person)) {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    // TEST: is true returned for valid day?
    numTests++;
    desc = "boolean result for valid day";
    person = createNewPerson();
    if (assignBirthDayToPerson(FIRST_VALID_DAY, &person)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned specified day of birth?
    numTests++;
    desc = "assign day of birth";
    person = createNewPerson();
    if ((assignBirthDayToPerson(10, &person))
            && (person.birth == 10)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "assignDeathDayToPerson()";
    printf("Executing %s\n", name);
    // TEST: is false returned for invalid day?
    numTests++;
    desc = "boolean result for invalid day";
    person = createNewPerson();
    if (assignDeathDayToPerson(-1, &person)) {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    } else {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    }
    // TEST: is true returned for valid day?
    numTests++;
    desc = "boolean result for valid day";
    person = createNewPerson();
    if (assignDeathDayToPerson(FIRST_VALID_DAY, &person)) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is person correctly assigned specified day of death?
    numTests++;
    desc = "assign day of death";
    person = createNewPerson();
    if ((assignDeathDayToPerson(100, &person))
            && (person.death == 100)
            ) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }

    name = "genAgeRandomly()";
    printf("Executing %s\n", name);
    // TEST: is age a valid day?
    numTests++;
    desc = "valid day returned";
    count = 1000;
    okFlag = true;
    for (int i = 0; i < count; i++) {
        age = genAgeRandomly();
        if (age < FIRST_VALID_DAY) {
            okFlag = false;
            break;
        }
    }
    if (okFlag) {
        numPass++;
        printf("  %s: %s: %s okay\n", name, PASS, desc);
    } else {
        numFail++;
        printf("  %s: %s: %s wrong\n", name, FAIL, desc);
    }
    // TEST: is age a valid age (less than or equal to MAX_AGE)?
    numTests++;
    desc = "valid age returned";
    count = 1000;
    Day maxAge = convertAgeInYearsToDays(END, MAX_AGE);
    okFlag = true;
    for (int i = 0; i < count; i++) {
        age = genAgeRandomly();
        if (age > maxAge) {
            okFlag = false;
            break;
        }
    }
    if (okFlag) {
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

/* private functions */
