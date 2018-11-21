#pragma once
#ifndef Linkedlist_H
#define Linkedlist_H
using namespace std;

#include "Node.h"
#include "HeadNode.h"

template <class T>
class Linkedlist
{
protected:
	HeadNode<T> headNode;

	Node<T> *getNodeAt(int position) const
	{
		//Counting from the beginning of the chain
		Node<T> *currentPointer = headNode.getNext(); //derived class contains parent's function
		for (int i = 1; i < position; i++)
		{
			currentPointer = currentPointer->getNext();
		}
		return currentPointer;
	}

public:
	//Constructor
	Linkedlist()
	{
		headNode.setNext(nullptr);
		headNode.setLast(nullptr);
		headNode.setItemCount(0); //pre-setting everything to empty(null and zero)
	}

	//New list; using copy constructor
	Linkedlist(const Linkedlist<T>& aList)
	{
		//pointer to node in original chain
		Node<T>* Chainpointer = aList.headNode.getNext();

		//item count
		headNode.setItemCount(aList.headNode.getItemCount());

		//if chain already exist and is empty
		if (Chainpointer == nullptr)
		{
			//do nothing
		}

		else
		{
			//copy first node
			headNode.setNext(new Node<T>());
			this->setEntry(1, Chainpointer->getItem());

			//copy remaining nodes
			Node<T>* newChainPointer = headNode.getNext();	//last-node pointer

			for (int i = 1; i < headNode.getItemCount(); i++)
			{
				//pointing to next in chain
				Chainpointer = Chainpointer->getNext();

				//getting next item in chain
				T nextItem = Chainpointer->getItem();

				//creating new node for new item
				Node<T>* newNodePointer = new Node<T>(nextItem);

				//linking new node to end of new chain
				newChainPointer->setNext(newNodePointer);

				//
				newChainPointer = newChainPointer->getNext();
			}

			//last chain = null
			newChainPointer->setNext(nullptr);

			//last chain pointer
			headNode.setLast(newChainPointer);

		}
	}

	//Destructor
	~Linkedlist()
	{
		Empty();
	}

	//Checks if list is empty
	bool isEmpty() const
	{
		return (headNode.getItemCount() == 0);
	}

	//Gets the length of the list
	int getLength() const
	{
		return (headNode.getItemCount());
	}

	//Add anywhere
	void Add(int newPosition, const T& newEntry)
	{
		//Check if item exist in position
		bool PositionExist = (newPosition >= 1) && (newPosition <= (headNode.getItemCount()) + 1);

		if (PositionExist)
		{
			//New node (The one being inserted)
			Node<T>* newNodePointer = new Node<T>(newEntry);

			//If the position is at the front of the chain
			if (newPosition == 1)
			{
				newNodePointer->setNext(headNode.getNext());
				headNode.setNext(newNodePointer);
				headNode.setLast(getNodeAt(headNode.getItemCount()));
			}

			//Adding new node elsewhere in chain
			else
			{
				//Finding node that will be before new node
				Node<T>* previousPointer = getNodeAt(newPosition - 1);

				//Add the new node after previousPointer's node
				newNodePointer->setNext(previousPointer->getNext());
				previousPointer->setNext(newNodePointer);
			}

			//Total amount of entries+1; used for future methods
			headNode.setItemCount(headNode.getItemCount() + 1);

			//Setting tail pointer
			headNode.setLast(getNodeAt(headNode.getItemCount()));
		}
	}

	//Adding to first of chain
	void AddFirst(const T& newEntry)
	{
		return Add(1, newEntry);
	}

	//Adding to last of chain
	void AddLast(const T& newEntry)
	{
		return Add(headNode.getItemCount() + 1, newEntry);
	}

	//Delete anywhere
	void remove(int position)
	{
		//temp memoery Pointer for 
		Node<T>* currentPointer = nullptr;

		//Check if the node exist


		if (position >= 1 && position <= headNode.getItemCount())
		{
			//If the node is at the beginning of chain
			if (position == 1)
			{
				//pointer to node to be removed must be saved in some temporary pointer in order to remove memory allocated for removed node
				currentPointer = headNode.getNext();
				headNode.setNext(getNodeAt(2));
			}

			//Removing node elsewhere in chain
			else
			{
				//Finding node before the node that is going to removed
				Node<T>* previousPointer = getNodeAt(position - 1);

				//Pointing to node to delete
				currentPointer = previousPointer->getNext();

				//Removing node by connecting previous node with next node
				previousPointer->setNext(currentPointer->getNext());
			}

			//Removing memory allocated for removed node
			currentPointer->setNext(nullptr);
			delete currentPointer;
			currentPointer = nullptr;

			//Total entries -1; used for method count of items in the list
			headNode.setItemCount(headNode.getItemCount() - 1);

			//setting tail pointer
			headNode.setLast(getNodeAt(headNode.getItemCount()));
		}

	}

	//Removes first entry; used for pop
	void removeFirst()
	{
		return remove(1);
	}

	//Removes last entry
	void removeLast()
	{
		return remove(headNode.getItemCount());
	}

	//Empty the list
	void Empty()
	{
		while (!isEmpty()) //while loop keeps deleting the first node
		{
			remove(1);
		}
	}

	//Find anywhere
	T getEntry(int position)
	{
		//Check if chain exist
		bool PositionExist = (position >= 1) && (position <= headNode.getItemCount());

		if (PositionExist)
		{
			Node<T>* entryNodePointer = getNodeAt(position);
			return entryNodePointer->getItem();
		}
		else
		{
			string NoExist = "Position doesn't exist\n";
			throw NoExist;
		}
	}

	//Get last Entry
	T getLastEntry()
	{
		return getEntry(headNode.getItemCount());
	}
};
#endif