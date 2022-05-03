#pragma once
#ifndef VECTOR_ARRAY_H
#define VECTOR_ARRAY_H
#include "array_sequence.h"
#include "vector.h"

template<typename Type>
class ArrayVector : public Vector<Type> {
protected:
	Sequence<Type>* GetValue() const override;
public:
    //constructs
    ArrayVector(Type* array, int count);
    ArrayVector(Sequence<Type>* sequence);
    // Destructor
    ~ArrayVector() {}
};

template <typename Type>
Sequence<Type>* ArrayVector<Type>::GetValue() const {
    return this->value;
}

template<typename Type>
ArrayVector<Type>::ArrayVector(Type* array, int count) {
    ArraySequence<Type>* arr = new ArraySequence(array, count);
    this->value = arr;
    this->size = count;
}

template<typename Type>
ArrayVector<Type>::ArrayVector(Sequence<Type>* sequence) {
    this->value = arr;
    this->size = sequence->GetLength;
}
#endif