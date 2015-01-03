/*
 * Copyright (c) 2013-2015 Kathy Feller.
 *
 * Source code for rng library.
 */

#include <time.h>
#include <stdlib.h>

#include "rng.h"

// seed and seeded flag
static int seeded = 0;		// 0 is always false
static int seed = 1;		// the default seed for srandom

/* declare private functions */
static void checkSeed(void);

/* public functions */

// initialize the seed
void initSeed(void) {
    seed = (int)(time(NULL));
    srandom(seed);
    seeded++;			// this becomes non-zero and therefore true
}

// get the current seed
int getSeed(void) {
    return seed;
}

// return odd or even of next random number
int coinflip(void) {
    checkSeed();
    return (random() % 2);
}

// normalized random number, uniform distribution
float nRand(void) {
    checkSeed();
    return (float)random() / (float)RAND_MAX;
}

// random number within a range, curve distribution
float cRand(int min, int max, int curve) {
    float num = 0;
    checkSeed();

    int high = (int)(((max - min) / curve) + .5) + 1;

    int i;
    for (i = 0; i < curve; i++)
        num = num + (nRand() * high);
    num = num + min;

    if (num > max)
        num = max;
    if (num < min)
        num = min;

    return num;
}

// random number within a range, bell curve distribution
float bRand(int min, int max) {
    checkSeed();
    return cRand(min, max, 3);
}

// random number within a range, uniform distribution
float uRand(int min, int max) {
    checkSeed();
    return cRand(min, max, 1);
}

// random number within a range, linear distribution
float lRand(int min, int max, int direction) {
    checkSeed();
    float num = 0;
    float x = 0;
    float y = 0;

    if (direction == 1)
        do {
            x = uRand(min, max);
            y = uRand(min, max);
        } while (y > x);
    else {
        do {
            x = uRand(min, max);
            y = uRand(min, max);
        } while (x > y);
    }
    num = x;

    return num;
}

// random number within a range, median centered distribution
float mRand(int min, int max, int median) {
    checkSeed();
    float num = 0;

    if (coinflip() == 1)
        num = num + lRand(min, (median - 1), UP);	// left side
    else
        num = num + lRand(median, max, DOWN);		// right side

    return num;
}

// random percentage, uniform distribution
float pRand(void) {
    checkSeed();
    return (uRand(1, 100)) / 100;
}

/* private functions */

// ensure seed has been set
static void checkSeed(void) {
    if (!seeded) {
        initSeed();
    }

    return;
}
