#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void counting_sort(vector<int>& vec) {
	vector<int> negative(10000, 0);
	vector<int> positive(10000, 0);

	for (unsigned i = 0; i < vec.size(); i++) {
		if (vec[i] > 0)
			positive[vec[i]]++;
		else
			negative[abs(vec[i])]++;
	}

	int idx = 0;

	for (int i = negative.size() - 1; i >= 0; i--) {
		for (int j = 0; j < negative[i]; j++)
			vec[idx++] = -i;
	}
	for (unsigned i = 0; i < positive.size(); i++) {
		for (int j = 0; j < positive[i]; j++)
			vec[idx++] = i;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	counting_sort(vec);

	for (auto num : vec) {
		cout << num << " ";
	}

	return 0;
}