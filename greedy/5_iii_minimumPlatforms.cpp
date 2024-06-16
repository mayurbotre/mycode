#include <bits/stdc++.h> 
using namespace std; 

int findPlatformOptimized(int arr[], int dep[], int n) { 

	int count = 0, maxPlatforms = 0; 

	int maxDepartureTime = dep[0]; 
	for (int i = 1; i < n; i++) { 
		maxDepartureTime = max(maxDepartureTime, dep[i]); 
	} 

	vector<int> v(maxDepartureTime + 2, 0); 

	for (int i = 0; i < n; i++) { 
		v[arr[i]]++; 
		v[dep[i] + 1]--; 
	} 

	for (int i = 0; i <= maxDepartureTime + 1; i++) { 
		count += v[i]; 
		maxPlatforms = max(maxPlatforms, count); 
	} 

	return maxPlatforms; 
} 

int main() { 
	int arr[] = { 100, 300, 600 }; 
	int dep[] = { 900, 400, 500 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findPlatformOptimized(arr, dep, n); 
	return 0; 
}