
/*
Author: Kevin Tyrrell
Date: 4/04/2017
Version: 1.0
*/

#pragma once

#include <stdbool.h>
#include <math.h>

/* Seeds this pseudo-random number generator with a provided value. */
void rand_seed(const unsigned int seed);
/* Generates a pseudo-random unsigned integer value from the current sequence. */
unsigned int rand_next();
/* Returns a pseudo-random unsigned integer in the domain of [0,limit). */
unsigned int rand_limit(const unsigned int limit);
/* Returns a pseudo-random boolean value based on the current sequence. */
bool rand_bool();