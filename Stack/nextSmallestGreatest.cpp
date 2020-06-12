#include<bits/stdc++.h>
using namespace std;

void nextGreater(int arr[],int n)
{
    set<int> se;
    set<int>::iterator it;   
    for(int i=0;i<n;i++)
        se.insert(arr[i]);
    
    for(int i=0;i<n;i++)
    {
        it = se.upper_bound(arr[i]);
        if(it!=se.end())
            cout<<(*it)<<" ";
        else
        {
            cout<<"-1 ";
        }
        it = se.find(arr[i]);
        if(it!=se.end())
            se.erase(it);
    }
    
}

int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    nextGreater(arr,n);
	    cout<<endl;
	}
	return 0;
}