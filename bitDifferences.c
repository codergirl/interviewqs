#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("This program takes two positive integers and prints the\n"
            "number of bit swaps that are required to make the numbers\n"
            "the same. i.e. 5=101 and 9=1001 would require 2 swaps.\n"

    if (argc<2) 
    {
        printf("Error. Provide two numbers.\n");
        exit(0);
    }
    else
    {
        unsigned int x = atoi(argv[1]);
        unsigned int y = atoi(argv[2]);

        unsigned int z;
        int count = 0;
        for (z=x^y; z!=0; z=z>>1)
        {
            count += z & 1;
        }
        printf("Differences: %d\n", count);
    }
}
