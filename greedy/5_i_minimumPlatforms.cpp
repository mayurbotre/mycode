#include <bits/stdc++.h> 
using namespace std; 

int findPlatform(int arr[], int dep[], int n) { 
	vector<pair<int, int> > arr2(n); 

	for (int i = 0; i < n; i++) { 
		arr2[i] = { arr[i], dep[i] }; 
	} 

	sort(arr2.begin(), arr2.end()); 

	priority_queue<int, vector<int>, greater<int> > p; 
	int count = 1; 
	p.push(arr2[0].second); 

	for (int i = 1; i < n; i++) { 

		if (p.top() >= arr2[i].first) { 
			count++; 
		} 
		else { 
			p.pop(); 
		} 
		p.push(arr2[i].second); 
	} 

	return count; 
} 

int main() { 
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findPlatform(arr, dep, n); 
	return 0; 
}