#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void generate_balanced_parens(int openCount, int closeCount, string s)
{
    if (openCount == 0 && closeCount == 0)
        cout << s << "\n";

    if (openCount > 0)
        generate_balanced_parens(openCount-1, closeCount+1, s + '(');

    if (closeCount > 0)
        generate_balanced_parens(openCount, closeCount-1, s + ')');
}

int main(int argc, char* argv[])
{
    int pairs = atoi(argv[1]);
    generate_balanced_parens(pairs, 0, "");
}
