#include <iostream>
#include "string.h"

using namespace std;

int strLen(const char* str) {
	const char* Reader = str;
	if (Reader == nullptr) { return 0; }
	while (*Reader != '\0') {
		Reader++;
	}
	return Reader - str;
}

MyString::MyString() {
	this->str=nullptr;
}
MyString::MyString(const MyString& other) {  //rule of three
	deleteNeed();
	copyFrom(other);
}
MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		deleteNeed();
		copyFrom(other);
	}
	return *this;
}
MyString::~MyString() {
	deleteNeed();
}
MyString::MyString(const char* _str) {
	int size = strLen(_str);
	deleteNeed();
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++) {
		this->str[i] = _str[i];
	}
	this->str[size] = '\0';	
}
void MyString::appendString(const char* _string) {
	int size = strLen(_string);
	int sizeOfStr = strLen(this->str);
	resize(sizeOfStr, size);
	for (int i = 0; i < size+1; i++) {//from the size of this->str to the last element +1 cuz we want to copy the \0 too
		this->str[sizeOfStr] = _string[i];
		sizeOfStr++;
	}
}
void MyString::appendSymbol(const char symbol) {
	int size = strLen(this->str);
	resize(size, 1);
	this->str[size]=symbol;
	this->str[size + 1] = '\0';
}
void MyString::printString() {
	int sizeOfstr = strLen(this->str);
	for (int i = 0; i < sizeOfstr; i++) {
		cout << this->str[i];
	}
}
bool MyString::operator==(const MyString& other) {
	int thisSize = strLen(this->str);
	int otherSize = strLen(other.str);
	if (thisSize > otherSize) {
		return false;
	}
	if (thisSize < otherSize) {
		return false;
	}
	for (int i = 0; i < thisSize; i++) {
		if (this->str[i] != other.str[i]) {
			return false;
		}
	}
	return true;
}
bool MyString::operator!=(const MyString& other) {
	int thisSize = strLen(this->str);
	int otherSize = strLen(other.str);
	if (thisSize != otherSize) { return true; }
	for (int i = 0; i < thisSize; i++) {
		if (this->str[i] != other.str[i]) {
			return true;
		}
	}
	return false;
}
bool MyString::operator>(const MyString& other) {
	int thisSize = strLen(this->str);
	int otherSize = strLen(other.str);
	if (thisSize > otherSize) { return true; }
	if (thisSize < otherSize) { return false; }
	for (int i = 0; i < thisSize; i++) {
		if (this->str[i] > other.str[i]) { return true; }
		if (this->str[i] < other.str[i]) { return false; }
	}
	return false;
}
bool MyString::operator<(const MyString& other) {
	int thisSize = strLen(this->str);
	int otherSize = strLen(other.str);
	if (thisSize > otherSize) { return false; }
	if (thisSize < otherSize) { return true; }
	for (int i = 0; i < thisSize; i++) {
		if (this->str[i] < other.str[i]) { return true; }
		if (this->str[i] > other.str[i]) { return false; }
	}
	return false;//if they are equal
}
void MyString::copyFrom(const MyString& other) {
	int size = strLen(other.str);
	this->str = new char[size + 1];
	for (int i = 0; i < size; i++) {
		this->str[i] = other.str[i];
	}
	this->str[size] = '\0';
}
void MyString::deleteNeed() {
	if (this->str != nullptr) {
		delete[] this->str;
	}
}
void MyString::resize(int sizeOfStr, int symbolSize) {// helper function that resize the given str as much as needed
	char* holder = new char[sizeOfStr + symbolSize + 1];
	for (int i = 0; i < sizeOfStr; i++) {
		holder[i] = this->str[i];
	}
	deleteNeed();
	this->str = new char[sizeOfStr + symbolSize + 1];
	for (int i = 0; i < sizeOfStr; i++) {
		this->str[i] = holder[i];
	}
	delete[] holder;
}