#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H
#include "linked_list.h"
#include "Sequence.h"

template<typename Type>
class ListSequence : public Sequence<Type> {
private:
	LinkedList<Type>* arr;
public:
	//constructs
	ListSequence();
	ListSequence(Type* items, int count);
	ListSequence(LinkedList <Type>* list);

	//getters
	Type GetFirst() const override;
	Type GetLast() const override;
	Type Get(int index) const override;
	int GetLength() const override;
	Sequence<Type>* GetSubsequence(int startIndex, int endIndex) const override;

	//setters
	void Append(Type item) override;
	void Prepend(Type item) override;
	void InsertAt(Type item, int index) override;
	Sequence<Type>* Concat(Sequence<Type>* list) override;

	//destructs
	~ListSequence() {}
};

//constructs
template<typename Type>
ListSequence<Type>::ListSequence() {
	this->arr = new LinkedList<Type>();
}

template<typename Type>
ListSequence<Type>::ListSequence(Type* items, int count) {
	this->arr = new LinkedList<Type>(items, count);
}

template<typename Type>
ListSequence<Type>::ListSequence(LinkedList<Type>* list) {
	this->arr = new LinkedList<Type>(list);
}

//getters
template<typename Type>
Type ListSequence<Type>::GetFirst() const {
	return	this->arr->GetFirst();
}

template<typename Type>
Type ListSequence<Type>::GetLast() const {
	return	this->arr->GetLast();
}

template<typename Type>
Type ListSequence<Type>::Get(int index) const {
	return	this->arr->Get(index);
}

template<typename Type>
int ListSequence<Type>::GetLength() const {
	return	this->arr->GetLength();
}

template<typename Type>
Sequence<Type>* ListSequence<Type>::GetSubsequence(int startIndex, int endIndex) const {
	LinkedList<Type>* cur = this->arr->GetSubList(startIndex, endIndex);
	ListSequence<Type>* newList = new ListSequence<Type>(cur);
	return newList;
}

//setters
template<typename Type>
void ListSequence<Type>::Append(Type item) {
	this->arr->Append(item);
}

template<typename Type>
void ListSequence<Type>::Prepend(Type item) {
	this->arr->Prepend(item);
}

template<typename Type>
void ListSequence<Type>::InsertAt(Type item, int index) {
	this->arr->InsertAt(item, index);
}

template<typename Type>
Sequence<Type>* ListSequence<Type>::Concat(Sequence<Type>* list) {
	for (int i = 0; i < list->GetLength(); ++i) {
		this->arr->Append(list->Get(i));
	}
	return this;
}
#endif