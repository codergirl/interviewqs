#include <stdio.h>
#include <stdlib.h>

void rotateArray(int arr[], int n, int i);

int main(void)
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int arr2[] = { 10, 20, 30, 40, 50 };
    
    rotateArray(arr, 6, 2);
//    rotateArray(arr, 5, 2);
//    rotateArray(arr, 5, 5);
}

void rotateArray(int arr[], int n, int i)
{
    int k;
    printf("input array:\n");
    for (k=0; k<n; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n\noutput array:\n");
    int last_loc = 0;
    int new_loc;
    int next_val;
    int last_val = arr[0];
    for (k=0; k<n/2; k++)
    {
        new_loc = (last_loc + i) % n;

        printf("last_loc: %d new_loc: %d last_val: %d\n", 
                last_loc, new_loc, last_val);
        next_val = arr[new_loc];
        arr[new_loc] = last_val;
        last_val = next_val;
        last_loc = new_loc;
    }

    for (k=0; k<n; k++)
    {
        printf("%d ", arr[k]);
    }
    printf("\n\n");

}
