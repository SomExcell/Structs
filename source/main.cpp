#include "String.h"

#include <iostream>
#include <vector>
#include <algorithm>

bool lexicographicWithoutRegistr(String &first, String& second)
{
    for (size_t i = 0; i < std::min(first.size(),second.size()); ++i)
    {
        if(std::tolower(first[i]) > std::tolower(second[i])){return false;}
        else if(std::tolower(first[i]) < std::tolower(second[i])){return true;}
    }
    if(first.size() > second.size()){return false;}
    return true;
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
    sort(vec.begin(),vec.end(),lexicographicWithoutRegistr);
    reverse(vec.begin(),vec.end());

    return 0;
}