#define BST_H
#ifndef NODE_H

#include <iostream>
using namespace std;
#include "Node.h"

template <typename T>
class BST
{
private:

public:

	BSTNode<T>* root;

	BST() {
		root = NULL;
	}

	~BST() {
		root = root->empty(root);
	}

	void insert(T x) {
		root = root->insert(x, root);
	}

	void remove(T x) {
		root = remove(x, root);
	}

	void display() {
		inorder(root);
		cout << endl;
	}

	BSTNode<T>* printPreorder() {
		root->preorder(root);
		cout << endl;
		return root;
	}

	BSTNode<T>* printPostorder() {
		root->postorder(root);
		cout << endl;
		return root;
	}

	BSTNode<T>* printInorder() {
		root->inorder(root);
		cout << endl;
		return root;
	}

};
#endif
