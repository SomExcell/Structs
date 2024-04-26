#include "String.h"

#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(String &first, String& second)
{
    for (size_t i = 0; i < std::min(first.size(),second.size()); ++i)
    {
        if(std::tolower(first[i]) < std::tolower(second[i])){return false;}
        else if(std::tolower(first[i]) > std::tolower(second[i])){return true;}
    }
    if(first.size() < second.size()){return false;}
    return true;
}

void print(const std::vector<String> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << '\n';
    }
}

int main()
{
    size_t countWords;
    std::cin >> countWords;
    std::vector<String> vec(countWords);
    for (size_t i = 0; i < countWords; ++i)
    {
        std::cin >> vec[i];
    }
    sort(vec.begin(),vec.end(),comparator);
    print(vec);
    return 0;
}