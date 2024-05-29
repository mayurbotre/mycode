#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int arr_size, int sum)
{
	for (int i = 0; i < arr_size - 2; i++) {
		unordered_set<int> s;
		int curr_sum = sum - A[i];
		for (int j = i + 1; j < arr_size; j++) {
			int required_value = curr_sum - A[j];
			if (s.find(required_value) != s.end()) {
				printf("Triplet is %d, %d, %d", A[i], A[j],
					required_value);
				return true;
			}
			s.insert(A[j]);
		}
	}
	return false;
}

int main(){
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int sum = 22;
	int arr_size = sizeof(A) / sizeof(A[0]);
	find3Numbers(A, arr_size, sum);
	return 0;
}