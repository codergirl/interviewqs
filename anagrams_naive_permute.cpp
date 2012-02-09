#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

string excludeI(string str, int i)
{
    // no need to make copy, str passed by value
    str.erase(i,1);
    return str;
}

string anagrams(const string str, const string prefix)
{
    if (str.length() == 1)
        return prefix + str + " ";
    
    string all = "";
    for (int i=0; i<str.length(); i++)
    {
        string newprefix(prefix + str[i]);
        all += anagrams(excludeI(str, i),newprefix);
    }
    return all;
}

void check_correctness(string anagrams)
{
    vector<string> v; 
    char* copy = (char*)malloc(sizeof(char)*anagrams.length());
    strcpy(copy,anagrams.c_str());
    char* tok_p = strtok(copy," ");
    vector<string>::iterator findit;
    int i=0;
    while(tok_p)
    {
        basic_string<char> token(tok_p);

        findit = find(v.begin(), v.end(),token);
        if (findit != v.end())
        {
            cout << "Not all anagrams were unique, namely \"" << token << "\".\n";
            break;
        }
        v.push_back(token);
        tok_p = strtok(NULL," ");
        i++;
    }
    cout << v.size() << " unique anagrams found.\n";
}

int main(int argc, char* argv[])
{
    cout << "This program takes as input a string and prints all anagrams of that string.\n";

    if (argc!=2)
    {
        cout << "Bad input.\n";
        exit(0);
    }
    string str = argv[1];
    string anagrams_str = anagrams(str,"");
    cout << anagrams_str << "\n";

    check_correctness(anagrams_str);
}

