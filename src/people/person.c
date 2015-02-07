/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include "person.h"

/* private variables */


/* declare private functions */

Person createNewPerson(Id id, enum GenderType gender, Day birthDay);


/* private functions */

Person createNewPerson(Id id, enum GenderType gender, Day birthDay) {
    Person person;

    person.id = id;
    person.gender = gender;
    person.birth = birthDay;
    person.death = UNKNOWN;
    person.firstFertileDay = UNKNOWN;
    person.lastFertileDay = UNKNOWN;

    return person;
}


/* public functions */

// generate a new person with unknown values
Person genUnknownPerson(void) {
    return createNewPerson(UNKNOWN, GENDER_UNKNOWN, UNKNOWN);
}

/*
// generate a new person
Person genNewPerson(Id id, Time current) {
    return createNewPerson(UNKNOWN, GENDER_UNKNOWN, UNKNOWN);
}
*/
