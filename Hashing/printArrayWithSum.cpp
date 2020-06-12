#include<bits/stdc++.h>
using namespace std;

void printAllArrayWithSum(int arr[], int n) 
{
    // Your code here
    unordered_map<int,vector<int> > m;
    unordered_map<int,vector<int> >::iterator it;
    vector<pair<int,int> > v;
    vector<int>::iterator vit;
    vector<pair<int,int> >::iterator pvit;
    int sum = 0;
    int cur_sum = 0;
    int temp;
    for(int i=0;i<n;i++)
    {
        cur_sum+=arr[i];
        if(cur_sum == sum)
        {
            v.push_back({0,i});
        }
        //temp = cur_sum - arr[i];
        it = m.find(cur_sum);
        if(it !=m.end())
        {
            vit = (it->second).begin();
            for(;vit!=it->second.end();vit++)
            {
                v.push_back(make_pair(*vit+1,i));
            }
        }
        m[cur_sum].push_back(i);
    }
    pvit = v.begin();
    for(;pvit!=v.end();pvit++)
    {
        cout<<"("<<pvit->first<<","<<pvit->second<<")"<<",";
    }
}

int main()
 {
	//code
	int t=1,n,k;
	// cin>>t;
	while(t--)
	{
        int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
        n=sizeof(arr)/sizeof(arr[0]);
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
	   printAllArrayWithSum(arr,n);
       cout<<endl;
	}
	return 0;
}