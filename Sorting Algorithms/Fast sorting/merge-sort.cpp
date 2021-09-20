#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& vec) {
	for (auto num : vec){
		cout << num << ' ';
	}
}

vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> result;
	unsigned i = 0, k = 0;
	while (i < a.size() && k < b.size()) {
		if (a[i] <= b[k])
			result.push_back(a[i++]);
		else
			result.push_back(b[k++]);
	}

	while (i < a.size())
		result.push_back(a[i++]);

	while (k < b.size())
		result.push_back(b[k++]);

	return result;
}

vector<int> merge_sort(vector<int>& arr, int start, int end) {
	if (start == end) {
		vector<int> temp;
		temp.push_back(arr[start]);
		return temp;
	}
	int mid = start + (end - start) / 2;

	return merge(merge_sort(arr, start, mid), merge_sort(arr, mid + 1, end));
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> vec(n);
	for (unsigned i = 0; i < vec.size(); i++){
		cin >> vec[i];
	}

	vec = merge_sort(vec,0, vec.size() - 1);
	print(vec);

	return 0;
}