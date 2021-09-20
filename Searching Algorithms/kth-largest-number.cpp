#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<time.h>
#include <algorithm>
using namespace std;

void swap(int arr[], int from, int to) {
	int temp = arr[from];
	arr[from] = arr[to];
	arr[to] = temp;
}

int partition(int left, int right, int arr[], int pivot) {
	int pivotValue = arr[pivot];
	int i = left;
	swap(arr, pivot, right);
	for (int j = left; j < right; j++) {
		if (arr[j] < pivotValue) {
			swap(arr, j, i);
			i++;
		}
	}
	swap(arr, right, i);
	return i;
}

int kth_element(int* arr, int N, int k) {
	int left = 0;
	int right = N - 1;
	while (left <= right) {
		srand(time(0));
		int pivot = rand() % ((right - left + 1) + left);
		int finalPivot = partition(left, right, arr, pivot);
		if (finalPivot == N - k) {
			return arr[finalPivot];
		}
		if (finalPivot > N - k) {
			right = finalPivot - 1;
		}
		else {
			left = finalPivot + 1;
		}
	}
	return -1;
}

int main() {
	int N = 0;
	int K = 0;
	cin >> N >> K;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << kth_element(arr, N, K);
}