#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n){
	if (n <= 0)
		return 0;
	if ((n & (~(n - 1))) == n)
		return 1;
	return 0;
}
int main(){
	isPowerofTwo(30) ? cout << "Yes\n" : cout << "No\n";
	isPowerofTwo(128) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}
