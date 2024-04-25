#pragma once
#include "Repository.h"
template<class T>
Repository<T>::Repository(string tableName)
{
	this->filePath = string(".\\database\\" + tableName + ".dat");
	this->load();
}

template<class T>
Repository<T>::~Repository()
{
	this->save();
}

template<class T>
void Repository<T>::add(T data)
{
	this->list.create(data);
	this->save();
}

template<class T>
void Repository<T>::insert(T data, int index)
{
	this->list.insert(data, index);
	this->save();
}

template<class T>
void Repository<T>::sort(bool predicate(T first, T second))
{
	this->list.sort(predicate);
	this->save();
}

template<class T>
void Repository<T>::loop(void delegate(T item, int index))
{
	this->list.loop(delegate);
	this->save();
}

template<class T>
void Repository<T>::save()
{
	ofstream file(this->filePath, ios::trunc | ios::binary | ios::app);
	if (file.is_open())
	{
		this->writeToFile(file);
	}
	else
	{
		file = ofstream(this->filePath, ios::binary);
		this->writeToFile(file);
	}
	file.close();
}

template<class T>
void Repository<T>::load() {
	ifstream file(this->filePath, ios::in | ios::binary);
	if (file.is_open()) {
		this->list.clear();
		T* item = new T();
		while (file.read((char*)(item), sizeof(T))) 
		{
			this->list.create(*item);
		}
		file.close();
	}
}


template<class T>
void Repository<T>::writeToFile(ofstream& file)
{
	Node<T>* current = this->list.getHead();
	while (current != NULL)
	{
		T item = current->getData();
		file.write((char*)(&item), sizeof(T));
		current = current->getNext();
	}
}

template<class T>
template<class C>
LinkedList<T> Repository<T>::find(bool predicate(T item, C comparer), C comparer)
{
	LinkedList<T> founded = this->list.find(predicate, comparer);
	this->save();
	return founded;
}

template<class T>
template<class C>
void Repository<T>::remove(bool predicate(T item, C comparer), C comparer)
{
	this->list.remove(predicate, comparer);
	this->save();
}
