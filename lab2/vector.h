#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include "array_sequence.h"
#include "list_sequence.h"

template<typename Type>
class Vector {
protected:
	Sequense<Type>* value;
	int size;
public:
	//getters
	Type Get(int index) const;
	int GetLength() const;

	//setters
	Vector<Type>* Multiplication(Type a);
	Type Multiplication(Vector<Type> vec2);
	Vector<Type>* Sum(Vector<Type> vec2);

	//destructs
	~Matrix() {}
};

//getters
template<typename Type>
Type Vector<Type>::Get(int index) const {
	return this->value->Get(index)
}

template<typename Type>
int Vector<Type>::GetLength() const {
	return this->size;
}

//setters
template<typename Type>
Vector<Type>* Vector<Type>::Multiplication(Type a) {
	for (int i = 0; i < size; ++i) {
		this->value->Set(this->value->Get(i) * a);
	}
	retrun this;
}

template<typename Type>
Type Vector<Type>::Multiplication(Vector<Type> vec2) {
	Type mult = this->value->Get(0) * vec2->Get(0);
	for (int i = 1; i < size; ++i) {
		mult += this->value->Get(i) * vec2->Get(i);
	}
	retrun mult;
}

template<typename Type>
Vector<Type>* Vector<Type>::Sum(Vector<Type> vec2) {
	for (int i = 0; i < size; ++i) {
		this->value->Set(this->value->Get(i) + vec2->Get(i));
	}
	retrun this;
}
#endif