#include <stdio.h>
#include <stdlib.h>

void itoa2(int num, char str[])
{
    if (num == 0) 
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int is_neg = 0;
    char buff[11];
    if (num < 0)
    {
        num *= -1;
        is_neg = 1;
    }
    int i;
    for(i=0; num>0; i++)
    {
        buff[i] = (num % 10) + '0';
        num = num / 10;
    }
    int len = i;
    char* curr = &str[0];
    if (is_neg)
    {
        *curr = '-';
        curr++;
    }
    for(i=len-1; i>=0; i--)
    {
        *curr = buff[i];
        curr++;
    }
    *curr = '\0';
}

int main(int argc, char* argv[])
{
    printf("Takes an ascii string and converts it to its corresponding "
           "integer representation.\n");
    char str[11]; // 10 for 2^32 + null
    int integer = atoi(argv[1]);

    itoa2(integer, str);
    
    printf("string: %s\n", str);
}
