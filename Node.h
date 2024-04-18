#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	Node();

	Node(T data);

	T getData();

	Node<T>* getNext();

	void setData(T data);

	void setNext(Node<T>* next);
private:
	T data;
	Node<T>* next;
};