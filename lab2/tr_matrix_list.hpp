#ifndef TR_MATRIX_LIST_HPP
#define TR_MATRIX_LIST_HPP
#include <cmath>
#include <iostream>
#include "list_sequence.hpp"


template<typename Type>
class ListMatrix {
protected:
    ListSequence<Type>* value;
    int row;
    int column;
    ListSequence<Type>* GetValue() const;
public:
    friend std::ostream& operator << (std::ostream& os, const ListMatrix<Type>* mat) {
        for (int i = 0; i < mat->GetRow(); ++i) {
            for (int j = 0; j < mat->GetColumn(); ++j) {
                os << mat->Get(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }

    //constructs
    ListMatrix(Type** array, int row);

    //getters
    Type Get(int index1, int index2) const;
    int GetRow() const;
    int GetColumn() const;
    float GetNorm() const;

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
ListMatrix<Type>::ListMatrix(Type** array, int row) {
    ListSequence<Type>* arr = new ListSequence<Type>[row];
    for (int i = 0; i < row; ++i) {
        ListSequence<Type> arr1 = ListSequence<Type>(array[i], row);
        arr[i] = arr1;
    }
    this->value = arr;
    this->row = row;
    this->column = row;
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

template<typename Type>
float ListMatrix<Type>::GetNorm() const {
    float a = 0;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            a += this->value[i].Get(j) * this->value[i].Get(j);
        }
    }
    return sqrt(a);
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
