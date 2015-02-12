rng library for WorldSim.

DESCRIPTION
    This library contains routines to generate pseudo-random numbers, with
    differing distributions, which are random enough for the needs of the
    WorldSim program.

    Language: C library.
    Dependencies: standard C library routines: random, srandom, time.
    License: MIT
    Copyright: 2013-2015, Kathy Feller.

SPECIAL NOTES
    A distribution describes the fequency and type of generation for the
    numbers.  For example, a uniform distribution gives an even chance of
    generating any given number in the range specified.  A bell curve
    distribution has a higher chance of generating a number closer to the
    midpoint than either end of the range.  See the Documentation for the
    complete list of distributions.

CONTENTS
    The library sources are contained in this directory.

    For man page style documentation on the library routines, see Doc.txt.

    For unit tests, see the test subdirectory.  (In progress)

    For example uses, see the examples subdirectory.  (TBD)

    For frequency distribution reports, see the reports subdirectory.  (TBD)

BUILD INFORMATION
    Uses standard make and command line c compiler.  (Tested on OSx.)
    Depends on the overall make structure setup for the WorldSim program.

    To compile and create the library:
        make

    To install for use in WorldSim program:
        make install

    To run unit tests:
        make runtest

TODO
    Complete unit tests.
    Add examples of use.
    Add frequency distribution reports.
