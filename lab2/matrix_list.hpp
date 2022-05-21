#ifndef MATRIX_LIST_HPP
#define MATRIX_LIST_HPP
#include "list_sequence.hpp"


template<typename Type>
class ListMatrix {
protected:
    ListSequence<Type>* value;
    int row;
    int column;
    ListSequence<Type>* GetValue() const;
public:
    //constructs
    ListMatrix(Type** array, int row, int column);

    //getters
    Type Get(int index1, int index2) const;
    int GetRow() const;
    int GetColumn() const;

    //setters
    ListMatrix<Type>* Sum(ListMatrix<Type>* mat2);
    ListMatrix<Type>* Mult(Type a);
    // Destructor
    ~ListMatrix() {}
};


template <typename Type>
ListSequence<Type>* ListMatrix<Type>::GetValue() const {
    return this->value;
}


template<typename Type>
ListMatrix<Type>::ListMatrix(Type** array, int row, int column) {
    ListSequence<Type>* arr = new ListSequence<Type>[row];
    for (int i = 0; i < row; ++i) {
        ListSequence<Type> arr1 = ListSequence<Type>(array[i], column);
        arr[i] = arr1;
    }
    this->value = arr;
    this->row = row;
    this->column = column;
}


//getters
template<typename Type>
Type ListMatrix<Type>::Get(int index1, int index2) const {
    return this->value[index1].Get(index2);
}

template<typename Type>
int ListMatrix<Type>::GetRow() const {
    return this->row;
}

template<typename Type>
int ListMatrix<Type>::GetColumn() const {
    return this->column;
}


//setters
template<typename Type>
ListMatrix<Type>* ListMatrix<Type>::Sum(ListMatrix<Type>* mat2) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            Type a = this->value[i].Get(j) + (mat2->GetValue())[i].Get(j);
            this->value[i].Set(a, j);
        }
    }
    return this;
}

template<typename Type>
ListMatrix<Type>* ListMatrix<Type>::Mult(Type a) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            Type b = this->value[i].Get(j) * a;
            this->value[i].Set(b, j);
        }
    }
    return this;
}
#endif
