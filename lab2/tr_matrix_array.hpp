#ifndef TR_MATRIX_ARRAY_HPP
#define TR_MATRIX_ARRAY_HPP
#include <cmath>
#include <iostream>
#include "array_sequence.hpp"


template<typename Type>
class ArrayMatrix {
protected:
    ArraySequence<Type>* value;
    int row;
    int column;
    ArraySequence<Type>* GetValue() const;
public:
    friend std::ostream& operator << (std::ostream& os, const ArrayMatrix<Type>* mat) {
        for (int i = 0; i < mat->GetRow(); ++i) {
            for (int j = 0; j < mat->GetColumn(); ++j) {
                os << mat->Get(i, j) << " ";
            }
            os << std::endl;
        }
        return os;
    }

    //constructs
    ArrayMatrix(Type** array, int row);

    //getters
    Type Get(int index1, int index2) const;
    int GetRow() const;
    int GetColumn() const;
    float GetNorm() const;

    //setters
    ArrayMatrix<Type>* Sum(ArrayMatrix<Type>* mat2);
    ArrayMatrix<Type>* Mult(Type a);
    // Destructor
    ~ArrayMatrix() {}
};


template <typename Type>
ArraySequence<Type>* ArrayMatrix<Type>::GetValue() const {
    return this->value;
}


template<typename Type>
ArrayMatrix<Type>::ArrayMatrix(Type** array, int row) {
    ArraySequence<Type>* arr = new ArraySequence<Type>[row];
    for (int i = 0; i < row; ++i) {
        ArraySequence<Type> arr1 = ArraySequence<Type>(array[i], row);
        arr[i] = arr1;
    }
    this->value = arr;
    this->row = row;
    this->column = row;
}


//getters
template<typename Type>
Type ArrayMatrix<Type>::Get(int index1, int index2) const {
    return this->value[index1].Get(index2);
}

template<typename Type>
int ArrayMatrix<Type>::GetRow() const {
    return this->row;
}

template<typename Type>
int ArrayMatrix<Type>::GetColumn() const {
    return this->column;
}

template<typename Type>
float ArrayMatrix<Type>::GetNorm() const {
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
ArrayMatrix<Type>* ArrayMatrix<Type>::Sum(ArrayMatrix<Type>* mat2) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            Type a = this->value[i].Get(j) + (mat2->GetValue())[i].Get(j);
            this->value[i].Set(a, j);
        }
    }
    return this;
}

template<typename Type>
ArrayMatrix<Type>* ArrayMatrix<Type>::Mult(Type a) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->column; ++j) {
            Type b = this->value[i].Get(j) * a;
            this->value[i].Set(b, j);
        }
    }
    return this;
}
#endif
