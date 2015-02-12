gender library for WorldSim.

DESCRIPTION
    This library contains routines to define, retrieve, and handle gender
    types for the WorldSim program.

    Language: C library.
    Dependencies: WorldSim rng library routines
    License: MIT
    Copyright: 2015, Kathy Feller.

SPECIAL NOTES
    Only traditional male and female genders are specified at this time.
    (See TODO for more information.)

    In addition to the actual genders, undefined and unknown are defined.
    Note that there is a definite difference between undefined and unknown.
    Undefined means that the gender has not been assigned or determined.
    Unknown means that a determination has been made, but that the gender is
    unknown.  This means that a process can sweep through all persons with
    undefined status and assign a gender to them without changing persons
    whose gender is specified to be unknown.

CONTENTS
    The library sources are contained in this directory.

    For man page style documentation on the library routines, see Doc.txt.

    For unit tests, see the test subdirectory.

BUILD INFORMATION
    Uses standard make and command line c compiler.  (Tested on OSx, Ubuntu.)
    Depends on the overall make structure setup for the WorldSim program.

    To compile and create the library:
        make

    To install for use in WorldSim program:
        make install

    To run unit tests:
        make runtest

TODO
    Add other genders and gender identifications.  This may need to be split
    into biological genders and identification genders.  Mostly because there
    are two major uses for gender in WorldSim: fertility and mating.  The
    library currently combines the two - which is both unrealistic for humans
    and reduces the diversity of societies that can be simulated.  Possibly
    use a mating orientation - which might belong in a different library.
