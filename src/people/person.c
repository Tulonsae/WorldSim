/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include "person.h"

/* private variables */


/* declare private functions */

// create a new person object
Person createPersonObject(void);
// copy an existing person object
Person copyPersonObject(Person orig);


/* private functions */

Person createPersonObject(void) {
    Person person;

    person.id = UNKNOWN;
    person.gender = GENDER_UNDEFINED;
    person.birth = UNKNOWN;
    person.death = UNKNOWN;
    person.firstFertileDay = UNKNOWN;
    person.lastFertileDay = UNKNOWN;

    return person;
}

Person copyPersonObject(Person orig) {
    Person person;

    person.id = orig.id;
    person.gender = orig.gender;
    person.birth = orig.birth;
    person.death = orig.death;
    person.firstFertileDay = orig.firstFertileDay;
    person.lastFertileDay = orig.lastFertileDay;

    return person;
}

/* public functions */

// create a person with default (unknown) data
Person createNewPerson(void) {
    return createPersonObject();
}

// create a person with default (unknown) data with id
Person createNewPersonWithId(Id id) {
    Person person = createPersonObject();
    person.id = id;
    return person;
}

// assign person id
Person assignIdToPerson(Person person, Id id) {
    Person copy = copyPersonObject(person);
    copy.id = id;
    return copy;
}

// assign gender type
Person assignGenderToPerson(Person person, enum GenderType gender) {
    Person copy = copyPersonObject(person);
    copy.gender = gender;
    return copy;
}

// assign day of birth
Person assignBirthDayToPerson(Person person, Day birth) {
    Person copy = copyPersonObject(person);
    copy.birth = birth;
    return copy;
}

// assign day of death
Person assignDeathDayToPerson(Person person, Day death) {
    Person copy = copyPersonObject(person);
    copy.death = death;
    return copy;
}
