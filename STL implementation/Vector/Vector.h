#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector {
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector& operator=(const Vector<T>& other);
	~Vector();

	void pushBack(T element);

	void pop();

	void printVector();

	void insert(T element, size_t position);

	void removeFrom(size_t position);

private:
	T* values;
	size_t size;
	size_t capacity;
	void copySupp(const Vector& other);
	void deleteMemory();
	void resize();
};

template <typename T>
Vector<T>::Vector() {
	this->values = nullptr;
	this->size = 0;
	this->capacity = 0;
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
	copySupp(other);
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		deleteMemory();
		copySupp(other);
	}
	return*this;
}
template <typename T>
Vector<T>::~Vector() {
	deleteMemory();
}

template <typename T>
void Vector<T>::pushBack(T element) {
	if (this->values == nullptr) {
		capacity = 8;
		this->values = new T[capacity];
	}
	if (size == capacity) {
		resize();
	}
	this->values[this->size] = element;
	this->size++;
}

template <typename T>
void Vector<T>::pop() {
	if (this->size != 0) {
		this->size--;
	}
	else { cout << endl << "Vector is empty"; }
}

template <typename T>
void Vector<T>::printVector() {
	cout <<endl<< "Capacity: " << this->capacity << endl;
	cout << "Size: " << this->size << endl;
	for (size_t i = 0; i < size; i++) {
		cout << this->values[i] << " ";
	}
}

template <typename T>
void Vector<T>::insert(T element, size_t position) {
if (position > this->size) { cout << "You can not insert the number in this position!"; }
	else {
		this->size++;
		resize();
		for (size_t i = this->size; i >= position; i--) {
			this->values[i] = this->values[i - 1];
		}
		this->values[position] = element;
	}
}

template <typename T>
void Vector<T>::removeFrom(size_t position) {
	if (position > this->size) { cout << "There is no element to remove"; }
	else {
		for (size_t i = position; i < size - 1; i++) {
			this->values[i] = values[i + 1];
		}
		this->size--;
	}
}

template <typename T>
void Vector<T>::copySupp(const Vector& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->values = new T[this->capacity];
	for (size_t i = 0; i < size; i++) {
		this->values[i] = other.values[i];
	}
}

template <typename T>
void Vector<T>::deleteMemory() {
	if (this->values != nullptr) {
		delete[] this->values;
	}
}

template <typename T>
void Vector<T>::resize() {
	if (this->capacity == this->size) {
		this->capacity = this->capacity * 2;
		T* holder = new T[this->capacity];
		for (size_t i = 0; i < size; i++) {
			holder[i] = this->values[i];
		}
		deleteMemory();
		this->values = new T[this->capacity];
		for (size_t i = 0; i < size; i++) {
			this->values[i] = holder[i];
		}
		delete[] holder;
	}
}