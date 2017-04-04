# (GitHub-Flavored) Markdown Editor



## Random in C

Library in C to make generating random sequences of integers easier and more robust. The sequence follows the [K.I.S.S algorithm](https://en.wikipedia.org/wiki/KISS_(algorithm)). The sequence has a period of **2<sup>32</sup>**. Afterwards, the sequence of random values will repeat. 


#### Sample:
```c
#include "Random.h"

int main()
{
   /*
    * Seed the Random file before calling other functions.
    * Not calling `rand_seed` will default to the standard seed.
    * Larger seeds are objectively stronger but it shouldn't make much of a difference.
    * A seed of time(NULL) will produce uniformly random results each runtime.
    */ 
   const unsigned int seed = 16252425;
   rand_seed(seed);
   
   /* Generate a value between 25 and 50 inclusive.
    * Note that rand_limit generates a value from 0 to the parameter, exlusive.
    */
   const unsigned int min = 25, max = 50;
   unsigned int random_num = min + rand_limit(max - min + 1);
   printf("Random value between %u and %u: %u.\n", min, max, random_num);  
 
   return 0;
}
```