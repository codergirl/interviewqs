#include <stdio.h>
#include <stdlib.h>

int arrLeader ( int a[], int n ) {
    
    if (n==0 || n==1) 
        return -1;
    
    // find the median
    int ind = 0;
    int count = 1;
    int i;
    for(i=0; i<n; i++)
    {
        if (a[i] == a[ind])
            count++;
        else
            count--;
        
        if (count==0)
        {
            ind = i;
            count = 1;
        }
    }
    int median = a[ind];
    
    // check that it occurs over half the time
    int occurrences = 0;
    for (i=0; i<n; i++)
    {
        if (a[i]==median)
            occurrences++;
    }
    if (occurrences > (n-occurrences))
        return median;
        
    return -1; 
}

int main(void)
{
    int arr[]  = {1, 1, 2, 3, 1};
    int arr2[] = {1, 1, 2, 3};
    int arr3[] = {1};

    int arr4[] = {1, 1, 2, 7};

    int i;
    for (i=0; i<4; i++)
        printf("%d ", arr4[i]);
  
    printf("\nmajority: %d\n", arrLeader(arr4, 4));
}


