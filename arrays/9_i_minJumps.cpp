#include <bits/stdc++.h> 
using namespace std; 

int min(int x, int y) { return (x < y) ? x : y; } 

int minJumps(int arr[], int n) 
{ 
	int* jumps = new int[n]; 
	int i, j; 
	if (n == 0 || arr[0] == 0) 
		return INT_MAX; 
	jumps[0] = 0; 
	for (i = 1; i < n; i++) { 
		jumps[i] = INT_MAX; 
		for (j = 0; j < i; j++) { 
			if (i <= j + arr[j] && jumps[j] != INT_MAX) { 
				jumps[i] = min(jumps[i], jumps[j] + 1); 
				break; 
			} 
		} 
	} 
	return jumps[n - 1]; 
} 

int main() { 
	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }; 
	int size = sizeof(arr) / sizeof(int); 
	cout << "Minimum number of jumps to reach end is "
		<< minJumps(arr, size); 
	return 0; 
} 