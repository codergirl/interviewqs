#include <stdio.h>
#include <string.h>
#include <cstdlib>

int main(int argc, char* argv[])
{
    printf("This program takes as input: <string n i> where\n"
            " string is a string of length n which is to be rotated left i places.\n");

    if (argc!=4)
    {
        printf("Bad inputs.\n");
        exit(0);
    }

    char* str = (char*)malloc(sizeof(char)*strlen(argv[1]));
    strcpy(str, argv[1]);
    int n = atoi(argv[2]);
    int i = atoi(argv[3]);

    int k;
    char last = str[0];
    for (k=0; k<=n; k++)
    {
        char curr = last;
        int nextIndex = (k+(n-i))%n;  // rotate right by n-i
        last = str[nextIndex];
        str[nextIndex] = curr;
    }

    printf("Result: %s\n", str);
}
