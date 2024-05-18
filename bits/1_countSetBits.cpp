#include <bits/stdc++.h>
using namespace std;

unsigned int countSetBits(unsigned int n){
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}
int main(){
	int i = 9;
	cout << countSetBits(i);
    //cout << __builtin_popcount(4) << endl;
    //cout << __builtin_popcount(15) << endl;
	return 0;
}