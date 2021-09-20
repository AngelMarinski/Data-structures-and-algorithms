#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void bubble_sort(vector<int>& arr) {
	for (unsigned i = 0; i < arr.size(); i++) {
		for (unsigned k = i + 1; k < arr.size(); k++) {
			if (arr[i] > arr[k])
				swap(arr[i], arr[k]);
		}
	}
}