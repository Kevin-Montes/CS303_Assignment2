#include "LinkedList.h"

LinkedList::LinkedList()
{
	headPtr = nullptr;
	tailPtr = nullptr;
	numItems = 0;

}
LinkedList::LinkedList(data d)
{
	Node* tempPtr = new Node;
	tempPtr->d = d;//putting the data recieved in the argument into thw first index of the linkde list.
	tempPtr->nextPtr = nullptr;
	
	headPtr = tempPtr;
	tailPtr = tempPtr;
	numItems++;

}
LinkedList::~LinkedList()
{
	while (headPtr != nullptr) {
		Node* delNode = headPtr;
		headPtr = headPtr->nextPtr;
		delete delNode;
	}
	delete headPtr;
	headPtr = nullptr;
	tailPtr = nullptr;
	numItems = 0;
}
void LinkedList::pushFront(data d)
{
	Node* tempPtr = new Node;
	tempPtr->d = d;//putting the data recieved in the argument into thw first index of the linkde list.
	if (headPtr == nullptr)//vhrvking if list is empty
	{
		
		tempPtr->nextPtr = nullptr;

		headPtr = tempPtr;
		tailPtr = tempPtr;
		numItems++;

	}
	else
	{
		tempPtr->nextPtr = headPtr;
		headPtr = tempPtr;
		numItems++;
	}
}
void LinkedList::pushBack(data d)
{
	Node* tempPtr = new Node;
	tempPtr->d = d;//putting the data recieved in the argument into thw first index of the linkde list.
	if (headPtr == nullptr)//vhrvking if list is empty
	{

		tempPtr->nextPtr = nullptr;

		headPtr = tempPtr;
		tailPtr = tempPtr;
		numItems++;

	}
	else
	{
		tailPtr->nextPtr = tempPtr;
		tailPtr = tempPtr;
		tailPtr->nextPtr = nullptr;
		numItems++;
	}
}
int LinkedList::popFront()
{
	if (headPtr == nullptr)
	{
		std::cout << "The list is empty\n";
		return 0;
	}
	else
	{
		int tempInt = headPtr->d.item;
		Node* delNode = headPtr;
		headPtr = headPtr->nextPtr;
		delete delNode;
		delNode = nullptr;
		return tempInt;
		numItems--;
	}
}
int LinkedList::popBack()
{
	if (headPtr == nullptr)
	{
		std::cout << "The list is empty\n";
		return 0;
	}
	else if (headPtr == tailPtr)
	{
		int tempInt = headPtr->d.item;
		delete headPtr;
		headPtr = nullptr;
		tailPtr = nullptr;
		numItems--;
		return tempInt;



	}
	else
	{
		Node* tempPtr = headPtr;
		while (tempPtr->nextPtr->nextPtr != nullptr)
		{
			tempPtr = tempPtr->nextPtr;
		}

		int tempInt = tempPtr->nextPtr->d.item;
		Node* delNode = tempPtr->nextPtr;
		tailPtr = tempPtr;
		tailPtr->nextPtr = nullptr;
		delete delNode;
		delNode = nullptr;
		numItems--;
		return tempInt;
	}
}
void LinkedList::empty()
{
	while (headPtr != nullptr) {
		Node* delNode = headPtr;
		headPtr = headPtr->nextPtr;
		delete delNode;
	}
	delete headPtr;
	headPtr = nullptr;
	tailPtr = nullptr;
	numItems = 0;
}
void LinkedList::insert(int index, data d)
{
	if (numItems <= index)
	{
		Node* tempPtr = new Node;
		tempPtr->d = d;//putting the data recieved in the argument into thw first index of the linkde list.
		if (headPtr == nullptr)//vhrvking if list is empty
		{

			tempPtr->nextPtr = nullptr;

			headPtr = tempPtr;
			tailPtr = tempPtr;
			numItems++;

		}
		else
		{
			tailPtr->nextPtr = tempPtr;
			tailPtr = tempPtr;
			tailPtr->nextPtr = nullptr;
			numItems++;
		}
	}
	else if (index <= 0)
	{
		Node* tempPtr = new Node;
		tempPtr->d = d;//putting the data recieved in the argument into thw first index of the linkde list.
		if (headPtr == nullptr)//vhrvking if list is empty
		{

			tempPtr->nextPtr = nullptr;

			headPtr = tempPtr;
			tailPtr = tempPtr;
			numItems++;

		}
		else
		{
			tempPtr->nextPtr = headPtr;
			headPtr = tempPtr;
			numItems++;
		}
	}
	else
	{
		index--;//we need to go one before to insert it correctly
		Node* tempPtr = headPtr;
		for (index; index > 0; index--)
		{
			tempPtr = tempPtr->nextPtr;
		}
		Node* insertPtr = new Node;
		insertPtr->d = d;
		insertPtr->nextPtr = tempPtr->nextPtr;
		tempPtr->nextPtr = insertPtr;
	}
	numItems++;
}
bool LinkedList::remove(int index)
{
	if (numItems <= index)
	{
		std::cout << "index is over the range of List\n";
		return false;
	}
	else if (numItems != 0 and index <= 0)
	{
		if (headPtr == nullptr)
		{
			std::cout << "The list is empty\n";
			return 0;
		}
		else
		{
			int tempInt = headPtr->d.item;
			Node* delNode = headPtr;
			headPtr = headPtr->nextPtr;
			delete delNode;
			delNode = nullptr;
			return tempInt;
			numItems--;
		}
	}
	else
	{
		index--;//we need to go one before to insert it correctly
		Node* tempPtr = headPtr;
		for (index; index > 0; index--)
		{
			tempPtr = tempPtr->nextPtr;
		}
		Node* removePtr = new Node;
		
		removePtr->nextPtr = tempPtr->nextPtr;
		tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
		delete removePtr;
	}
	numItems--;
	return true;
	
}
int LinkedList::find(data d)
{
	int index = 0;
	Node* tempPtr = headPtr;
	while (index < numItems)
	{
		if (d.item == tempPtr->d.item)
		{
			return index;
		}
		tempPtr = tempPtr->nextPtr;
	}
	std::cout << "object not in list\n";
	return numItems;
}
