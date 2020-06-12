#include<bits/stdc++.h>
using namespace std;

// void swap(int& x,int& y)
// {
//     x^=y;
//     y^=x;
//     x^=y;
// }

void inplaceMerge(int arr1[],int arr2[],int n1,int n2)
{
    int gap = n1+n2;
    gap = (gap/2)+(gap%2);
    int i,j;
    int rem;
    while(gap)
    {
        // cout<<"gap is:"<<gap<<endl;
        i=0;
        j=i+gap;
        //(gap+1) is sliding window size, no of time loop runs is total size - window size
        
        while(j<n1)
        {
            if(arr1[i] > arr1[j])
                swap(arr1[i],arr1[j]);
            i++;
            j++;
        }
        j=0;
        while(i<n1 && j<n2)
        {
            if(arr1[i] > arr2[j])
                swap(arr1[i],arr2[j]);
            i++;
            j++;
        }
        i=0;
        while(j<n2)
        {
            if(arr2[i] > arr2[j])
                swap(arr2[i],arr2[j]);
            i++;
            j++;
        }
        if(gap==1)
            break;
        gap = (gap/2)+(gap%2);
    }
        for(int i=0;i<n1;i++)
            cout<<arr1[i]<<" ";
        for(int i=0;i<n2;i++)
            cout<<arr2[i]<<" ";
        cout<<endl;
}

int main()
 {
	//code
	int t,n1,n2;
	// cin>>t;
    t=1;
	while(t--)
	{
	    // cin>>n1>>n2;
        n1=50;
        n2=10;
	    int arr1[n1];
	    int arr2[n2];
	    for(int i=0;i<n1;i++)
	        arr1[i]=i+1;
        for(int i=0;i<n2;i++)
            arr2[i]=i+1;
        for(int i=0;i<n1;i++)
            cout<<arr1[i]<<" ";
        for(int i=0;i<n2;i++)
            cout<<arr2[i]<<" ";
        cout<<endl;
        inplaceMerge(arr1,arr2,n1,n2);
	}
	return 0;
}