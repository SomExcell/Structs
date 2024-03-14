#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <iostream>
#include <vector>

struct BinaryHeap
{
public:
    BinaryHeap(){}
    BinaryHeap(const BinaryHeap& rhs);
    BinaryHeap(BinaryHeap&& rhs);
    BinaryHeap& operator=(const BinaryHeap& rhs);
    BinaryHeap& operator=(BinaryHeap&& rhs);
public:
	void push(const int &value);
	void pop();
	int max();

private:
	void trickleUp(const int &currentIndex);
	void trickleDown(const int &currentIndex);

	int parentIndex(const int &index);
	int leftChildIndex(const int &index);
    int rightChildIndex(const int &index);
	int graterChildIndex(const int &leftIndex,const int &rightIndex);

private:
	std::vector<int> values;
};

#endif