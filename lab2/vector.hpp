#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <cmath>
#include "array_sequence.hpp"
#include "list_sequence.hpp"

template<typename Type>
class Vector {
protected:
	Sequence<Type>* value;
	virtual Sequence<Type>* GetValue() const = 0;
	int size;
public:
	//getters
	Type Get(int index) const;
	int GetLength() const;

	//setters
	Vector<Type>* Multiplication(Type a);
	Type Multiplication(Vector<Type>* vec2);
	Vector<Type>* Sum(Vector<Type>* vec2);
	float Norm();
	//destructs
	virtual ~Vector() {};
};

//getters
template<typename Type>
Type Vector<Type>::Get(int index) const {
	return this->value->Get(index);
}

template<typename Type>
int Vector<Type>::GetLength() const {
	return this->size;
}

//setters
template<typename Type>
Vector<Type>* Vector<Type>::Multiplication(Type a) {
	for (int i = 0; i < size; ++i) {
		this->value->Set(this->value->Get(i) * a, i);
	}
	return this;
}

template<typename Type>
Type Vector<Type>::Multiplication(Vector<Type>* vec2) {
	Type mult = this->value->Get(0) * vec2->Get(0);
	for (int i = 1; i < size; ++i) {
		mult += this->value->Get(i) * vec2->Get(i);
	}
	return mult;
}

template<typename Type>
Vector<Type>* Vector<Type>::Sum(Vector<Type>* vec2) {
	for (int i = 0; i < this->size; ++i) {
		this->value->Set(this->value->Get(i) + vec2->Get(i), i);
	}
	return this;
}

template<typename Type>
float Vector<Type>::Norm() {
	Type norm = this->value->Get(0) * this->value->Get(0);
	for (int i = 1; i < size; ++i) {
		norm += this->value->Get(i) * this->value->Get(i);
	}
	return sqrt(norm);
}
#endif