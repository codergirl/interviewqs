#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("This programs takes one argument; a positive integer\n" 
           "where the result is every pair of odd and even\n"
           "bits swapped. i.e. 8=1000 is swapped to 4=0100.\n");

    if (argc<2) 
    {
        printf("Error. Provide a number.\n");
        exit(0);
    }
    else
    {
        unsigned int x = atoi(argv[1]);
        printf("%d\n",x);

        int count = 0;
        unsigned int y = 0;
        int i;
        printf("last_two == 0x0? %d\n", (x & 0x3) == 0x0);
        printf("last_two == 0x1? %d\n", (x & 0x3) == 0x1);
        printf("last_two == 0x2? %d\n", (x & 0x3) == 0x2);
        printf("last_two == 0x3? %d\n", (x & 0x3) == 0x3);

        printf("0x1 %d\n", y | 0x1);
        printf("0x2 %d\n", y | 0x2);

        for (i=0; x!=0; x=x>>2,i=i+2)
        {
            if ((x & 0x3) == 0x0) 
                ;
            else if ((x & 0x3) == 0x2)  
                y = y | (0x1 << i); 
            else if ((x & 0x3) == 0x1) 
                y = y | (0x2 << i);
            else                
                y = y | (0x3 << i);
        }
        printf("%d\n", y);
    }
}
