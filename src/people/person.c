/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include "people.h"

/* private variables */


/* declare private functions */

// initialize a new person
Person initPerson(void);


/* private functions */

Person initPerson(void) {
    Person person;

    person.id = UNDEFINED;
    person.gender = GENDER_UNDEFINED;
    person.birth = UNDEFINED;
    person.death = UNDEFINED;
    person.firstFertileDay = UNDEFINED;
    person.lastFertileDay = UNDEFINED;

    return person;
}


/* public functions */

// create a new person, with undefined data
Person createNewPerson(void) {
    return initPerson();
}

// create a new person, with undefined data and specified id
Person createNewPersonWithId(Id id) {
    Person person = initPerson();

    if (id < FIRST_VALID_ID)
        person.id = UNDEFINED;
    else
        person.id = id;

    return person;
}

// assign person id
bool assignIdToPerson(Id id, Person *person) {

    if (id < FIRST_VALID_ID)
        return false;

    person->id = id;
    return true;
}

// assign gender type
bool assignGenderToPerson(enum GenderType gender, Person *person) {

    if (!isValidGenderType(gender))
        return false;

    person->gender = gender;
    return true;
}

// assign day of birth
bool assignBirthDayToPerson(Day birth, Person *person) {

    if (birth < FIRST_VALID_DAY)
        return false;

    person->birth = birth;
    return true;
}

// assign day of death
bool assignDeathDayToPerson(Day death, Person *person) {

    if (death < FIRST_VALID_DAY)
        return false;

    person->death = death;
    return true;
}
