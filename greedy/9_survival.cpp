#include <bits/stdc++.h> 
using namespace std; 

void survival(int S, int N, int M) { 
    int x = S/7;
    int y = S - x;
    int sm = S * M;
    int days = sm / N;
    if(sm % N != 0) days++;
    if(days <= y) cout<< "Yes" << days << endl;
    else cout<< "No" << endl;  
} 

int main() { 
	int S = 10, N = 16, M = 2; 
	survival(S, N, M); 
	return 0; 
} 