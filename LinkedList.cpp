#pragma once
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(T data)
{
    this->size++;
    this->setHead(new Node<T>(data));
}

template<class T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}


template<class T>
void LinkedList<T>::setHead(Node<T>* head)
{
    this->head = head;
}

template<class T>
Node<T>* LinkedList<T>::getHead()
{
    return this->head;
}

template<class T>
void LinkedList<T>::create(T data)
{
    Node<T>* temp = new Node<T>(data);
    Node<T>* current = this->getHead();
    if (current == NULL)
    {
        this->setHead(temp);
        this->size++;
        return;
    }
    while (current->getNext() != NULL)
    {
        current = current->getNext();
    }
    this->size++;
    current->setNext(temp);
}

template<class T>
int LinkedList<T>::getSize()
{
    return this->size;
}

template<class T>
void LinkedList<T>::loop(void delegate(T item, int index))
{
    Node<T>* current = this->getHead();
    int i = 0;
    while (current != NULL)
    {
        delegate(current->getData(), i);
        current = current->getNext();
        i++;
    }
}

template<class T>
template<class C>
LinkedList<T> LinkedList<T>::find(bool isNeed(T item, C comparer), C comparer)
{
    LinkedList<T> result = LinkedList<T>();
    Node<T>* current = this->getHead();
    while (current != NULL)
    {
        if (isNeed(current->getData(), comparer))
        {
            result.create(current->getData());
        }
        current = current->getNext();
    }
    return result;
}

template<class T>
void LinkedList<T>::sort(bool canSwap(T first, T second))
{
    bool isUnsorted = false;
    do
    {
        isUnsorted = false;
        Node<T>* current = this->getHead();
        if (current == NULL)
        {
            return;
        }
        while ((current != NULL) && (current->getNext() != NULL))
        {

            if (canSwap(current->getData(), current->getNext()->getData()))
            {
                isUnsorted = true;
                this->swap(current, current->getNext());
            }
            current = current->getNext();
        }

    } while (isUnsorted == true);
}

template<class T>
void LinkedList<T>::insert(T data, int index)
{
    Node<T>* temp = new Node<T>(data);
    Node<T>* current = this->getHead();
    if (current == NULL || index == 0)
    {
        temp->setNext(current);
        this->setHead(temp);
        this->size++;
        return;
    }
    for (int i = 1; (i < index) && (current->getNext() != NULL); i++, current = current->getNext());
    temp->setNext(current->getNext());
    current->setNext(temp);
    this->size++;

}

template<class T>
void LinkedList<T>::clear()
{
    Node<T>* current = head;
    while (current != NULL)
    {
        Node<T>* temp = current->getNext();
        delete current;
        current = temp;
    }
    this->setHead(NULL);
    this->size = 0;
}

template<class T>
T LinkedList<T>::operator[](int index)
{
    Node<T>* current = this->getHead();
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    T item = current->getData();
    return item;
}

template<class T>
void LinkedList<T>::swap(Node<T>* first, Node<T>* second)
{
    Node<T>* beforeFirst = NULL;
    Node<T>* beforeSecond = NULL;
    Node<T>* afterFirst = first->getNext();
    Node<T>* afterSecond = second->getNext();
    Node<T>* current = this->getHead();
    while (current != NULL)
    {
        if (current->getNext() == first)
        {
            beforeFirst = current;
        }
        if (current->getNext() == second)
        {
            beforeSecond = current;
        }
        current = current->getNext();
    }
    if (first->getNext() == second)
    {
        second->setNext(first);
        first->setNext(afterSecond);
        if (beforeFirst == NULL)
        {
            this->setHead(second);
        }
        else
        {
            beforeFirst->setNext(second);
        }
        return;
    }

    first->setNext(afterSecond);
    if (beforeFirst == NULL)
    {
        this->setHead(second);
    }
    else
    {
        beforeFirst->setNext(second);
    }
    if (first->getNext() == second)
    {
        second->setNext(first);
    }
    else
    {
        second->setNext(afterFirst);
    }
    beforeSecond->setNext(first);
}

template<class T>
template<class C>
void LinkedList<T>::remove(bool isNeed(T item, C comparer), C comparer)
{
    Node<T>* current = this->getHead();
    if ((current == NULL))
    {
        return;
    }
    if (isNeed(current->getData(), comparer))
    {
        this->setHead(current->getNext());
        delete(current);
        this->size--;
        return;
    }
    while ((current != NULL) && (current->getNext() != NULL))
    {
        if (isNeed(current->getNext()->getData(), comparer))
        {
            Node<T>* temp = current->getNext()->getNext();
            delete(current->getNext());
            current->setNext(temp);
            this->size--;
        }
        current = current->getNext();
    }
}

template<class T>
template<class C>
void LinkedList<T>::edit(bool isNeed(T item, C comparer), C comparer, T updated)
{
    Node<T>* current = this->getHead();
    if (current == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        if (isNeed(current->getData(), comparer))
        {
            current->setData(updated);
        }
        current = current->getNext();
    }
}

template<class T>
template<class C>
C LinkedList<T>::redce(C delegate(T item, C result), C startValue)
{
    Node<T>* current = this->getHead();
    C result = startValue;
    while (current != NULL)
    {
        result = delegate(current->getData(), result);
        current = current->getNext();
    }
    return result;
}
