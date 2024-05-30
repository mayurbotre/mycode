#include <bits/stdc++.h> 
using namespace std; 

int trappedWater(vector<int>& arr) 
{ 
	int num_blocks = 0; 
	int n = 0; 
	int max_height = INT_MIN; 

	for (auto height : arr) { 
		num_blocks += height; 
		n += 1; 
		max_height = max(max_height, height); 
	} 

	int total = 0; 
	int left = 0; 
	int right = n - 1; 

	for (int i = 1; i <= max_height; i++) { 

		while (arr[left] < i) 
			left += 1; 

		while (arr[right] < i) 
			right -= 1; 

		total += (right - left + 1); 
	} 

	total -= num_blocks; 
	return total; 
} 
 
int main() { 
	vector<int> arr = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
	cout << trappedWater(arr) << endl; 
	return 0; 
} 