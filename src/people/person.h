#ifndef PERSON_H
#define PERSON_H
/*
 * This only allows for 2 (human) parents.  Eventually, need to expand this
 * to include advanced technology (more than 2 dna contributed) and nonhumans
 * (potentially more than 2 genders).
 *
 * Also need to allow for more dynamic relationships - adoption, fostering,
 * surrogate birth mother, and so on.
 *
 * And variety of names, titles, and so on.
 *
 * And marriage, mates, and so on.
 *
 * And genetics or various character traits.
 */

#include <sim.h>
#include <calendar.h>
#include "fertility.h"

// gender type
enum GenderType {
    GENDER_UNDEFINED,			// none assigned
    GENDER_UNKNOWN,			// not known
    GENDER_FEMALE,			// female
    GENDER_MALE,			// male
    GENDER_SIZE,			// number of gender types
};

// basic person data
typedef struct {
    Id id;				// person's unique identifier
    enum GenderType gender;		// gender
    Day birth;				// day of birth
    Day death;				// day of death
    Day firstFertileDay;		// first day of fertility
    Day lastFertileDay;			// last day of fertility
    Id mother;				// id of genetic mother
    Id father;				// id of genetic father
    int numOffspring;			// number of offspring
    Id *offspring[];			// ptr to array of offspring ids
} Person;

// generate a new person
Person genNewPerson(Day curDay);
Person genNewPersonByGenderByAge(Day curDay, enum GenderType gender, Day age);

#endif /* PERSON_H */
