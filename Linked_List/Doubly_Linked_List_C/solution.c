#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <crtdbg.h>

struct Node {
	struct Node* next;
	struct Node* prev;
	int val;
};

struct Node* head;
int size = 0;

//helper function in case insert is called with position 0
//helps with reducing the amonth of code in insert 
void add_front(struct Node* node) {
	if (head == NULL) {
		head = node;
		size++;
		return;
	}

	node->next = head;
	head->prev = node;
	head = node;
	size++;
}

void insert(struct Node* node, int position) {
	if (position > size)
		return;
	//uncomment if you want to determine the program when invalid position is passed
	//assert(position<size)

	if (position == 0) {
		add_front(node);
		return;
	}

	struct Node* curr=head;
	struct Node* previous = NULL;
	int i = 0;

	for (i ; i < position && curr != NULL; i++) {
		previous = curr;
		curr = curr->next;
	}

	//satifying warnings with those ifs
	if (previous != NULL && previous->next != NULL)
		node->next = previous->next;
	if (previous != NULL)
		previous->next = node;
	node->prev = previous;
	if (node->next != NULL)
		node->next->prev = node;
	
	size++;
}

void erase(int position) {
	if (head == NULL || position >= size)
		return;

	//uncomment if you want to determine the program when invalid position is passed
	//or list is empty;
	//assert(head != NULL && position < size);

	if (position == 0) {
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		size--;
		return;
	}

	struct Node* curr = head;
	struct Node* prev = NULL;

	for (int i = 0; i < position; i++) {
		prev = curr;
		curr = curr->next;
	}

	if (curr != NULL && prev != NULL)
		prev->next = curr->next;
	if (curr != NULL && curr->next != NULL)
		curr->next->prev = curr->prev;

	size--;
}

void print() {
	struct Node* curr = head;
	while (curr != NULL) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}

int main() {
	//this func is checking for memory leaks but it costs us program execution speed
	//and in this case we dont actully need it to be honest, because we are not using dynamic allocations
	//_CrtSetBreakAlloc(_CRTDBG_LEAK_CHECK_DF);
	
	struct Node node1 = { NULL, NULL, 1 };
	struct Node node2 = { NULL, NULL, 4 };
	struct Node node3 = { NULL, NULL, 2 };
	struct Node node4 = { NULL, NULL, 3 };
	
	//adding nodes in the list
	insert(&node1, 0);
	//after insertion: 1
	insert(&node2, 0);
	//after insertion: 4 -> 1
	insert(&node3, 1);
	//after insertion: 4 -> 2 -> 1
	insert(&node4, 2);
	//after insertion: 4-> 2 -> 3 -> 1

	print();

	//the list contains: 4 -> 2 -> 3 -> 1
	//positions:         0    1    2    3
	//by erasing on position 2 we are erasing node with value 3
	erase(2);
	print();

	erase(2);
	print();

	erase(0);
	print();

	//trying to erase unreal position
	erase(142141);
	print();

	erase(1);
	print();

	erase(0);
	print();

	return 0;
}