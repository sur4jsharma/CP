#include<bits/stdc++.h>
using namespace std;

void equalSumPair(int arr[], int n) 
{
    unordered_map<int,pair<int,int> > mm;
    unordered_map<int,pair<int,int> >::iterator it;
    int sum;
    int a,b,c,d;
    int flag = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum = arr[i]+arr[j];
            it = mm.find(sum);
            if(it != mm.end())
            {
                a = arr[it->second.first];
                b = arr[it->second.second];
                c = arr[i];
                d = arr[j];
                flag = 1;
                break;
            }
            mm.insert({sum,make_pair(i,j)});
        }
        if(flag)
            break;
    }
    if(!flag)
        printf("no pair found");
    else
        printf("(%d,%d) and (%d,%d)",a,b,c,d);
}

int main()
 {
	//code
	int t=1,n,k;
	// cin>>t;
	while(t--)
	{
        int arr[] = {65, 30, 7, 90, 1, 9, 8};
        n=sizeof(arr)/sizeof(arr[0]);
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   equalSumPair(arr,n);
       cout<<endl;
	}
	return 0;
}