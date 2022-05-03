#pragma once
#ifndef VECTOR_LIST_H
#define VECTOR_LIST_H
#include "list_sequence.h"
#include "vector.h"

template<typename Type>
class ListVector : public Vector<Type> {
protected:
    Sequence<Type>* GetValue() const override;
public:
    //constructs
    ListVector(Type* array, int count);
    ListVector(Sequence<Type>* sequence);
    // Destructor
    ~ArrayVector() {
        delete GetValue();
    }
};

template <typename Type>
Sequence<Type>* ListVector<Type>::GetValue() const {
    return this->value;
}

template<typename Type>
ListVector<Type>::ListVector(Type* array, int count) {
    ArraySequence<Type>* arr = new ListSequence<Type>(array, count);
    this->value = arr;
    this->size = count;
}

template<typename Type>
ListVector<Type>::ListVector(Sequence<Type>* sequence) {
    this->value = new ListSequence<Type>(sequence);
    this->size = sequence->GetLength;
}

#endif