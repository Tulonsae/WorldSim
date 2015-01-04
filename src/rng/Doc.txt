Documentation for rng library.
Copyright (c) 2015 Kathy Feller.

NAME
    initSeed, getSeed, coinflip, bRand, cRand, lRand, mRand, nRand, pRand,
    uRand - generate pseudo-random numbers

LIBRARY
    librng.a

SYNOPSIS
    #include <rng.h>

    void
    initSeed(void);

    int
    getSeed(void);

    int
    coinflip(void);

    float
    bRand(int min, int max);

    float
    cRand(int min, int max, int curve);

    float
    lRand(int min, int max, int direction);

    float
    mRand(int min, int max, int median);

    float
    nRand(void);

    float
    pRand(void);

    float
    uRand(int min, int max);

    #define ODD 1
    #define EVEN 0
    #define UP 1
    #define DOWN 0

DESCRIPTION
    These functions are a group of utility functions that use the time(),
    random(), and srandom() functions (from the Standard C Library) to provide
    different distributions of pseudo-random numbers.

    This library doesn't allow for a specified seed.  Repeatable distributions
    are not supported, by intention.  All pseudo-random generating functions
    check if the seed has been set with initSeed and, if not, execute initSeed.
    This limitation can be worked around by executing initSeed() once (so the
    library will set its "seeded" flag) and then executing srandom() with the
    desired seed.

    The initSeed() function sets the seed with the current time() and sets
    the library's internal "seeded" flag.

    The getSeed() function returns the library's current seed, as set by
    initSeed().  Note: if srandom() has been used to set the seed, getSeed()
    will not return the correct value.

    The coinflip() function returns 1 (ODD) or 0 (EVEN) if the next random()
    number is odd or even.

    The nRand() function returns the next random() number as a normalized
    number between 0 and 1 and with a uniform distribution.

    The uRand() function returns the next random() number as a number within
    the specified range and with a uniform distribution.

    The pRand() function returns the next random() number as a percentage - a
    number between 1 and 100, converted to a percentage, and with a uniform
    distribution.

    The cRand() function returns a random number within the specified range
    and with a curved (higher frequency of numbers closer to the midpoint
    of the range) distribution.  A higher curve number produces a more steeply
    curved distribution.

    The bRand() function returns a random number within the specified range
    with a bell curve distribution.  This is exactly the same as cRand() with
    a curve of 3.

    The lRand() function returns a random number within the specified range
    with a linear distribution.  The direction specifies whether the linear
    distribution increases/UP or decreases/DOWN from the minimum to maximum.
    In other words, whether the fequency of the generated numbers is greater
    closer to the maximum (UP) or the minimum (DOWN).

    The mRand() function returns a random number within the specified range
    with a median distribution.  This is a curved distribution where the
    greater frequency of numbers cluster around the specified median rather
    than the midpoint of the range.

SEE ALSO
    random(3) from the Unix/Linux man pages.

TODO
    Nothing planned.

AUTHORS
    Kathy Feller
