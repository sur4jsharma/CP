#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }
    int l=0,h=1;
    while(arr[h]==0)
    {
        l=h;
        h=2*h;
    }
    cout<<h;

}