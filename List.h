#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
template<class T>
class List
{
public:
	List();

	List(T data);

	~List();

	Node<T>* getHead();

	void setHead(Node<T>* head);

	void create(T data);

	void insert(T data, int index);

	void loop(void delegate(T item, int index));

	template<class C>
	void remove(bool canDelete(T data, C comparer), C comparer);
private:
	Node<T>* head;
};