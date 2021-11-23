#pragma once
#include <iostream>

using namespace std;

template<typename T>
struct Node {
	Node() {
		this->data = 0;
		this->prev = nullptr;
		this->next = nullptr;
	}
	Node(T el) {
		this->data = el;
		this->prev = nullptr;
		this->next = nullptr;
	}

	Node<T>* prev;
	Node<T>* next;
	T data;
};

template<typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	Node<T>* begin();
	Node<T>* end();
	int sizeList();
	bool isEmpty();
	void insertFront(T el);
	void insertBack(T el);
	void insert(Node<T>* node, T el);
	void eraseFront();
	void eraseBack();
	void erase(Node<T>* node);
	void eraseX(T x);
	int average();

	void print();
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	for (auto p = head->next; p != tail; ) {
		auto next = p->next;
		delete p;
		p = next;
	}
	this->size = 0;
	delete this->head;
	delete this->tail;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::begin() {
	return this->head;
}

template<typename T>
Node<T>* DoublyLinkedList<T>::end() {
	return this->tail;
}

template<typename T>
int DoublyLinkedList<T>::sizeList() {
	return this->size;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
	if (size == 0)
		return true;

	return false;
}

template<typename T>
void DoublyLinkedList<T>::insertFront(T el) {
	if (head == nullptr) {
		Node<T>* temp = new Node<T>();
		temp->data = el;
		temp->prev = nullptr;
		this->head = temp;
		this->tail = this->head;
		this->size++;
		return;
	}

	Node<T>* temp = new Node<T>();
	temp->data = el;
	temp->prev = nullptr;
	temp->next = head;
	this->head->prev = temp;
	this->head = temp;
	this->size++;
}

template<typename T>
void DoublyLinkedList<T>::insertBack(T el) {
	Node<T>* node = new Node<T>(el);

	if (this->head == nullptr) {
		this->head = node;
		this->tail = this->head;
		this->size++;
		return;
	}

	node->prev = this->tail;
	this->tail->next = node;
	this->tail = this->tail->next;
	this->size++;
}

template<typename T>
void DoublyLinkedList<T>::insert(Node<T>* previous, T el) {
	if (previous == this->tail) {
		insertBack(el);
		return;
	}

	Node<T>* node = new Node(el);
	node->next = previous->next;
	previous->next = node;
	node->prev = previous;

	if (node->next != nullptr)
		node->next->prev = node;

	this->size++;
}

template<typename T>
void DoublyLinkedList<T>::eraseFront() {
	if (this->head == nullptr)
		return;

	Node<T>* temp = this->head;
	this->head = this->head->next;
	this->head->prev = nullptr;
	delete(temp);
}

template<typename T>
void DoublyLinkedList<T>::eraseBack() {
	if (this->tail == nullptr)
		return;

	Node<T>* temp = this->tail;
	this->tail = this->tail->prev;
	this->tail->next = nullptr;
	delete(temp);
}

template<typename T>
void DoublyLinkedList<T>::print() {
	if (size <= 0)
		return;

	Node<T>* curr = head;

	while (curr != nullptr) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}

template<typename T>
void DoublyLinkedList<T>::erase(Node<T>* node) {
	if (this->head == nullptr || node == nullptr)
		return;
	if (node == this->head) {
		eraseFront();
		return;
	}
	if (node == this->tail) {
		eraseBack();
		return;
	}

	if (node->next != nullptr)
		node->next->prev = node->prev;

	if (node->prev != nullptr)
		node->prev->next = node->next;

	delete(node);
}

template<typename T>
void DoublyLinkedList<T>::eraseX(T x) {
	Node<T>* curr = this->head;

	while (curr != nullptr) {
		if (curr->data == x) {
			Node<T>* temp = curr->next;
			erase(curr);
			curr = temp;
			continue;
		}
		curr = curr->next;
	}
}

template<typename T>
int DoublyLinkedList<T>::average() {
	int average = 0;
	Node<T>* curr = this->head;

	while (curr != nullptr) {
		average += curr->data;
		curr = curr->next;
	}

	return average / this->size;
}