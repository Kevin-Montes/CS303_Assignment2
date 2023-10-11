#pragma once
#include <string>
#include <iostream>

struct data {
	int item;
};

struct Node {
	data d;
	Node* nextPtr;
};


class LinkedList
{
private:
	Node* headPtr=nullptr;
	Node* tailPtr=nullptr;
	int numItems=0;
public:
	LinkedList();
	LinkedList(data d);
	~LinkedList();
	void pushFront(data d);
	void pushBack(data d);
	int popFront();
	int popBack();
	void empty();
	void insert(int index,data d);

	bool remove(int index);
	int find(data d);
	
	
};

