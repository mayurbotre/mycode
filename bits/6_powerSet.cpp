#include <bits/stdc++.h> 
using namespace std; 

void AllPossibleStrings(string s){
	vector<string> ans;
    int n=pow(2, s.length());
    for(int i=1;i<n;i++){
        int x=i;
        int j=0;
        string c="";
        while(x){
            if(x&1){
                c=c+s[j];
            }
            j++;
            x=x>>1;
        }
        ans.push_back(c);
    }
    sort(ans.begin(), ans.end());
    for(auto out: ans){
        cout<<out<<endl;
    }
}
int main() {
	AllPossibleStrings("abc"); 
	return 0; 
} 