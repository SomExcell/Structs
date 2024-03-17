#ifndef BINARYSEARCHTREE_HPP_
#define BYNARYSEARCHTREE_HPP_
#include <iostream>

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree(){}

public:
    void insert(const T &value);
    void erase(const T &value);
    bool count(const T &value);
    size_t size();

private:
    BinarySearchTree* erase(const T& value,BinarySearchTree<T> *tree);
    BinarySearchTree* getMax(BinarySearchTree<T> *tree);
    BinarySearchTree* getMin(BinarySearchTree<T> *tree);

private:
    T value;
    BinarySearchTree<T> *left = nullptr;
    BinarySearchTree<T> *right = nullptr;
    BinarySearchTree<T> *top = nullptr;
    BinarySearchTree<T> *node = nullptr;
    size_t _size = 0;
};

template<typename T>
void BinarySearchTree<T>::insert(const T &value)
{
    if(_size == 0)
    {
        this->value = value;
        ++_size; 
        return;
    }

    node = this;
    while(true)
    {
        if(value == node->value){return;}
        else if(value < node->value)
        {
            if(node->left == nullptr)
            {
                node->left = new BinarySearchTree<T>{};
                node->left->value = value;
                node->left->top = node;
                ++_size;
                return;
            }else
            {
                node = node->left;
            }
        }else if(value > node->value)
        {
            if(node->right == nullptr)
            {
                node->right = new BinarySearchTree<T>{};
                node->right->value = value;
                node->right->top = node;
                ++_size;
                return;
            }else
            {
                node = node->right;
            }
        }
    }
}

template<typename T>
void BinarySearchTree<T>::erase(const T &value)
{
    erase(value,this);
    return;
}

template<typename T>
BinarySearchTree<T>* BinarySearchTree<T>::erase(const T &value, BinarySearchTree<T> *tree)
{
    if(node == nullptr)return nullptr;
    else if(value < tree->value){tree->left = erase(value,tree->left);}
    else if(value > tree->value){tree->right = erase(value,tree->right);}
    else
    {
        if(tree->left == nullptr || node->right == nullptr)
        {
            tree->left == nullptr ? tree = tree->right : tree = tree->right;
        }
        else
        {

        }
    }
    return tree;
}

template<typename T>
bool BinarySearchTree<T>::count(const T &value)
{
    node = this;
    while(node)
    {
        if(node->value == value){return true;}
        else if(node->value > value){node = node->left;}
        else if(node->value < value){node = node->right;}
    }
    return false;
}

template<typename T>
size_t BinarySearchTree<T>::size()
{
    return _size;
}

#endif