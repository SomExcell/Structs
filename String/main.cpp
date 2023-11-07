#include <iostream>
#include <vector>
#include <algorithm>

#include "String.h"


int main()
{
    std::vector<String> vec = {"d","a","c","b","b","AA","A","AB","cad","C"};
    sort(begin(vec), end(vec), [](String &x,String &y) {
        for (size_t i = 0; i < std::min(x.length(), y.length()); i++)
        {
            if (std::tolower(x[i]) >= std::tolower(y[i]))
            {
                return false;
            }
        }
        if (x.length() > y.length())
        {
            return false;
        }
        return true;
    });
    reverse(begin(vec), end(vec));
	return 0;
}