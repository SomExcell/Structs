#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include "String.h"

int main()
{
    std::string a = "asdsssssssssssssssssss";
    a+='s';
    a.resize(46);
    a.reserve(100);
    int x = a.capacity();

    size_t countWords;
    std::cin >> countWords;
    std::vector<String> vec(countWords);
    for (size_t i = 0; i < countWords; i++)
    {
        std::cin >> vec[i];
    }
    
    
    

    return 0;
}