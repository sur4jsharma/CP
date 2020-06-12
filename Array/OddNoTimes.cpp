#include<bits/stdc++.h>
using namespace std;
int main()
{
    int result=0;
    int arr[] = {1, 2, 3, 2, 3, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        result ^= arr[i];
    }
    cout<<"Number occuring odd times is: "<<result<<endl;
}