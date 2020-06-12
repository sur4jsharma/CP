#include<bits/stdc++.h>
using namespace std;
void nonRepeating(int arr[],int n)
{
    int store_xor = 0;
    int n1,n2;
    for(int i=0;i<n;i++)
    {
        store_xor ^= arr[i];
    }
    int temp = store_xor & ((~store_xor)+1);
    //cout<<temp<<endl;
    n1 = 0;
    n2 = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] & temp)
            n1 = n1 ^ arr[i];
        else
            n2 = n2 ^ arr[i];
    }
    cout<<n1<<" "<<n2<<endl;

}
int main()
{
    int arr[] = {1, 2, 3, 2, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    nonRepeating(arr,n);
}