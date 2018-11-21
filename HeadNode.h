#pragma once
#ifndef HEAD_NODE_H
#define HEAD_NODE_H
#include "Node.h"

using namespace std;

template <class T> //template so it can accecpt any kind of data
class HeadNode : public Node <T>
{
protected:
	int ItemCount;	//item count (doesnt work if type string)

	Node<T> *last;	//pointer to last node

public:
	HeadNode() //Constructors
	{
		ItemCount = 0; //preset to 0
		last = nullptr; //last doesnt have any to refer to
	}

	HeadNode(const int &localItemCount)
	{
		ItemCount = localItemCount;
	}

	HeadNode(const int &localItemCount, Node<T> *headPointer)
	{
		ItemCount = localItemCount;
		next = headPointer;
	}

	HeadNode(const int &localItemCount, Node<T> *headPointer, Node<T> *tailPointer)
	{
		ItemCount = localItemCount;
		next = headPointer;
		last = tailPointer;
	}

	//setters
	void setItemCount(const int &localItemCount)
	{
		ItemCount = localItemCount;
	}

	void setLast(Node<T> *tailPointer)
	{
		last = tailPointer;
	}

	//getters
	int getItemCount() const
	{
		return ItemCount;
	}

	Node<T> *getLast() const
	{
		return last;
	}
};

#endif