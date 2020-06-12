#include<bits/stdc++.h>
using namespace std;

/*
void rearrange(int arr[],int n)
{
    int i,j,k;
    i=0;
    k=0;
    int max = 0;
    int count=n;//track how many indeces of output array is correctly filled
    int temp = arr[i];
    while(count>0)
    {
        while(arr[i]!=k)
        {
            j = arr[i];
            arr[i] = arr[j];
            i=j;
            
            if(i>max)
                max = i;
        }
        arr[i] = temp;
        count = n-(max+1);
        //when input array can be split in multiple parts then start same process from other parts.
        if(count>0)
        {
            max=max+1;
            i=max;
            k=i;
            temp=arr[i];
        }
    }
}
*/

void rearrange(int arr[],int n)
{

        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i] + (arr[arr[i]]%n)*n;
        }
        for(int i=0;i<n;i++)
        {
            arr[i] = arr[i]/n;
            cout<<arr[i]<<" ";
        }
    cout<<endl;
}

int main()
{
    // int arr[]={3,2,0,1};
    int n=100;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = i;
    }
    //int arr[]={ 0, 1, 2, 3,4,5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    rearrange(arr,n);
}