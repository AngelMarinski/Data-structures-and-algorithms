#include "Stack.h"

using namespace std;


Stack::Stack(){
	this->stack = nullptr;
	this->capacity = 0;
	this->size = 0;
}

Stack::Stack(const Stack& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->stack = new int[this->capacity];
	for (int i = 0; i < size; i++) {
		this->stack[i] = other.stack[i];
	}
}

Stack Stack::operator=(const Stack& other) {
	if (this->stack != nullptr) {
		delete[] this->stack;
	}
	this->capacity = other.capacity;
	this->size = other.size;
	this->stack = new int[this->capacity];
	for (int i = 0; i < size; i++) {
		this->stack[i] = other.stack[i];
	}
	return *this;
}

Stack::~Stack() {
	if (this->stack != nullptr) {
		delete[] this->stack;
	}
}

void Stack::push(int element) {
	if (this->stack == nullptr) {
		capacity = 1;
		this->stack = new int[capacity];
	}
	if (size == capacity) {
		this->capacity = this->capacity * 2;
		int* support = new int[capacity];
		for (int i = 0; i < size; i++) {
			support[i] = this->stack[i];
		}
		delete[] this->stack;
		this->stack = support;
	}
	this->stack[size] = element;
	this->size++;
}
	
void Stack::pop() {
	if (this->size != 0) {
		this->size--;
	}
}

int Stack::peek() {
	return this->stack[size-1];
}

bool Stack::empty() {
	if (this->size == 0) {
		return true;
	}
	return false;
}

void Stack::printStack() {
	for (int i = 0; i <size; i++) {
		cout << endl << this->stack[i];
	}
}
