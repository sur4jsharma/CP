#include<bits/stdc++.h>
using namespace std;

//0 means boys party

bool checkDisjoint(int arr1[],int arr2[],int n1,int n2)
{
    set<int> s;
    for(int i=0;i<n1;i++)
    {
        s.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++)
    {
        if(s.find(arr2[i]) != s.end())
            return 0;
    }
    return 1;
}

int main()
 {
	//code
	int t=1,n1,n2;
	// cin>>t;
	while(t--)
	{
        int arr1[] = {12, 34, 11, 9, 3};
        int arr2[] = {7, 2, 1, 5};
        n1=sizeof(arr1)/sizeof(arr1[0]);
        n2 = sizeof(arr2)/sizeof(arr2[0]);
	    // cin>>n;
        // cin>>k;
	    // int arr[n];
	    // for(int i=0;i<n;i++)
	    //     cin>>arr[i];
        if(checkDisjoint(arr1,arr2,n1,n2))
            cout<<"disjoint";
        else
            cout<<"not disjoint";
       cout<<endl;
	}
	return 0;
}