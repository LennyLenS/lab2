#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<typename Type>
class LinkedList {
private:
	struct element {
		Type value;
		Type* next;
	}element;
	element* start;
	int lenght;

public:
	//constructs
	LinkedList(Type* items, int count);
	LinkedList();
	LinkedList(LinkedList <Type>& list const);
	//getters
	Type GetFirst();
	Type GetLast();
	Type Get(int index);
	LinkedList<Type>* GetSubList(int startIndex, int endIndex);
	int GetLength();
	//setters
	void Append(Type item);
	void Prepend(Type item);
	void InsertAt(Type item, int index);
	LinkedList<Type>* Concat(LinkedList<Type>* list);
	//destructor
	~LinkedList() {};
};


//constructs
template<typename Type>
LinkedList<Type>::LinkedList() {
	lenght = 0;
	start->value = NULL;
	start->next = nullptr;
}

template<typename Type>
LinkedList<Type>::LinkedList(Type* items, int count) {
	
}
#endif // !LINKED_LIST_H
