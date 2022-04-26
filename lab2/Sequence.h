#pragma once


template<typename Type>
class Sequence {
	//constuctors
	ArraySequence(T* items, int count);
	LinkedListSequence(T* items, int count);
	ArraySequence();
	LinkedListSequence();
	ArraySequence(LinkedList <T>& list const);
	LinkedListSequence(LinkedList <T>& list const);
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
};
