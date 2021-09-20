#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& vec) {
	for (unsigned i = 1; i < vec.size(); i++) {
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key){
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}