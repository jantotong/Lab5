#define BST_H
#include "LinkedList.h"

using namespace std;
template <class T>
struct BST : protected Linkedlist <T>
{
protected:
	string name;
	int birthday;
	BST *left, *right;

public:
	BST() {
		Linkedlist<T>::Linkedlist(); //create and empty linklist using constructor of base class
	}

	BST(const BST<T>& aBST)
	{
		Linkedlist::Linkedlist(aBST);
	}

};
