#include <iostream>
#include <vector>
#include <ctime>;
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(vector<int> arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
}

void quick_sort(vector<int>& arr, int start, int end) {
	if (start >= end)
		return;
	
	int size = end - start + 1;
	int pivot = start + rand() % size;

	swap(arr[start], arr[pivot]);
	int idx = start + 1;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] < arr[start])
			swap(arr[idx++], arr[i]);
	}
	swap(arr[start], arr[idx - 1]);
	quick_sort(arr, start, idx - 2);
	quick_sort(arr, idx, end);
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> vec(n);

	for (unsigned i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
	srand(time(NULL));
	quick_sort(vec, 0, vec.size() - 1);
	print(vec);
}