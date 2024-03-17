#include "String.h"
#include "Matrix.hpp"
#include "BinarySearchTree.hpp"
#include "BinaryHeap.hpp"

#include <iostream>
#include <vector>
#include <set>


int main()
{
    BinarySearchTree<int> tree{};
    int count,value;
    std::cin >> count;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> value;
        tree.insert(value);
    }
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> value;
        tree.erase(value);
    }
    
    
    
}
