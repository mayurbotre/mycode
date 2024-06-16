#include <bits/stdc++.h> 
using namespace std; 

int buyMaximumProducts(int n, int k, int price[]){
    vector<pair<int ,int>> v;
    for(int i = 1; i <= n; i++)
    v.push_back({price[i-1], i});
    
    sort(v.begin(), v.end());
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        int value = v[i].first * v[i].second;
        if(k >= value){
            k = k - value;
            ans += v[i].second;
        }
        else {
            ans += k/v[i].first;
            break;
        }
    }
    return ans;
}