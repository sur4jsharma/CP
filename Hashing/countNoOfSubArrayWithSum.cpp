#include<bits/stdc++.h>
using namespace std;

void countSubArraySumInAnyArray(int arr[],int n,int sum)
{
    unordered_map<int,int>um;
    unordered_map<int,int>::iterator it;
    int curr_sum = 0;
    int temp;
    int count = 0;
    //um.insert(pair<int,int>(0,1));
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum == sum)
        {
            count++; 
        }
        temp = curr_sum - sum;   
        it = um.find(temp);
        if(it != um.end())
        {
            count+=it->second;
        } 
        it = um.find(curr_sum);
        // if(it==um.end())
        //     um.insert({curr_sum,0});
        um[curr_sum]++;
    }
    cout<<count<<endl;

}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        countSubArraySumInAnyArray(arr,n,0);
    
    }

    return 0;
}
