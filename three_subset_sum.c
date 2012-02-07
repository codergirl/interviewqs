#include <stdio.h>
#include <stdlib.h>

int comparator(const void* a, const void* b)
{
    return (*((int*)a)) - (*((int*)b));
}

int three_subset_sum(int arr[], int n)
{
    // sort the array
    qsort(arr, n, sizeof(int), comparator);

    int i;
    for (i=0; i<n; i++)
    {
        int j=i+1;
        int k=n-1;
        while (j<k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum == 0)
            {
                printf("\nSubset: %d + %d + %d = %d\n", arr[i], arr[j], arr[k], sum);
                return 1;
            }
            else if (sum<0)
                j++;
            else
                k--;
        }
    }
    printf(" \nNone sum to 0.\n");
    return 0;
}

void three_subset_sum_intro(int arr[], int n)
{
    printf("\nArray: ");
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    three_subset_sum(arr, n);
}

int main()
{
    printf("This program finds 3 elements that sum to 0 in an array, or reports that \n"
            "none are found. It is O(n^2) in complexity and constant in space, although \n"
            "it destroys the input array.\n");
    int arr[] = { 15, -6, -2, 12, 22, -1, 15, 7, 82 };
    int n = sizeof(arr)/sizeof(int);

    three_subset_sum_intro(arr, n);
    arr[0] = -80;
    three_subset_sum_intro(arr, n);
    arr[0] = 2;
    three_subset_sum_intro(arr, n);
}


