#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define LETTERS_PER_KEY 3

void print_power_set();
void print_combinations_of_a_string();
void print_telephone_words();

// note: compile me with -lm
int main(void)
{
//    print_power_set();
//    print_combinations_of_a_string();
    print_telephone_words();
}

void print_combinations_of_a_string()
{
    char arr[] = "snows";

    printf("\n\nCombinations of string %s:\n", arr);
    
}

char get_char_key(int telephone_key, int loc)
{
    switch (telephone_key)
    {
        case 1: return '1'; 
        case 2: 
            if (loc == 0) return 'A';
            else if (loc == 1) return 'B';
            else if (loc == 2) return 'C';
        case 3:
            if (loc == 0) return 'D';
            else if (loc == 1) return 'E';
            else if (loc == 2) return 'F';
        case 4:
            if (loc == 0) return 'G';
            else if (loc == 1) return 'H';
            else if (loc == 2) return 'I';
    }
    return 'Y';
}

void print_telephone_words_(char* prefix, int prefix_size, int remaining[], int remain_size)
{
    if (remain_size == 0)
    {
        printf("%s\n", prefix);
        return;
    }

    int* remaining_new = (int*)malloc(sizeof(int)*remain_size-1); 
    int i;
    for(i=0; i<remain_size-1;i++)
        remaining_new[i] = remaining[i+1];

    // can declare this outside of the loop since new_prefix wont get overwritten
    // until next loop iteration at which point the recursive call has completed
    // and the word has been printed. would not work if words were returned in 
    // base case unless prefix was copied into new str
    char* new_prefix = (char*)malloc(sizeof(char)*prefix_size+2);
    for(i=0; i<LETTERS_PER_KEY; i++)
    {
        char letter = get_char_key(remaining[0], i);
        sprintf(new_prefix, "%s%c", prefix, letter); // terminates with NULL
        print_telephone_words_(new_prefix, prefix_size+1, remaining_new, remain_size-1);
    }
    free(remaining_new);
    free(new_prefix);
}

void print_telephone_words()
{
    int number[] = {3,4,2};
    
    
    print_telephone_words_("", 0, number, 3);
}

void print_power_set()
{
    int binary_num;
    char arr[] = "abcdef";
    printf("\nPower set of %s:\n", arr);

    int n = strlen(arr);

    int power_set_size = pow(2,n);
    int bit_mask;

    for (binary_num=0; binary_num<power_set_size; binary_num++)
    {
        for (bit_mask=0; bit_mask<n; bit_mask++)
        {
            if (binary_num & (1<<bit_mask)) // bit at index bit_mask is on
            {
                printf("%c", arr[bit_mask]);
            }
        }
        printf(" ");
    }
}


