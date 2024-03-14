#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(const BinaryHeap& rhs):values(rhs.values){}

BinaryHeap::BinaryHeap(BinaryHeap&& rhs)
{
    values = std::move(rhs.values);
}

BinaryHeap& BinaryHeap::operator=(const BinaryHeap& rhs)
{
    if(this == &rhs){return *this;}
    values = rhs.values;
}

BinaryHeap& BinaryHeap::operator=(BinaryHeap&& rhs)
{
    if(this == &rhs){return *this;}
    values = std::move(rhs.values);
}

void BinaryHeap::push(const int &value)
{
    values.push_back(value);
    trickleUp(values.size()-1);
}

void BinaryHeap::pop()
{
    std::swap(values[0],values[values.size()-1]);
    values.pop_back();
    trickleDown(0);
}

int BinaryHeap::max()
{
    return values[0];
}

void BinaryHeap::trickleUp(const int &currentIndex)
{
    int pIndex = parentIndex(currentIndex);
    if(pIndex == currentIndex || values[pIndex] > values[currentIndex]){return;}
    std::swap(values[pIndex],values[currentIndex]);
    trickleUp(pIndex);
}

void BinaryHeap::trickleDown(const int &currentIndex)
{
    int greatChildIndex(graterChildIndex(leftChildIndex(currentIndex),rightChildIndex(currentIndex)));
    if(greatChildIndex == -1){return;}
    else if(values[greatChildIndex] < values[currentIndex]){return;}
    std::swap(values[greatChildIndex],values[currentIndex]);
    trickleDown(greatChildIndex);
}

int BinaryHeap::parentIndex(const int &index)
{
    return (index-1)/2;
}

int BinaryHeap::leftChildIndex(const int &index)
{
    int indexChild = index*2+1;
    if(indexChild >= values.size()){return -1;}
    return indexChild;
}

int BinaryHeap::graterChildIndex(const int &leftIndex,const int &rightIndex)
{
    if(leftIndex == -1 && rightIndex == -1){return -1;}
    else if(leftIndex == -1){return rightIndex;}
    else if(rightIndex == -1){return leftIndex;}
    else if(values[rightIndex] > values[leftIndex]){return rightIndex;}
    else{return leftIndex;}
}

int BinaryHeap::rightChildIndex(const int &index)
{
    int indexChild = index*2+2;
    if(indexChild >= values.size()){return -1;}
    return indexChild;
}
