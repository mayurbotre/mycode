#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int N, int K)
{
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		pq.push(arr[i]);
		if (pq.size() > K)
			pq.pop();
	}
	return pq.top();
}
int main(){
	int N = 10;
	int arr[N] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
	int K = 4;
	cout << "Kth Smallest Element is: "
		<< kthSmallest(arr, N, K);
}
