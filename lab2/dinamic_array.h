#pragma once

#ifndef DINAMIC_ARRAY_H
#define DINAMIC_ARRAY_H

template<typename Type>
class dinamic_array {
private:
	T* items;
	int size;
public:

	//getters
	Type GetFirst();
	Type GetLast();
	Type Get(int index);
	Sequence<Type>* GetSubsequence(int startIndex, int endIndex);
	int GetLength();
	//setters
	void Append(Type item);
	void Prepend(Type item);
	void InsertAt(Type item, int index);
	Sequence <Type>* Concat(Sequence <Type>* list);
	//destructor
	~Sequence() {}
};

#endif