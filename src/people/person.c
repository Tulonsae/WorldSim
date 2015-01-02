/*
 * Copyright (c) 2015, Kathy Feller
 */

#include "person.h"

/* declare local functions */


/* public functions */

// generate new person
Person genNewPerson(Day curDay) {
    Person person;

    // TODO

    return person;
}

// generate new person - given gender, age
Person genNewPersonByGenderByAge(Day curDay, enum GenderType gender, Day age) {
    Person person;

    person.gender = gender;
    person.birth = calcBirthDayByAge(curDay, age);

    return person;
}
