#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> goats;
int n = 0, k = 0;

bool is_fit(int weight) {
	int course = 0;
	vector<bool> taken(goats.size(), false);
	for (unsigned i = 0; i < goats.size(); i++) {
		int curr_weight = 0;
		if (taken[i])
			continue;
		curr_weight += goats[i];
		for (unsigned k = i + 1; k < goats.size(); k++) {
			if (taken[k])
				continue;
			if (curr_weight + goats[k] <= weight) {
				taken[k] = true;
				curr_weight += goats[k];
			}
		}
		course++;
		if (course > k)
			return false;
	}
	return true;
}

int binary_search(int left, int right) {
	int first_find = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (is_fit(mid)) {
			right = mid - 1;
			first_find = mid;
		}
		else{
			left = mid + 1;
		}
	}
	return first_find;
}

int main() {
	int total_weight = 0;

	cin >> n >> k;
	goats.resize(n);
	for (unsigned i = 0; i < goats.size(); i++) {
		cin >> goats[i];
		total_weight += goats[i];
	}
	sort(goats.begin(), goats.end(), greater<int>());
	cout << endl << binary_search(0, total_weight);

	return 0;
}