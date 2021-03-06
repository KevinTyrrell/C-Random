﻿
/*
Copyright © 2017 Kevin Tyrrell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * File Name:       Random.c
 * File Author:     Kevin Tyrrell
 * Date Created:    04/04/2017
 */

#include "../include/Random.h"

/* Local functions. */
static unsigned int rand_KISS();

/* Seed variables for this generator. */
static unsigned int x = 123456789,
        y = 362436000,
        z = 521288629,
        c = 7654321;

/*
* Seeds this pseudo-random number generator with a provided value.
* If a seed is not provided, random values will still be safe to use.
* All values of [0, UINT_MAX] are safe to use.
* Θ(1)
*/
void rand_seed(const unsigned int seed)
{
    /* Add `2` to the seed to prevent seeds of `0` and `1`. */
    z *= seed + 2;
}

/*
* Generates a pseudo-random unsigned integer value from the current sequence.
* See: `KISS` documentation.
* Θ(1)
*/
unsigned int rand_next()
{
    return rand_KISS();
}

/*
* Returns a pseudo-random unsigned integer in the domain of [0,limit).
* Θ(1)
*/
unsigned int rand_limit(const unsigned int limit)
{
    return rand_KISS() % limit;
}

#define RAND_FLOAT_MAX 1000000
/*
 * Returns a pseudo-random float in the domain of [0, 1].
 * Θ(1)
 */
float rand_float()
{
    unsigned int num = rand_limit(RAND_FLOAT_MAX);
    return num / (float)RAND_FLOAT_MAX;
}

/*
 * Returns a pseudo-random boolean value based on the current sequence.
 * Θ(1)
 */
bool rand_bool()
{
    return rand_limit(2) == 0;
}

/*
* Keep It Simple Stupid (KISS)
* Source: https://en.wikipedia.org/wiki/KISS_(algorithm)
* y, z, and c cannot be set to zero.
* Θ(1)
*/
static unsigned int rand_KISS()
{
    const unsigned long long a = 698769069ULL;
    unsigned long long t;

    x = 69069 * x + 12345;

    y ^= (y << 13);
    y ^= (y >> 17);
    y ^= (y << 5);

    t = a * z + c;
    c = (unsigned int)(t >> 32);

    return x + y + (z = (unsigned int)t);
}
