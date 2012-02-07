#include <stdio.h>
#include <stdlib.h>

int binary_search(int arr[], int target, int low, int high)
{
    if (low > high)
        return 0;

    int mid = (high - low)/2 + low;
    printf("low=%d mid=%d high=%d arr[mid]=%d target=%d\n", low,mid,high,arr[mid],target);

    if (target == arr[mid])
        return 1;
    else if (target < arr[mid])
        binary_search(arr, target, low, mid-1);
    else //if (target > arr[mid])
        binary_search(arr, target, mid+1, high);
}

int main(void)
{
    int arr[8] = { 1, 2, 5, 6, 7, 12, 22, 28 };
    int res = binary_search(arr, 1, 0, sizeof(arr)/sizeof(int)-1);
    printf("result: %s\n", res == 1 ? "true" : "false");
}
