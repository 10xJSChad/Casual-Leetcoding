/*
 * Very simple keygen, generates quite 'predictable' keys.
 * Pretty difficult to make them appear unique, since there is a length
 * limit of 7 characters and the sum of each digit has to add up to exactly 50.
 * 
 * I also chose to make them exactly 7 characters, since it looked nice when they'd all
 * print out neatly at the same width in a while loop :)
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RAND_TIMESEED() srand(time(NULL))
#define RAND_RANGE(min, max) (min + rand() % (max - min + 1))
#define DEFAULT_SURPLUS 13
#define MAX_LENGTH 7
typedef unsigned char uint8;


int
main()
{
    // rand my beloved
    RAND_TIMESEED();

    uint8 total_surplus = DEFAULT_SURPLUS;
    uint8 digit_surplus = 0;
    
    for (uint8 i = 0; i < MAX_LENGTH; ++i) {
        digit_surplus = total_surplus > 9 ? RAND_RANGE(1, 4)
                        : i <= total_surplus ? RAND_RANGE(i, total_surplus)
                                       : total_surplus;
        total_surplus -= digit_surplus;
        printf("%d", 9 - digit_surplus);
    }

    return 0;
}