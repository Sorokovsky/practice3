#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
template<class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T data);
	~LinkedList();
	void setHead(Node<T>* head);
	Node<T>* getHead();
	void create(T data);
	int getSize();
	void loop(void delegate(T item, int index));
	template<class C>
	LinkedList<T> find(bool isNeed(T item, C comparer), C comparer);
	void sort(bool canSwap(T first, T second));
	template<class C >
	void remove(bool isNeed(T item, C comparer), C comparer);
	template<class C>
	void edit(bool isNeed(T item, C comparer), C comparer, T updated);
	void insert(T data, int index);
	void clear();
	template<class C>
	C redce(C delegate(T item, C result), C startValue);
	T operator[](int index);
private:
	int size = 0;
	void swap(Node<T>* first, Node<T>* second);
	Node<T>* head;
};
#include "LinkedList.cpp"