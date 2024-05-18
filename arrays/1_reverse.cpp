#include<bits/stdc++.h>
using namespace std;    

class Solution
{
    public:
    string reverseWord(string str){
        int n=str.length();
        int start=0,end=n-1;
        while(start<end){
            swap(str[start], str[end]);
            start++;
            end--;
        }
        return str;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.reverseWord(s)<<endl;
    }
    return 0;
}