#include <bits/stdc++.h>
using namespace std;

int maxEqualSum(int N1, int N2, int N3, vector<int>& S1, vector<int>& S2, vector<int>& S3) {

    vector<int> suffix(S3.size() + 1, 0);

    int sum1 = 0;

    unordered_set<int> st1;

    for (int i = S1.size() - 1; i >= 0; i--) {
        sum1 = sum1 + S1[i];
        st1.insert(sum1);
    }

    int sum2 = 0;

    unordered_set<int> st2;

    for (int i = S2.size() - 1; i >= 0; i--) {
        sum2 = sum2 + S2[i];
        st2.insert(sum2);
    }

    for (int i = S3.size() - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + S3[i];
    }

    for (int i = 0; i < suffix.size(); i++) {
        if (st1.find(suffix[i]) != st1.end() && st2.find(suffix[i]) != st2.end()) {
            return suffix[i];
        }
    }
    return 0;
}

int main() {
    vector<int> stack1 = { 3, 2, 1, 1, 1 };
    vector<int> stack2 = { 4, 3, 2 };
    vector<int> stack3 = { 1, 1, 4, 1 };

    cout << maxEqualSum(stack1.size(), stack2.size(), stack3.size(), stack1, stack2, stack3) << endl;
    return 0;
}