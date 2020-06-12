#include<bits/stdc++.h>
using namespace std;

void printMissing(int arr[],int n,int st,int en)
{
    set<int> s;
    set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    for(int num = st;num<en;num++)
    {
        if(s.find(num) == s.end())
        {
            printf("%d ",num);
        }
    }
}

int main()
 {
	//code
	int t=1,n;
	// cin>>t;
	while(t--)
	{
        int arr[] = {1, 14, 11, 51, 15};
        n=sizeof(arr)/sizeof(arr[0]);
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   printMissing(arr,n,50,55);
       cout<<endl;
	}
	return 0;
}