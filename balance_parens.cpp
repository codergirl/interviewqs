#include <string>
#include <cstdio>
using namespace std;

typedef struct paren_t {
    char type;
    int loc;
} paren;

int main(void)
{
    string str = "()))((+g)";  
    
    paren parens[20];
    int paren_size = 0;
    
    int i;
    for (i=0; i<str.length(); i++)
    {
        if (str[i] == '(')
        {
            parens[paren_size] = { '(', i};
            paren_size++;
        }
        else if (str[i] == ')')
        {
            if (paren_size == 0)
            {
                parens[paren_size] = {')', i};
                paren_size++;
            }
            else if (parens[paren_size-1].type== '(')
            {
                paren_size--;
            }
        }
    }

    string leftovers;
    for (i=0; i<paren_size; i++)
    {
        leftovers += parens[i].type;
    }
    int loc = leftovers.find("((");
    if (loc != string::npos)
    {
        str[parens[loc+1].loc] = ')';
    }
    loc = leftovers.find("))");
    if (loc != string::npos)
    {
        str[parens[loc].loc] = '(';
    }
    printf("%s\n", str.c_str());
}





