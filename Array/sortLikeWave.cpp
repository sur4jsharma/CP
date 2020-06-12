#include<bits/stdc++.h>
using namespace std;

void waveSort(int arr[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        if(i%2 == 0)
        {
            if(arr[i] < arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }   
        }
        else
        {
            if(arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        
        
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    waveSort(arr,n);
}