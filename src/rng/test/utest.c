/*
 * Copyright (c) 2015, Kathy Feller.
 *
 * Unit tests for rng library.
 */

#include <stdio.h>
#include "../rng.h"

int main(int argc, char *argv[]) {
    int numTests = 0;
    int numFail = 0;
    int numPass = 0;
    char *FAIL = "FAILED";
    char *PASS = "PASSED";
    char *name = "";
    int count = 0;

    /* execute initSeed */
    name = "initSeed()";
    printf("Executing %s\n", name);
    initSeed();

    /* execute getSeed */
    name = "getSeed()";
    printf("Executing %s\n", name);
    int seed = getSeed();
    printf("  %s: Seed is %i\n", name, seed);

    /* execute coinflip */
    // and check if results are within expected ranges
    name = "coinflip()";
    printf("Executing %s\n", name);
    int odd = 0;
    int even = 0;
    int error = 0;
    count = 10;
    // generate numbers
    for (int i = 0; i < count; i++) {
        int flip = coinflip();
        if (flip == ODD)
            odd++;
        else if (flip == EVEN)
            even++;
        else
            error++;
    }
    // TEST: are all return values ODD/EVEN?
    numTests++;
    if (error > 0) {
        numFail++;
        printf("  %s: %s: invalid return values\n", name, FAIL);
    } else {
        numPass++;
        printf("  %s: %s: return values okay\n", name, PASS);
    }
    // TEST: is distribution of odd/even acceptable?
    int expected = count / 2;
    printf("  odd: %i (%f), even: %i (%f)\n", odd, (double)odd/expected, even, (double)even/expected);
}
