#include <iostream>
#include <vector>

using namespace std;

int binary_search_iterative(vector<int>& arr, int key) {
	int left(0), right(arr.size());
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else
			return mid;
	}

	return -1;
}

int binary_search_recursive(vector<int>& arr, int left, int right, int key) {
	if (left <= right) {
		int mid = left + (right - left) / 2;
		if (key < arr[mid])
			return binary_search_recursive(arr, mid + 1, right, key);
		else if (key > arr[mid])
			return binary_search_recursive(arr, left, mid - 1, key);
		else
			return mid;
	}
	
	return -1;
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> vec(n);

	for (unsigned i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	int key = 0;
	cin >> key;
	cout<<binary_search_iterative(vec, key)<< " " << binary_search_recursive(vec,0,vec.size() - 1,key);
}