#include <string>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <vector>
// challenge: don't use .h's

std::string excludeI(std::string str, int i)
{
    std::string copy(str);
    copy.erase(i,1);
    return copy;
}

std::string anagrams(const std::string str, const std::string prefix)
{
    if (str.length() == 1)
        return prefix + str + " ";
    
    std::string all = "";
    for (int i=0; i<str.length(); i++)
    {
        std::string newprefix(prefix + str[i]);
        all += anagrams(excludeI(str, i),newprefix);
    }
    return all;
}

void check_correctness(std::string anagrams)
{
    std::vector<std::string> v;

    char* tok_p = strtok(anagrams.c_str()," ");
    std::vector<std::string>::iterator findit;
    while(tok_p)
    {
        findit = std::find(v.begin(), v.end(), tok_p);
        if (findit != v.end())
        {
            std::cout << "Not all anagrams were unique, namely \"" << tok_p << "\".\n";
            break;
        }
        v.push_back(tok_p);
    }
    std::cout << v.size() << " anagrams found.\n";
}

int main(int argc, char* argv[])
{
    std::cout << "This program takes as input a string and prints all anagrams of that string.\n";

    if (argc!=2)
    {
        std::cout << "Bad input.\n";
        std::exit(0);
    }
    std::string str = argv[1];
    std::string anagrams_str = anagrams(str,"");
    std::cout << anagrams_str << "\n";

    check_correctness(anagrams_str);
}


