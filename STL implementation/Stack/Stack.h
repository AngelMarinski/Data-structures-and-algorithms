#include <iostream>

using namespace std;

class Stack {
public:
	Stack();
	Stack(const Stack& other);
	Stack operator=(const Stack& other);
	~Stack();

	void push(int element);
	void pop();
	int peek();
	bool empty();
	void printStack();
private:
	int* stack;
	unsigned int size;
	unsigned int capacity;
};