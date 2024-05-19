#include <bits/stdc++.h>
using namespace std;

vector<int> get2NonRepeatingNos(vector<int>& nums)
{
    long long int diff = 0;
    for (auto i : nums) {
        diff = i ^ diff;
    }
    diff &= -diff;
    vector<int> rets = {
        0, 0
    }; 
    for (int num : nums) {
        if ((num & diff) == 0) { 
            rets[0] ^= num;
        }
        else { 
            rets[1] ^= num;
        }
    }
    if (rets[0] > rets[1]) {
        swap(rets[0], rets[1]);
    }
    return rets;
}
int main        (){
    vector<int> arr = { 2, 3, 7, 9, 11, 2, 3, 11 };
    vector<int> result = get2NonRepeatingNos(arr);
    cout << "The non-repeating elements are " << result[0] << " and " << result[1];
}
