#pragma once

template <class T> class List;

template <class T>
class Node
{
private:
	Node(T value) { value_ = value; }
	T value() { return value_; }

	T value_;
	Node<T>* next = nullptr;
	Node<T>* previous = nullptr;

	friend class List<T>;
};

template <class T>
class List
{
public:
	List();

	List(const List& list);

	void push_back(const T& value);

	void push_front(const T& value);

	int size();

	void print();

	void pop_front();

	void pop_back();

	bool empty();

	T front();

	T back();

private:
	Node<T>* first;
	Node<T>* last;
	int size_;
};

template <class T>
List<T>::List()
{
	first = nullptr;
	last = nullptr;
	size_ = 0;
}

template <class T>
List<T>::List(const List& list)
{
	first = nullptr;
	last = nullptr;
	size_ = 0;
	Node<T>* node = l.first;
	while (node)
	{
		push_back(node->value());
		node = node->next;
	}
}

template <class T>
void List<T>::push_back(const T& value)
{
	Node<T>* node = new Node<T>(value);
	if (size_ == 0) { first = node; last = node; }
	else { last->next = node; node->previous = last; last = node; }
	++size_;
}

template <class T>
void List<T>::push_front(const T& value)
{
	Node<T>* node = new Node<T>(value);
	if (size_ == 0) { first = node; last = node; }
	else { first->previous = node; node->next = first; first = node; }
	++size_;
}

template <class T>
int List<T>::size()
{
	return size_;
}

template <class T>
void List<T>::print()
{
	Node<T>* node = first;
	while (node)
	{
		std::cout << node->value() << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

template <class T>
void List<T>::pop_front()
{
	if (size_ >= 2) { first = first->next; first->previous = nullptr; --size_; }
	else if (size_ == 1) { first = nullptr; last = nullptr; --size_; }
}

template <class T>
void List<T>::pop_back()
{
	if (size_ >= 2) { last = last->previous; last->next = nullptr; --size_; }
	else if (size_ == 1) { first = nullptr; last = nullptr; --size_; }
}

template <class T>
bool List<T>::empty()
{
	if (size_ == 0) { return true; }
	else { return false; }
}

template <class T>
T List<T>::front()
{
	return first->value();
}

template <class T>
T List<T>::back()
{
	return last->value();
}