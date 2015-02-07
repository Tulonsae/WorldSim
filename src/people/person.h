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

// generate a new person
Person genUnknownPerson(void);
//Person genNewPerson(Id id, Time current);

#endif /* PERSON_H */
