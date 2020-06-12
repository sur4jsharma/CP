#include<bits/stdc++.h>
using namespace std;

void swap(int& x,int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int partition(int arr[],int st,int en,int k)
{
    for(int i=st;i<=en;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    int pivot = arr[en];
    cout<<"pivot is:"<<pivot<<endl;
    int j=st-1;
    for(int i=st;i<=en;i++)
    {
        if(arr[i] <= pivot)
        {
            j++;
            cout<<"both numbers are:"<<arr[j]<<" "<<arr[i]<<endl;
            swap(arr[j],arr[i]);
        }
    }

    for(int i=st;i<=en;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return j;
}

int kthSmallest(int arr[],int st,int en,int k)
{
    int pivot_index = partition(arr,st,en,k);
    cout<<"pivot index is:"<<pivot_index<<endl<<endl;;
    if(pivot_index == (k-1) )
    {
        return arr[pivot_index];
    }
    if(pivot_index >=k)
        return kthSmallest(arr,st,pivot_index-1,k);
    else
        return kthSmallest(arr,pivot_index+1,en,k);
}

int main()
{
	//code
	int t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   cin>>k;
	   int smallest = -1;
	    if(k<=n)
            smallest = kthSmallest(arr,0,n-1,k);
	    cout<<smallest<<endl;
	}
	    return 0;
}

// 1
// 6
// 7 10 4 3 20 15
// 3