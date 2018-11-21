#ifndef BSTNode_H
#define BSTNode_H

template <typename T>
class BSTNode
{
	friend class BST<T>;

public:
	BSTNode(T, T);
	T getName();
	T getBday(); //returns data stored in node

private:
	T bday, name;
	BSTNode* leftPtr; //pointer to left child node of node
	BSTNode* rightPtr; //pointer to right child node of node
};

template <typename T>
BSTNode<T>::BSTNode(T getName, T getBday)
{
	bday = bdayIn;
	name = nameIn;
	leftPtr = 0; //pointer to left and right child nodes are initilized to NULL
	rightPtr = 0;
}

template <typename T>
T BSTNode<T>::getName()
{
	return name;
}

template <typename T>
T BSTNode<T>::getBday()
{
	return bday;
}
#endif
