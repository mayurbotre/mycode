#include <bits/stdc++.h> 
using namespace std; 

int findMinimum(int arr[], int n, int k) {

	int res = 0; 

	for (int i = 0; i < n; i++) { 

		res += arr[i]; 

		n = n - k; 
	} 
	return res; 
} 

int findMaximum(int arr[], int n, int k) { 
	int res = 0, index = 0; 

	for (int i = n - 1; i >= index; i--) { 

		res += arr[i]; 

		index += k; 
	} 
	return res; 
} 

int main() { 
	int arr[] = { 3, 2, 1, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 2; 
	sort(arr, arr + n); 

	// Function call 
	cout << findMinimum(arr, n, k) << " "
		<< findMaximum(arr, n, k) << endl; 
	return 0; 
}