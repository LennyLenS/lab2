#ifndef SQ_MATRIX_ARRAY_HPP
#define SQ_MATRIX_ARRAY_HPP
#include <cmath>
#include <iostream>
#include "array_sequence.hpp"


template<typename Type>
class ArrayMatrix {
protected:
    ArraySequence<Type>* value;
    int row;
    ArraySequence<Type>* GetValue() const;
public:
    friend std::ostream& operator << (std::ostream& os, const ArrayMatrix<Type>* mat) {
        for (int i = 0; i < mat->GetRow(); ++i) {
            for (int j = 0; j < mat->GetRow(); ++j) {
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
    float GetNorm() const;

    //setters
    ArrayMatrix<Type>* Sum(ArrayMatrix<Type>* mat2);
    ArrayMatrix<Type>* Mult(Type a);
    ArrayMatrix<Type>* SumRow(int ind1, int ind2);
    ArrayMatrix<Type>* SumColumn(int ind1, int ind2);
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
float ArrayMatrix<Type>::GetNorm() const {
    float a = 0;
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->row; ++j) {
            a += this->value[i].Get(j) * this->value[i].Get(j);
        }
    }
    return sqrt(a);
}

//setters
template<typename Type>
ArrayMatrix<Type>* ArrayMatrix<Type>::Sum(ArrayMatrix<Type>* mat2) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->row; ++j) {
            Type a = this->value[i].Get(j) + (mat2->GetValue())[i].Get(j);
            this->value[i].Set(a, j);
        }
    }
    return this;
}

template<typename Type>
ArrayMatrix<Type>* ArrayMatrix<Type>::Mult(Type a) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->row; ++j) {
            Type b = this->value[i].Get(j) * a;
            this->value[i].Set(b, j);
        }
    }
    return this;
}

template<typename Type>
ArrayMatrix<Type>* ArrayMatrix<Type>::SumRow(int ind1, int ind2) {
    for (int j = 0; j < this->row; ++j) {
        this->value[ind1].Set(this->value[ind1].Get(j) + this->value[ind2].Get(j), j);
    }
    return this;
}

template<typename Type>
ArrayMatrix<Type>* ArrayMatrix<Type>::SumColumn(int ind1, int ind2) {
    for (int i = 0; i < this->row; ++i) {
        this->value[i].Set(this->value[i].Get(ind1) + this->value[i].Get(ind2), ind1);
    }
    return this;
}
#endif
