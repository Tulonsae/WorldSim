/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include <stdio.h>
#include <calendar.h>
#include <people.h>

int main(int argc, char *argv[]) {
    int count = 10;
    Time curDay = 100.0;
    Id lastId = 0;

    printf("Id\tGender\n");
    for (int i = 0; i < count; i++) {
        Person person = createNewPersonWithId(++lastId);
        assignGenderToPerson(genGenderRandomly(), &person);
        printf("%i\t%s\n", person.id, getGenderCode(person.gender));
    }
}
