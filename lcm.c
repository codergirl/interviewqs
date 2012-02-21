#include <stdio.h>
#include <stdlib.h>

int nextNonZero(int arr[], int size, int start)
{
    int i;
    for(i=start; i<size; i++)
    {
        if (arr[i] > 0)
            return arr[i]; 
    }
    return -1;
}
void sieve(int n, int primesOut[], int* num_primes)
{
    int* primes = (int*)malloc(sizeof(int)*n);
    long i;
    for (i=0; i<n; i++)
    {
        primes[i] = i;
    }
    primes[1] = 0; // special case!
    printf("%d\n", primes[n-1]);

    long p=2;
    while (p != -1)
    {
        for (i=p; i*p<n; i++) 
//            printf("%ld*%ld=%ld\n", i, p, i*p);
            primes[i*p] = 0; 

        if (i*p >= n) break;
        p = nextNonZero(primes, n, p+1);
    }

    int primesInd = 0;
    for (i=1; i<n; i++)
    {
        if (primes[i])
        {
            primesOut[primesInd] = primes[i];
            primesInd++;
        }
    }
    *num_primes = primesInd;
}

int lcm(int nums[], int size)
{
    int* m[1000];
}

int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);
    int primes[n];

    printf("%lu\n", sizeof(primes)/sizeof(int));
    int num_primes;
    sieve(n, primes, &num_primes);
    
    int i;
    printf("Number of primes is %d:\n", num_primes);
    for(i=0; i<num_primes; i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n\n");
}
