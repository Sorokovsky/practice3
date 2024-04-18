#include "List.h"
template<class T>
List<T>::List()
{
	this->setHead(NULL);
}

template<class T>
List<T>::List(T data)
{
	this->setHead(new Node<T>(data));
}

template<class T>
List<T>::~List()
{
	Node<T>* current = this->getHead();
	while (current != NULL)
	{
		Node<T>* temp = current->getNext();
		delete(current);
		current = temp;
	}
}

template<class T>
Node<T>* List<T>::getHead()
{
	return this->head;
}

template<class T>
void List<T>::setHead(Node<T>* head)
{
	this->head = head;
}

template<class T>
void List<T>::create(T data)
{
	Node<T>* temp = new Node<T>(data);
	Node<T>* current = this->getHead();
	if (current == NULL)
	{
		this->setHead(temp);
	}
	else
	{
		while (current->getNext() != NULL)
		{
			current = current->getNext();
		}
		current->setNext(temp);
	}
}

template<class T>
void List<T>::insert(T data, int index) //index = 0......length - 1
{
	Node<T>* temp = new Node<T>(data);
	Node<T>* current = this->getHead();
	if (index == 0 || current == NULL)
	{
		temp->setNext(current);
		this->setHead(temp);
	}
	else
	{
		for (int i = 1; (i < index) && (current->getNext() != NULL); i++, current = current->getNext());
		temp->setNext(current->getNext());
		current->setNext(temp);
	}
}

template<class T>
void List<T>::loop(void delegate(T item, int index))
{
	Node<T>* current = this->getHead();
	for (int i = 0; current != NULL; i++, current = current->getNext())
	{
		delegate(current->getData(), i);
	}
}

template<class T>
template<class C>
void List<T>::remove(bool canDelete(T data, C comparer), C comparer)
{
	Node<T>* current = this->getHead();
	if (current == NULL)
	{
		return;
	}

}