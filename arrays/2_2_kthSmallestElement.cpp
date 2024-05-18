#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int count(vector<int>& nums, int& mid)
{
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] <= mid)
			cnt++;

	return cnt;
}

int kthSmallest(vector<int> nums, int& k)
{
	int low = INT_MAX;
	int high = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		low = min(low, nums[i]);
		high = max(high, nums[i]);
	}
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (count(nums, mid) < k)
			low = mid + 1;

		else
			high = mid;
	}
	return low;
}
int main(){
	vector<int> nums{ 1, 4, 5, 3, 19, 3 };
	int k = 3;
	cout << "K'th smallest element is "
		<< kthSmallest(nums, k);
	return 0;
}