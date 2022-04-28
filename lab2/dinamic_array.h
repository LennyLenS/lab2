#pragma once

#ifndef DINAMIC_ARRAY_H
#define DINAMIC_ARRAY_H

template<typename Type>
class DynamicArray {
private:
	T* arr;
	int size;
public:
	//constructs
	DynamicArray();
	DynamicArray(Type* items, int count);
	DynamicArray(int count);
	DynamicArray(DynamicArray<Type>& dynamicArray);
	//getters
	Type Get(int index) const;
	int GetSize() const;
	//setters
	void Set(int index, Type value);
	void Resize(int newSize);
	//destructor
	~DynamicArray() {}
};

//constructs
template<typename Type>
DynamicArray<Type>::DynamicArray() {
	arr = nullptr;
	size = 0;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(Type* items, int count) {
	arr = new Type[count];
	memcpy(arr, items, count * sizeof(Type));
	size = count;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(int count) {
	arr = new Type[count];
	size = count;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(DynamicArray<Type>& dynamicArray) {
	size = dynamicArray.GetSize();
	arr = new Type[size];
	memcpy(arr, &dynamicArray, size * sizeof(Type));
}

//getters
template<typename Type>
Type DynamicArray<Type>::Get(int index) const{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Out of range");
	}
	return arr[index];
}

template<typename Type>
int DynamicArray<Type>::GetSize() const {
	return size;
}

//setters
template<typename Type>
void DynamicArray<Type>::Set(int index, Type value) {
	if (index < 0 || index >= size) {
		throw std::out_of_range("Out of range");
	}
	memcpy(arr + index * sizeof(Type), &value, sizeof(Type));
}

template<typename Type>
void DynamicArray<Type>::Resize(int newSize) {
	if (newSize < 0) {
		throw std::invalid_argument("Invalid argument");
	}
	Type* new_arr = new Type[newSize];
	memcpy(new_arr, arr, newSize * sizeof(Type));
	arr = new_arr;
	size = newSize;
}
#endif