// CS303_Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//my code breaks after a certain point i did not figure out why, but my code theoretically shoudl work
#include <iostream>
#include "LinkedList.h"

int main()
{
    data d;
    d.item = 2;
    LinkedList list(d);
    d.item = 8;
    list.pushFront(d);
    d.item = 9;
    list.pushBack(d);
    std::cout << list.popBack() << "\n";
    std::cout << list.popFront() << "\n";
    std::cout << list.popBack() << "\n";
    std::cout << list.popBack() << "\n";
    LinkedList list2(d);
    d.item = 76;
    list2.insert(12, d);
    std::cout << list2.find(d) << "\n";
    if (std::remove(0))
    {
        std::cout << "Object removed succesfully\n";
    }
    for (int i = 0; i < 10; i++)
    {
        list2.pushFront(d);
        d.item -= i;
    }
    std::cout << list2.find(d) << "<index found\n";
    d.item = 0;
    std::cout << list2.find(d) << "<numItems\n";
    list.empty();
    std::cout<<list2.find(d)<<"<numItems\n";//proves list is empty
}
