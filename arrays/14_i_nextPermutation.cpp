#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& arr)
{
    
    auto it = is_sorted_until(arr.rbegin(), arr.rend());

    if (it == arr.rend()) {
        reverse(arr.begin(), arr.end());
    } else {
        auto next_it = upper_bound(arr.rbegin(), it, *it);
        swap(*it, *next_it);
        reverse(arr.rbegin(), it);
    }
}

int main(){

    vector<int> arr = { 3, 2, 1 };

    nextPermutation(arr);

    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}