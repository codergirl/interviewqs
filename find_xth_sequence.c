#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE (10)

long long int factorial(long long int n)
{
     if (n < 0) return 0;
     else if(n > 1) return n*factorial(n-1);
     return 1;
}

void print_bits(int num, int bitlen)
{
    int i;
    char nums[BIT_SIZE+1];
    int num_copy= num;

    for (i=0; i<BIT_SIZE; i++)
    {
        if (num & 1 == 1)
            nums[i] = '1';
        else
            nums[i] = '0';
        num = num >> 1;
    }
    char nums_rev[BIT_SIZE+1] = { 0 };
    for (i=0; i<BIT_SIZE; i++)
    {
        nums_rev[i] = nums[BIT_SIZE-i-1];
    }
    nums_rev[BIT_SIZE] = '\0';

    printf("(%d,%s) ", num_copy, nums_rev);
}

void generate_bit_sequences(int bitlen, int bitsleft, int num, int pos)
{
    if (bitsleft == 0)
    {
        if (pos == (bitlen-1))
        {
            print_bits(num, bitlen);
            return;
        }
        else
            generate_bit_sequences(bitlen, bitsleft, num<<1, pos+1);
    }
    else
    {
        if (pos+bitsleft<bitlen)
        {
            generate_bit_sequences(bitlen, bitsleft, (num<<1), pos+1);
        }
        if (pos < bitlen-1)
        {
            generate_bit_sequences(bitlen, bitsleft-1, (num|1)<<1, pos+1);
        }
        if (pos == (bitlen-1) && bitsleft == 1)
        {
            print_bits(num|1, bitlen);
        }
    }
}

int get_bucket(int seq, int bitlen, int* offset)
{
    int i;
    int total = 0;
    int range;
    for(i=1; ; i++)
    {
        range = factorial(bitlen)/((long)factorial(bitlen-i)*factorial(i));
        total += range;
        if (seq < total)
            break;
    }
    *offset = range -(total - seq);
    return i;
}

int main(int argc, char* argv[])
{
    int bitlen = 10;
    int xth_in_seq = atoi(argv[1]);
    int offset;
    int bucket = get_bucket(xth_in_seq, bitlen, &offset);

    printf("bucket: %d offset: %d\n", bucket, offset);

    generate_bit_sequences(bitlen, bucket, 0, 0);
}

