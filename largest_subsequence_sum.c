#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int largest_subsequence_sum(int arr[], int len)
{
    int global_largest = 0;
    int curr_largest = 0;
    for(int i=0; i<len; i++)
    {
        curr_largest = max(0, curr_largest + arr[i]);
        global_largest = max(global_largest, curr_largest);
    }
    return global_largest;
}

int main(int argc, char* argv[])
{
    printf("Pass in a list of space delimited integers and this "
            "program will print the largest subsequence's sum.\n");
    int len = argc-1;
    int* arr = (int*)malloc(sizeof(int)*len);
    int i;
    for(i=0; i<len; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }
    printf("sum = %d\n", largest_subsequence_sum(arr, len));
}
