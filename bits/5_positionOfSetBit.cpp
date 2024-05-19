#include <iostream>
#include <cmath>
using namespace std;

int findPosition(int N) {
    if(N==0) return -1;
    if((N&(N-1))==0){
        int c=0;
        while(N){
            c++;
            N=N>>1;
        }
        return c;
    } else {
        return -1;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<"Number of set bits in "<<N<<" is "<< findPosition(N)<<endl;
    }
    return 0;
}
//This code is contributed by Veerendra_Singh_Rajput
