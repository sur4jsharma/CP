#include<bits/stdc++.h>
using namespace std;

//0 means boys party

void findDuplicateWithinK(int arr[],int n,int k)
{
    set<int> s;
    int j;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i]) != s.end())
        {
            printf("%d ",arr[i]);
        }
        else
        {
            j = i-k;
            while(j>=0 && j<i)
            {
                s.erase(arr[j]);
                j++;
            }
        }
        s.insert(arr[i]);
    }
}

int main()
 {
	//code
	int t=1,n,k;
	// cin>>t;
	while(t--)
	{
        int arr[] = {1, 2, 3, 1, 4, 5};
        n=sizeof(arr)/sizeof(arr[0]);
        k = 3;
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   findDuplicateWithinK(arr,n,k);
       cout<<endl;
	}
	return 0;
}