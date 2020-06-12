#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] =  { 0, 1, 0, 1, 1, 1 };
    int n = sizeof(arr)/sizeof(int);
    int pivot = 1;
    int j=-1;
    int temp;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            temp =arr[j];
            arr[j]=arr[i];
            arr[i]=temp; 
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}