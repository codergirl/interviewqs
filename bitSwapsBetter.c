#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        printf("Please provide exactly one argument.\n");
        exit(0);
    }
    unsigned int num = atoi(argv[1]);
    unsigned int result = 0;
    while (num)
    {
        int subbednum = num & (num-1);
        int xored = subbednum ^ num;
        int xoredcopy = xored;
        int onloc = 0;
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
