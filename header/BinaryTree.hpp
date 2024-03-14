#ifndef BINARYTREE_HPP_
#define BYNARYTREE_HPP_

template<typename T> class BinaryTree;

template <typename T>
class Node
{
private:
    Node(){};
    Node(T val);

    Node<T> *parent = nullptr;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;

    friend class BinaryTree<T>;
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree(){};
    BinaryTree(const BinaryTree& rhs);
    BinaryTree(BinaryTree&& rhs);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree& rhs);
    BinaryTree& operator=(BinaryTree&& rhs);
};

#endif