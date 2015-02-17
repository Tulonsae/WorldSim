/*
 * Copyright (c) 2015, Kathy Feller.
 */

#include <stdio.h>
#include <calendar.h>
#include <person.h>

int main(int argc, char *argv[]) {
    int count = 10;
    Time curDay = 100.0;
    Id lastId = 0;

    printf("Id\n");
    for (int i = 0; i < count; i++) {
        Person person = createNewPerson();
        // should check the return code of assignIdToPerson
        assignIdToPerson(++lastId, &person);
        printf("%i\n", person.id);
    }
}
