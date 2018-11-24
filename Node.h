#ifndef NODE_H
#define NODE_H
#include "Queue.h"
using namespace std;

template <class T>
class Node
{
protected:
	T item;			//data item
	Node<T> *next;	//pointer to next node (headNnode if used as headnode object)

public:
	//Constructors
	Node()
	{
		next = nullptr;
	}

	Node(T &localItem) //last node
	{
		item = localItem;
		next = nullptr;
	}

	Node(const T &localItem, Node<T> *nextNodePointer)
	{
		item = localItem;
		next = nextNodePointer;
	}
	//setter
	void setItem(T &localItem)
	{
		item = localItem;
	}

	void setNext(Node<T> *nextNodePointer)
	{
		next = nextNodePointer;
	}

	//getter
	T getItem() const
	{
		return item;
	}

	Node<T> *getNext() const
	{

		return next;
	}

};

template <class T>
class BSTNode : public Node<T> {

public:
	T temp;
	BSTNode* right;
	BSTNode* left;

	BSTNode* insert(T &dataValue, BSTNode* location) {
		if (location == NULL) {
			location = new BSTNode;
			location->temp = dataValue;
			location->left = NULL;
			location->right = NULL;
		}
		else if (dataValue > location->temp) {
			location->right = insert(dataValue, location->right);
		}
		else if (dataValue < location->temp) {
			location->left = insert(dataValue, location->left);
		}
		else {//equal value 
		}
		return location;
	}

	BSTNode* findMin(BSTNode* location)
	{
		if (location == NULL)
			return NULL;
		else if (location->left == NULL)
			return location;
		else
			return findMin(location->left);
	}
	
	BSTNode* empty(BSTNode* location) {
		if (location == NULL) {
			return NULL;
		}
		empty(location->left);
		empty(location->right);
	}

	BSTNode* remove(T &value, BSTNode* location) {
		BSTNode* data;
		if (location == NULL)
			return NULL;
		else if (value < location->temp)
			location->left = remove(value, location->left);
		else if (value > location->temp)
			location->right = remove(value, location->right);
		else if (location->left && location->right)
		{
			data = findMin(location->right);
			location->temp = data->temp;
			location->right = remove(location->temp, location->right);
		}
		else
		{
			data = location;
			if (location->left == NULL)
				location = location->right;
			else if (location->right == NULL)
				location = location->left;
			delete data;
		}

		return location;
	}

	void inorder(BSTNode* location)
	{
		if (location == NULL)
			return;
		inorder(location->left);
		cout << location->temp << " ";
		inorder(location->right);
	}

	void preorder(BSTNode* node)
	{
		if (node == NULL)
			return;

		/* first print data of node */
		cout << node->temp << " ";

		/* then recur on left sutree */
		preorder(node->left);

		/* now recur on right subtree */
		preorder(node->right);
	}

	void postorder(BSTNode* node)
	{
		if (node == NULL)
			return;

		// first recur on left subtree 
		postorder(node->left);

		// then recur on right subtree 
		postorder(node->right);
		// now deal with the node 
		cout << node->temp << " ";
	}

	/*
	void bFirst(BSTNode* root)
	{
		// Base Case 
		if (root == NULL)  return;

		// Create an empty queue for level order tarversal 
		Queue<BSTNode*> q;

		// Enqueue Root and initialize height 
		q.push(root);

		while (q.empty() == false)
		{
			// Print front of queue and remove it from queue 
			BSTNode *node = q.front();
			cout << node->temp << " ";
			q.pop();

			if (node->left != NULL)
				q.push(node->left);

			if (node->right != NULL)
				q.push(node->right);
		}
	}
	*/



};

#endif
