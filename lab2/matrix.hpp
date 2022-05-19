#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "array_sequence.hpp"
#include "list_sequence.hpp"

template<typename Type>
class Matrix {
protected:
	Sequence<Sequence<Type> >* value;
	virtual Sequence<Sequence<Type> >* GetValue() const = 0;
	int row;
	int column;
public:
	//getters
	Type Get(int index1, int index2) const;
	int GetRow() const;
	int GetColumn() const;

	//setters
	Matrix<Type>* Sum(Matrix<Type>* mat2);
	Matrix<Type>* Mult(Type a);

	//destructs
	virtual ~Matrix() {};
};

//getters
template<typename Type>
Type Matrix<Type>::Get(int index1, int index2) const {
	return this->value->Get(index1).Get(index2);
}

template<typename Type>
int Matrix<Type>::GetRow() const {
	return this->row;
}

template<typename Type>
int Matrix<Type>::GetColumn() const {
	return this->column;
}

//setters
template<typename Type>
Matrix<Type>* Matrix<Type>::Sum(Matrix<Type>* mat2) {
	for (int i = 0; i < this->row; ++i) {
		for (int j = 0; j < this->column; ++j) {
			Type a = this->value->Get(i).Get(j) + mat2->GetValue()->Get(i).Get(j);
			this->value->Set(this->value->Get(i).Set(a, j), i);
		}
	}
	return this;
}

template<typename Type>
Matrix<Type>* Matrix<Type>::Mult(Type a) {
	for (int i = 0; i < this->row; ++i) {
		for (int j = 0; j < this->column; ++j) {
			Type b = this->value->Get(i).Get(j) * a;
			this->value->Set(this->value->Get(i).Set(a, j), i);
		}
	}
	return this;
}

/*
template<typename Type>
float Vector<Type>::Norm() {
	Type norm = this->value->Get(0) * this->value->Get(0);
	for (int i = 1; i < size; ++i) {
		norm += this->value->Get(i) * this->value->Get(i);
	}
	return sqrt(norm);
}
*/
#endif