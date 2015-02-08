#ifndef PERSON_H
#define PERSON_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file for person data and routines.
 */

#include <sim.h>
#include <calendar.h>
#include <gender.h>
#include <fertility.h>

// person data
typedef struct {
    Id id;				// person's id, within the region
    enum GenderType gender;		// gender
    Day birth;				// day of birth
    Day death;				// day of death
    Day firstFertileDay;		// first day of fertility
    Day lastFertileDay;			// last day of fertility
} Person;

// create a person, with default (unknown) data
Person createNewPerson(void);
// create a person, with default (unknown) data and specified id
Person createNewPersonWithId(Id id);

// assign data values to person
Person assignIdToPerson(Person person, Id id);
Person assignGenderToPerson(Person person, enum GenderType gender);
Person assignBirthDayToPerson(Person person, Day birth);
Person assignDeathDayToPerson(Person person, Day death);

//Person genNewPerson(Id id, Time current);

#endif /* PERSON_H */
