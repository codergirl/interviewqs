#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("This programs takes one argument; a positive integer\n" 
            "where the result is every pair of odd and even\n"
            "bits swapped. i.e. 8=1000 is swapped to 4=0100.\n");

    if (argc != 2) 
    {
        printf("Please provide exactly one argument.\n");
        exit(0);
    }
    unsigned int num = atoi(argv[1]);
    unsigned int result = 0;
    while (num)
    {
        unsigned int subbednum = num & (num-1);
        unsigned int xored = subbednum ^ num;
        unsigned int xoredcopy = xored;
        unsigned int onloc = 0;
        while (xoredcopy)
        {
            onloc++;
            xoredcopy = xoredcopy >> 1;
        }
        if (onloc % 2 == 0)
            result = result | (xored >> 1);
        else
            result = result | (xored << 1);

        num = subbednum;
    }
    printf("result: %d\n", result);
    return result;
}
