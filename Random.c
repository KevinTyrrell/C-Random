
#include "Random.h"

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
	x += seed;
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
	c = (t >> 32);

	return x + y + (z = (unsigned int)t);
}
