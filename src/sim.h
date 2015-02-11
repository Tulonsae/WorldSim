#ifndef SIM_H
#define SIM_H
/*
 * Copyright (c) 2015 Kathy Feller.
 *
 * Header file that defines basic/fundamental types for WorldSim.
 */

/* constants */
#define UNKNOWN 0
#define UNDEFINED -1

/* id */
typedef int Id;

/* sequence */
enum Sequence {
    BEGIN,
    MIDDLE,
    END,
    RANDOM
};

#endif /* SIM_H */
