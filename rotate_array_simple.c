#include <stdio.h>
#include <stdlib.h>

char* rotateArray(char* arr, int i, int n)
{
    char* output = (char*)malloc(sizeof(char)*n+1);
    int k;
    for (k=0; k<n; k++)
    {
        int loc = (k+i)%n;
        output[loc] = arr[k];
    }
    output[n] = '\0';
    return output;
}

int main(int argc, char* argv[])
{
    char* arr = argv[1];
    int n = atoi(argv[2]);
    int i = atoi(argv[3]);

    char* result = rotateArray(arr, i, n);
    int k;
    printf("%s\n\n", result);
}
