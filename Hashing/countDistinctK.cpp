#include<bits/stdc++.h>
using namespace std;

void countDistinct(int arr[], int n, int k) 
{
    // Your code here
    unordered_map<int,int> m;
    unordered_map<int,int>::iterator it;
    int count=0;
    int temp=k;
    for(int i=0;i<n;i++)
    {
        it = m.find(arr[i]);
        temp--;
        if(it == m.end())
        {
            //cout<<(it->first)<<endl;
            count++;
        }
        m[arr[i]] = i;
        if(!temp)
        {
            cout<<count<<" ";
            it = m.find(arr[i-k+1]);
            if(it->second == (i-k+1))
            {
                m.erase(it);
                count--;
            }
            temp++;
        }
    }
}

int main()
 {
	//code
	int t=1,n,k;
	// cin>>t;
	while(t--)
	{
        int arr[] = {1, 2, 3, 1, 1, 5};
        n=sizeof(arr)/sizeof(arr[0]);
        k = 3;
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   countDistinct(arr,n,k);
       cout<<endl;
	}
	return 0;
}