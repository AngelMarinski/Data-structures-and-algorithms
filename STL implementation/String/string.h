#pragma once
#include <iostream>

using namespace std;

int strLen(const char* str);

class MyString {
public:
	MyString();
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();
	MyString(const char* _str);
	void appendString(const char* _string);
	void appendSymbol(const char symbol);
	void printString();
	bool operator==(const MyString& other);
	bool operator!=(const MyString& other);
	bool operator>(const MyString& other);
	bool operator<(const MyString& other);
private:
	char* str;
	void copyFrom(const MyString& other);
	void deleteNeed();
	void resize(int sizeOfStr, int symbolSize);
};