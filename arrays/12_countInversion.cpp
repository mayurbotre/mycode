#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getNumOfInversions(vector<int>& A) {
	int N = A.size();
	if (N <= 1) {
		return 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sortList;
	int result = 0;
	for (int i = 0; i < N; i++) {
		sortList.push(make_pair(A[i], i));
	}
	vector<int> x;
	while (!sortList.empty()) {
		int v = sortList.top().first;
		int i = sortList.top().second;
		sortList.pop();
		int y = upper_bound(x.begin(), x.end(), i) - x.begin();
		result += i - y;

		x.insert(upper_bound(x.begin(), x.end(), i), i);
	}

	return result;
}
int main() {
	vector<int> A = {1, 20, 6, 4, 5};
	int result = getNumOfInversions(A);
	cout << "Number of inversions are " << result << endl;

	return 0;
}