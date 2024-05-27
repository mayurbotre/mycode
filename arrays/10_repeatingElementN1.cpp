#include<bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = (arr[i]-1) % n;
        arr[index] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if(((arr[i]-1) / n) >= 2)
            cout<<i+1<<endl;
    }
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i < n; i++)
        cin>>arr[i];

    cout<<"The repeating elements are: "<<endl;

    printRepeating(arr, n);
    return 0;
}