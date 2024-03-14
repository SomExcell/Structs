#include "String.h"
#include "Matrix.hpp"
#include "BinaryTree.hpp"
#include "BinaryHeap.hpp"

#include <iostream>
#include <vector>


int main()
{
    BinaryHeap<std::string> heap{};
    int count;
    std::cin >> count;
    std::string value;
    for (size_t i = 0; i < count; i++)
    {
        std::cin >> value;
        heap.push(value);
    }
    heap.reverse();
    for (size_t i = 0; i < count; i++)
    {
        std::cout << heap.top() << ' ';
        heap.pop();
    }
    
    
}
