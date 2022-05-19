#ifndef MATRIX_ARRAY_HPP
#define MATRIX_ARRAY_HPP
#include "array_sequence.hpp"
#include "matrix.hpp"

template<typename Type>
class ArrayMatrix : public Matrix<Type> {
protected:
    Sequence<Type>* GetValue() const override;
public:
    //constructs
    ArrayMatrix(Type* array, int count);
    ArrayMatrix(Sequence<Type>* sequence);

    //getters
    Type Get(int index, int index2) {
        return this->val->Get(index1).Get(index2);
    }
    // Destructor
    ~ArrayMatrix() {
        delete this->value;
    }
};

/*
template <typename Type>
Sequence<Type>* ArrayVector<Type>::GetValue() const {
    return this->value;
}

template<typename Type>
ArrayVector<Type>::ArrayVector(Type* array, int count) {
    ArraySequence<Type>* arr = new ArraySequence<Type>(array, count);
    this->value = arr;
    this->size = count;
}

template<typename Type>
ArrayVector<Type>::ArrayVector(Sequence<Type>* sequence) {
    this->value = new ArraySequence<Type>(sequence);
    this->size = sequence->GetLength;
}
*/
#endif
