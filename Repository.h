#pragma once
#include "LinkedList.h"
#include <fstream>
template<class T>
class Repository
{
public:
	Repository(string tableName);
	~Repository();
	void add(T data);
	void insert(T data, int index);
	template<class C>
	LinkedList<T> find(bool predicate(T item, C comparer), C comparer);
	void sort(bool predicate(T first, T second));
	void loop(void delegate(T item, int index));
	template<class C>
	void remove(bool predicate(T item, C comparer), C comparer);
	void save();
	void load();
private:
	void writeToFile(ofstream& file);
	LinkedList<T> list;
	string filePath;
};
#include "Repository.cpp"