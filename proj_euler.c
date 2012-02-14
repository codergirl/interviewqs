#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int find_largest_prime_factor(long long num)
{
    /* observe that the smallest factor of a number num is prime. if it were
     * not prime, its factors would be factors of num and hence it would
     * have not been the smallest factor. so find the smallest factor
     * which has a prime factor. then, divide away the factor and again
     * find the smallest factor. therefore we get all prime factors of num */

    long long i;
    if (num == 1)
        return 0;

    for (i=2; i*i<num; i++)
    {
        if (num % i == 0)
            return max(i, find_largest_prime_factor(num/i));
    }
    return num;
}

void prob3()
{
    long long num = 600851475143;
    printf("largest prime factor is %d\n", find_largest_prime_factor(num));
}

void prob2()
{
    long long i;
    long long total = 2;
    long long prev = 1;
    long long prev2 = 2;
    long long fib;

    while(1)
    {
        fib = prev + prev2;
        if (fib > 4000000)
            break;
        else if (fib % 2 == 0)
            total += fib;

        prev = prev2;
        prev2 = fib;
    }
    printf("prob 2: %lld\n", total);
}

void prob1()
{
    int i = 1;
    int total = 0;
    while (1)
    {
        if (3*i >= 1000 && 5*i >= 1000)
            break;
        else
        {
            if (3*i < 1000)
                total += 3*i;
            if (5*i < 1000)
                if (5*i % 3 != 0) // only add to total if its not a factor of 3
                    total += 5*i;
        }
        i++;
    }
    printf("problem 1: %d\n", total);
}

int main(void)
{
    prob3();
}
