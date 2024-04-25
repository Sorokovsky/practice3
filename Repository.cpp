#pragma once
#include "Repository.h"
template<class T>
Repository<T>::Repository(string tableName)
{
	this->filePath = string(".\\database\\" + tableName + ".dat");
}

template<class T>
void Repository<T>::add(T data)
{
	list.create(data);
}

template<class T>
void Repository<T>::insert(T data, int index)
{
	list.insert(data, index);
}

template<class T>
void Repository<T>::sort(bool predicate(T first, T second))
{
	list.sort(predicate);
}

template<class T>
void Repository<T>::loop(void delegate(T item, int index))
{
	list.loop(delegate);
}

template<class T>
void Repository<T>::save()
{
	ofstream file(this->filePath, ios::trunc | ios::binary | ios::app);
	if (file.is_open())
	{
		Node<T>* current = list.getHead();
		while (current != NULL)
		{
			T item = current->getData();
			file.write((char*)&item, sizeof(item));
			current = current->getNext();
		}
	}
	file.close();
}

template<class T>
void Repository<T>::load()
{
	ifstream file(this->filePath, ios::in | ios::binary);
	if (file.is_open())
	{
		list = LinkedList<T>();
		T item;
		while (!file.eof())
		{
			file.read((char*)&item, sizeof(T));
		}
	}
	file.close();
}

template<class T>
template<class C>
LinkedList<T> Repository<T>::find(bool predicate(T item, C comparer), C comparer)
{
	LinkedList<T> founded = list.find(predicate, comparer);
	return founded;
}

template<class T>
template<class C>
void Repository<T>::remove(bool predicate(T item, C comparer), C comparer)
{
	list.remove(predicate, comparer);
}
