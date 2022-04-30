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
	LinkedList(LinkedList <Type>& list);
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
	this->lenght = 0;
	this->start->value = NULL;
	this->start->next = nullptr;
}

template<typename Type>
LinkedList<Type>::LinkedList(Type* items, int count) {
	this->lenght = 1;
	memcpy(this->start->value, items, sizeof(Type));
	for (int i = 1; i < count; ++i) {
		this->Append(items[i]);
	}
}

template<typename Type>
LinkedList<Type>::LinkedList(LinkedList <Type>& list) {
	this->lenght = 1;
	memcpy(this->start->value, list->start->value, sizeof(Type));
	element* current = list->start->next;
	for (int i = 1; i < list->; ++i) {
		this->Append(current->value);
		current = current->next;
	}
}

//getters
template<typename Type>
Type LinkedList<Type>::GetFirst() {
	return this->start->value;
}

template<typename Type>
Type LinkedList<Type>::GetLast() {
	element* current = this->start;
	for (int i = 0; i < this->lenght - 1; ++i) {
		current = current->next;
	}
	return current->value;
}

template<typename Type>
Type LinkedList<Type>::Get(int index) {
	if (index < 0 || index > = this->lenght) {
		throw std::out_of_range("Out of range");
	}
	element* current = this->start;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->value;
}

template<typename Type>
int LinkedList<Type>::GetLength() {
	return this->lenght;
}
#endif // !LINKED_LIST_H
