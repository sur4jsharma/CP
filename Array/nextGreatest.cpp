#include<bits/stdc++.h>
using namespace std;

void place(int arr[],int start, int end)
{
    //Place to correct position

    // cout<<start<<" "<<end<<endl;
    int temp = arr[end];
    int i=end;
    while(i>start)
    {
        arr[i] = arr[i-1];
        i--;
    }
    arr[i] = temp;
}

void sortTheRest(int arr[],int start,int end)
{
    //In place sort
    int i=start;
    int j=end-1;
    int temp;

    while(j>i)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
    //sort(arr+start,arr+end);
}

void nextGreatest(int arr[], int n)
{
    int max = INT_MIN;
    int i,j,k;
    int temp;
    i = n-1;
    while(arr[i-1] > arr[i])
    {
        i--;
    }
    j=i-1;
    // cout<<j<<endl;
    temp = arr[j];
    // cout<<temp<<endl;
    for(k=n-1;k>i;k--)
    {
        if(arr[k] > temp)
        {
            break;
        }
    }
    // cout<<k<<endl;
    // cout<<arr[k]<<endl;
    place(arr,j,k);
    sortTheRest(arr,j+2,n);
    // cout<<j+1<<endl;
    j=j+1;
    temp = arr[j];
    cout<<temp<<endl;
    while((j+1) < n && temp > arr[j+1])
    {
        arr[j] = arr[j+1];
        j++;
    }
    arr[j]=temp;
}

int main()
{
    int t=1,n;
    //scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int swap = 0;
        int n = sizeof(arr)/sizeof(arr[0]);
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1] > arr[i])
                {
                    swap = 1;
                    break;
                }
        }
        if(swap)
        {
            nextGreatest(arr,n);
        }
        else
            sort(arr,arr+n);
        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        cout<<endl;
    }
}