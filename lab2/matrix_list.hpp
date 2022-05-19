#ifndef MATRIX_LIST
#define VECTOR_ARRAY_HPP
#include "array_sequence.hpp"
#include "vector.hpp"

template<typename Type>
class ArrayVector : public Vector<Type> {
protected:
    Sequence<Type>* GetValue() const override;
public:
    //constructs
    ArrayVector(Type* array, int count);
    ArrayVector(Sequence<Type>* sequence);
    // Destructor
    ~ArrayVector() {
        delete this->value;
    }
};

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
#endif