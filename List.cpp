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
	this->clear();
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
void List<T>::swap(Node<T>* first, Node<T>* second)
{
	Node<T>* beforeFirst = this->getHead();
	Node<T>* beforeSecond = this->getHead();
	Node<T>* nextFirst = first->getNext();
	Node<T>* nextSecond = second->getNext();
	if (beforeFirst == NULL || beforeSecond == NULL)
	{
		return;
	}

	while (beforeFirst->getNext() != first)
	{
		beforeFirst = beforeFirst->getNext();
	}
	while (beforeSecond->getNext() != second)
	{
		beforeSecond = beforeSecond->getNext();
	}
	if (nextFirst == second)
	{
		nextFirst = first;
	}
	first->setNext(nextSecond);
	second->setNext(nextFirst);
	if (first == this->getHead())
	{
		this->setHead(second);
	}
	else
	{
		beforeFirst->setNext(second);
	}
	if (second == this->getHead())
	{
		this->setHead(first);
	}
	else
	{
		beforeSecond->setNext(first);
	}
}

template<class T>
void List<T>::clear()
{
	Node<T>* current = this->getHead();
	while (current != NULL)
	{
		Node<T>* temp = current->getNext();
		delete(current);
		current = temp;
	}
	this->setHead(NULL);
}

template<class T>
template<class C>
void List<T>::remove(bool canDelete(T data, C comparer), C comparer)
{
	Node<T>* current = this->getHead();
	while (current != NULL)
	{
		if (canDelete(current->getData(), comparer))
		{
			Node<T>* temp = this->getHead();
			if (temp == current)
			{
				this->setHead(temp->getNext());
				delete(temp);
				current = this->getHead();
				continue;
			}
			while (temp->getNext() != current)
			{
				temp = temp->getNext();
			}
			Node<T>* next = temp->getNext()->getNext();
			delete(temp->getNext());
			temp->setNext(next);
			current = next;
			continue;
		}
		current = current->getNext();
	}
}

template<class T>
void List<T>::sort(bool canSwap(T first, T second))
{
	Node<T>* current = this->getHead();
	bool isUnsorted = false;
	if (current == NULL)
	{
		return;
	}
	do
	{
		isUnsorted = false;
		while (current->getNext() != NULL)
		{
			if (canSwap(current->getData(), current->getNext()->getData()))
			{
				isUnsorted = true;
				this->swap(current, current->getNext());
			}
		}
	} while (isUnsorted == false);
}

template<class T>
template<class C>
List<T> List<T>::find(bool isNeed(T item, C comparer), C comparer)
{
	List<T> founded = List<T>();
	Node<T>* current = this->getHead();
	while (current != NULL)
	{
		if (isNeed(current->getData(), comparer))
		{
			founded.create(current->getData());
		}
		current = current->getNext();
	}
	return founded;
}
