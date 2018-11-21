#define BST_H
#include <iostream>
using namespace std;
#include "BSTNode.h"
#include "LinkedList.h"

template <typename T>
class BST
{
public:
	BST();

private:
	BSTNode<T> *rootPtr;
};
