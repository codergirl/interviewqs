#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc<2) 
    {
        printf("Provide two numbers.\n");
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
        printf("Diffs: %d\n", count);
    }
}
