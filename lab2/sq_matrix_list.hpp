#ifndef SQ_MATRIX_LIST_HPP
#define SQ_MATRIX_LIST_HPP
#include <cmath>
#include <iostream>
#include "list_sequence.hpp"


template<typename Type>
class ListMatrix {
protected:
    ListSequence<Type>* value;
    int row;
    ListSequence<Type>* GetValue() const;
public:
    friend std::ostream& operator << (std::ostream& os, const ListMatrix<Type>* mat) {
        for (int i = 0; i < mat->GetRow(); ++i) {
            for (int j = 0; j < mat->GetRow(); ++j) {
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
    float GetNorm() const;

    //setters
    ListMatrix<Type>* Sum(ListMatrix<Type>* mat2);
    ListMatrix<Type>* Mult(Type a);
    ListMatrix<Type>* SumRow(int ind1, int ind2);
    ListMatrix<Type>* SumColumn(int ind1, int ind2);
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
float ListMatrix<Type>::GetNorm() const {
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
ListMatrix<Type>* ListMatrix<Type>::Sum(ListMatrix<Type>* mat2) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->row; ++j) {
            Type a = this->value[i].Get(j) + (mat2->GetValue())[i].Get(j);
            this->value[i].Set(a, j);
        }
    }
    return this;
}

template<typename Type>
ListMatrix<Type>* ListMatrix<Type>::Mult(Type a) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->row; ++j) {
            Type b = this->value[i].Get(j) * a;
            this->value[i].Set(b, j);
        }
    }
    return this;
}

template<typename Type>
ListMatrix<Type>* ListMatrix<Type>::SumRow(int ind1, int ind2) {
    for (int j = 0; j < this->row; ++j) {
        this->value[ind1].Set(this->value[ind1].Get(j) + this->value[ind2].Get(j), j);
    }
    return this;
}

template<typename Type>
ListMatrix<Type>* ListMatrix<Type>::SumColumn(int ind1, int ind2) {
    for (int i = 0; i < this->row; ++i) {
        this->value[i].Set(this->value[i].Get(ind1) + this->value[i].Get(ind2), ind1);
    }
    return this;
}
#endif
