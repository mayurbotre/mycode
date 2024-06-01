#include <bits/stdc++.h>
using namespace std;

int smallestSubArrayLen(int target, vector<int>& nums)
{
	int n = nums.size();

	if (n == 0) return 0;

	int ans = INT_MAX - 1;

	vector<int> sums(n + 1, 0);

	for (int i = 1; i <= n; i++) sums[i] = sums[i - 1] + nums[i - 1];

	for (int i = 1; i <= n; i++) {

		int to_find = target + sums[i - 1];

		auto bound = lower_bound(sums.begin(), sums.end(), to_find);

		if (bound != sums.end() && *bound != to_find) {

			int len = bound - (sums.begin() + i - 1);

			ans = min(ans, len);

		}
	}
    
	return (ans != INT_MAX - 1) ? ans : 0;
}

int main(){
	vector<int> arr1 = { 1, 4, 45, 6, 10, 19 };
	int target1 = 51;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target1, arr1) << endl;

	vector<int> arr2 = { 1, 10, 5, 2, 7 };
	int target2 = 9;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target2, arr2) << endl;

	vector<int> arr3 = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int target3 = 11;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target3, arr3) << endl;

	vector<int> arr4
		= { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
	int target4 = 280;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target4, arr4) << endl;

	return 0;
}