
int countBitsFlip(int a, int b){
    int val=a^b;
    int res;
    while(val){
        if(val&1) res++;
        val=val>>1;
    }
    return res;
}
int main(){
    int result = get2NonRepeatingNos(10, 20);
    cout << "The bit flips are " << result << endl;
}