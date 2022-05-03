#pragma once
#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "dynamic_array.h"
#include "Sequence.h"

template<typename Type>
class ArraySequence : public Sequence<Type> {
private:
	DynanicArray<Type>* arr;
public:
	//constructs
	ArraySequence();
	ArraySequence(Type* items, int count);
	ArraySequence(int count);
	ArraySequence(DynamicArray<Type>& DynamicArray);

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
	ArraySequence<Type>* Concat(Sequence<Type>* list) override;
	
	//destructs
	~ArraySequence() {}
};


//constructs
template<typename Type>
ArraySequence<Type>::ArraySequence() {
	this->arr = new DynamicArray<Type>();
}

template<typename Type>
ArraySequence<Type>::ArraySequence(Type* items, int count) {
	this->arr = new DynamicArray<Type>(items, count);
}

template<typename Type>
ArraySequence<Type>::ArraySequence(int count) {
	this->arr = new DynamicArray<Type>(count);
}

template<typename Type>
ArraySequence<Type>::ArraySequence(DynamicArray<Type>& DynamicArray) {
	this->arr = new DynamicArray<Type>(DynamicArray)
}

//getters
template<typename Type>
Type ArraySequence<Type>::GetFirst() const {
	return	this->arr->Get(0);	
}

template<typename Type>
Type ArraySequence<Type>::GetLast() const {
	return	this->arr->Get(this->arr->GetSize() - 1);
}

template<typename Type>
Type ArraySequence<Type>::Get(int index) const {
	return	this->arr->Get(index);
}

template<typename Type>
int ArraySequence<Type>::GetLength() const {
	return	this->arr->GetSize();
}

template<typename Type>
Sequence<Type>* ArraySequence<Type>::GetSubsequence(int startIndex, int endIndex) const {
	int size = endIndex - startIndex + 1;
	Type* elements = new Type[size];
	for (int i = 0; i < size; ++i) {
		elemnts[i] = this->arr->Get(startIndex + i);
	}

	ArraySequence<Type>* ArraySeq = new ArraySequence(elements, size);
	return ArraySequence;
}

//setters
template<typename Type>
void ArraySequence<Type>::Append(Type item) {
	this->arr->Resize(this->arr->GetLength() + 1);
	this->arr->Set(item, this->arr->GetLength() - 1);
}

template<typename Type>
void ArraySequence<Type>::Prepend(Type item) {
	this->arr->Resize(this->arr->GetLength() + 1);
	for (int i = this->arr->GetLength() - 1; i > 0; --i) {
		this->arr->Set(i, this->arr->Get(i - 1));
	}
	this->arr->Set(0, item);
}

template<typename Type>
void ArraySequence<Type>::InsertAt(Type item, int index) {
	this->arr->Resize(this->arr->GetLength() + 1);
	for (int i = this->arr->GetLength() - 1; i > index; --i) {
		this->arr->Set(i, this->arr->Get(i - 1));
	}
	this->arr->Set(index, item);
}

template<typename Type>
ArraySequence<Type>* ArraySequence<Type>::Concat(Sequence<Type>* list) {
	int size = this->arr->GetLength();
	this->arr->Resize(this->arr->GetLength() + list->GetLength);
	for (int i = size; i < this->arr->GetLength(); ++i) {
		this->arr->Set(i, this->list->Get(i - size));
	}
	return this;
}
#endif