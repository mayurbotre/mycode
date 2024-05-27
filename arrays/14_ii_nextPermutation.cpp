#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& A) {
    int n = A.size();
    int ind = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        reverse(A.begin(), A.end());
        return ;
    }

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    reverse(A.begin() + ind + 1, A.end());
}

int main(){

    vector<int> arr = { 3, 2, 1 };

    nextPermutation(arr);

    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}