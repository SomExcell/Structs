#ifndef BINARYHEAP_HPP_
#define BINARYHEAP_HPP_

#include <iostream>
#include <vector>

template <typename T>
struct BinaryHeap
{
public:
    BinaryHeap(){}
    BinaryHeap(const BinaryHeap& rhs);
    BinaryHeap(BinaryHeap&& rhs);
    BinaryHeap& operator=(const BinaryHeap& rhs);
    BinaryHeap& operator=(BinaryHeap&& rhs);
public:
	void push(const T &value);
	void pop();
	T top();
	void reverse();

private:
	void trickleUp(const int &currentIndex);
	void trickleDown(const int &currentIndex);

	void trickleUpReversed(const int &currentIndex);
	void trickleDownReversed(const int &currentIndex);

	int parentIndex(const int &index);
	int leftChildIndex(const int &index);
    int rightChildIndex(const int &index);

	int graterChild(const int &leftIndex,const int &rightIndex);
	int leastChild(const int &leftIndex, const int &rightIndex);

private:
	std::vector<T> values;
	bool reversed = false;
};

template<typename T>
BinaryHeap<T>::BinaryHeap(const BinaryHeap& rhs):values(rhs.values){}

template<typename T>
BinaryHeap<T>::BinaryHeap(BinaryHeap&& rhs)
{
    values = std::move(rhs.values);
}

template<typename T>
BinaryHeap<T>& BinaryHeap<T>::operator=(const BinaryHeap& rhs)
{
    if(this == &rhs){return *this;}
    values = rhs.values;
    return *this;
}

template<typename T>
BinaryHeap<T>& BinaryHeap<T>::operator=(BinaryHeap&& rhs)
{
    if(this == &rhs){return *this;}
    values = std::move(rhs.values);
    return *this;
}

template<typename T>
void BinaryHeap<T>::push(const T &value)
{
    values.push_back(value);
    if(reversed){trickleUpReversed(values.size()-1);}
    else{trickleUp(values.size()-1);}
}

template<typename T>
void BinaryHeap<T>::pop()
{
    std::swap(values[0],values[values.size()-1]);
    values.pop_back();
    if(reversed){trickleDownReversed(0);}
    else{trickleDown(0);}
}

template<typename T>
T BinaryHeap<T>::top()
{
    return values[0];
}

template<typename T>
void BinaryHeap<T>::reverse()
{
    reversed ? reversed = false : reversed = true;
    std::vector<T> vec(values);
    values.clear();
    for (size_t i = 0; i < vec.size(); i++)
    {
        push(vec[i]);
    }
}

template<typename T>
void BinaryHeap<T>::trickleUp(const int &currentIndex)
{
    int pIndex = parentIndex(currentIndex);
    if(pIndex == currentIndex || values[pIndex] >= values[currentIndex]){return;}
    std::swap(values[pIndex],values[currentIndex]);
    trickleUp(pIndex);
}

template<typename T>
void BinaryHeap<T>::trickleDown(const int &currentIndex)
{
    int greatChildIndex = graterChild(leftChildIndex(currentIndex),rightChildIndex(currentIndex));
    if(greatChildIndex == -1){return;}
    else if(values[greatChildIndex] < values[currentIndex]){return;}
    std::swap(values[greatChildIndex],values[currentIndex]);
    trickleDown(greatChildIndex);
}

template<typename T>
void BinaryHeap<T>::trickleUpReversed(const int &currentIndex)
{
    int pIndex = parentIndex(currentIndex);
    if(pIndex == currentIndex || values[pIndex] <= values[currentIndex]){return;}
    std::swap(values[pIndex],values[currentIndex]);
    trickleUpReversed(pIndex);
}

template<typename T>
void BinaryHeap<T>::trickleDownReversed(const int &currentIndex)
{
    int leastChildIndex = leastChild(leftChildIndex(currentIndex),rightChildIndex(currentIndex));
    if(leastChildIndex == -1){return;}
    else if(values[leastChildIndex] > values[currentIndex]){return;}
    std::swap(values[leastChildIndex],values[currentIndex]);
    trickleDownReversed(leastChildIndex);
}

template<typename T>
int BinaryHeap<T>::parentIndex(const int &index)
{
    return (index-1)/2;
}

template<typename T>
int BinaryHeap<T>::leftChildIndex(const int &index)
{
    int indexChild = index*2+1;
    if(indexChild >= values.size()){return -1;}
    return indexChild;
}

template<typename T>
int BinaryHeap<T>::rightChildIndex(const int &index)
{
    int indexChild = index*2+2;
    if(indexChild >= values.size()){return -1;}
    return indexChild;
}

template<typename T>
int BinaryHeap<T>::graterChild(const int &leftIndex,const int &rightIndex)
{
    if(leftIndex == -1 && rightIndex == -1){return -1;}
    else if(leftIndex == -1){return rightIndex;}
    else if(rightIndex == -1){return leftIndex;}
    else if(values[rightIndex] > values[leftIndex]){return rightIndex;}
    else{return leftIndex;}
}

template<typename T>
int BinaryHeap<T>::leastChild(const int &leftIndex, const int &rightIndex)
{
    if(leftIndex == -1 && rightIndex == -1){return -1;}
    else if(leftIndex == -1){return rightIndex;}
    else if(rightIndex == -1){return leftIndex;}
    else if(values[rightIndex] < values[leftIndex]){return rightIndex;}
    else{return leftIndex;}
}


#endif