#pragma once
#ifndef NODE_H
#define NODE_H

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

	Node(const T &localItem) //last node
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
	void setItem(const T &localItem)
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

#endif