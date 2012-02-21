#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void prob4()
{
    const int LIMIT = 20;
    printf("Problem 4:\nFind the largest palindrome made from the product of two 3-digit "
            "numbers.\n");

    unsigned long long total = 1*7*8*9*11*12*13*14*15*16*17*18*19*20;
    long long running_total = total;
    long long curr_total;
    long long prev_total;
    int i;
    int outer;
    for(outer=0; ; outer++)
    {
        for(i=2;i<=LIMIT; i++)
        {
            if (running_total % i == 0)
            {
                curr_total = running_total / i;
                int j;
                for (j=2; j<=LIMIT; j++)
                {
                    if (curr_total % j != 0)
                        break;
                }
                if (j==LIMIT+1)
                {
                    running_total = curr_total;
                }
            }
        }
        if(prev_total == running_total)
            break;
        else
            prev_total = running_total;
    }
    printf("result: %lld\n", running_total);
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
    printf("Problem 3:\nFind the largest prime factor of a composite number.\n");

    long long num = 600851475143;
    printf("result: %d\n\n", find_largest_prime_factor(num));
}

void prob2()
{
    printf("Problem 2:\nBy considering the terms in the Fibonacci sequence whose values\n"
            "do not exceed four million, find the sum of the even-valued terms.\n");
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
    printf("result: %lld\ni\n", total);
}

void prob1()
{
    printf("Problem 1:\nAdd all the natural numbers below 1,000 that are multiples of "
            "3 or 5.\n");

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
    printf("result: %d\n\n", total);
}

int main(void)
{
    prob1();
    prob2();
    prob3();
    prob4();
}
