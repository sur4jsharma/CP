#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,sum;
    int reqSum;
    cin>>t;
    int flag;
    int i;
    while(t--)
    {
        flag = 0;
        cin>>n>>sum;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        
        int l,r;
        int x1,x2,x3;
        reqSum = sum;
        for(i=0;i<n-2;i++)
        {
            l=i+1;
            r=n-1;
            while(l<r)
            {
                reqSum = sum - arr[i];
                reqSum -= (arr[l]+arr[r]);
                //cout<<"REq sum:"<<reqSum<<endl;
                if(reqSum == 0)
                {
                     cout<<"1"<<endl;
                     flag = 1;
                     break;
                }
                if(reqSum < 0)
                {
                    r--;
                }
                else
                    l++;
                
            }
            if(reqSum == 0)
            {
                //cout<<"Triplet is: {"<<x1<<","<<x2<<","<<x3<<"}"<<endl;
                break;
            }
        }
        if(!flag)
            cout<<"0"<<endl;
    }
    

}