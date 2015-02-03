#ifndef RNG_H
#define RNG_H
/*
 * Copyright (c) 2013-2015 Kathy Feller.
 *
 * Header file for rng library.
 */

#define _XOPEN_SOURCE 500
#include <time.h>
#include <stdlib.h>

/* odd or even */
#define ODD	1
#define EVEN	0

/* increasing (up) or decreasing (down) */
#define UP	1
#define DOWN	0

/* Initialize the seed to the current time in seconds */
void initSeed(void);

/* Get the current seed */
int getSeed(void);

/* Flip a coin - return odd or even of next random number */
int coinflip(void);

/* Get a normalized [0,1] random number, uniform distribution */
float nRand(void);

/* Get a random number within specified range, curve distribution */
float cRand(int min, int max, int curve);

/* Get a random number within specified range, bell curve distribution */
float bRand(int min, int max);

/* Get a random number within specified range, uniform distribution */
float uRand(int min, int max);

/* Get a random number within specified range, linear distribution */
float lRand(int min, int max, int direction);

/* Get a random number within specified range, median centered distribution */
float mRand(int min, int max, int median);

/* Get a random percentage, uniform distribution */
float pRand(void);

#endif /* RNG_H */
