#include<bits/stdc++.h>
using namespace std;

void subArraySumInPosArray(int arr[],int n,int sum)
{
    int si,li;
    int curr_sum = 0;
    si = 0;
    li = -1;
    int tail = 0;
    for(int i=0;i<n;i++)
    {
        curr_sum+= arr[i];
        //cout<<"Current element is:"<<arr[i]<<" and sum till now is:"<<curr_sum<<endl;

        if(curr_sum == sum)
        {
            li = i;
            break;
        }
        else if(curr_sum > sum)
        {
            // remove trailing element until curr_sum > sum;
            while(tail < i && (curr_sum) > sum)
            {
                curr_sum-=arr[tail];
                tail++;
            }
            if(curr_sum == sum)
            {
                si = tail;
                li = i;
                break;
            }        
        }
    }
    if(li != -1)
    {
        cout<<"Sum found between index "<<si<<" and "<<li<<endl;
    }
}

void zeroSumInSubArray(int arr[],int n)
{
    
    int sum = 0;
    unordered_map<int,int>um;
    unordered_map<int,int>::iterator it;
    int curr_sum = 0;
    int si=0;
    int li=-1;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        it = um.find(curr_sum);
        if(it != um.end())
        {
            //cout<<"Key:"<<it->first<<" Value:"<<it->second<<endl;
            si = it->second + 1;
            li = i;
            //cout<<"si:"<<si<<" li:"<<li<<endl;
        }
        um.insert(pair<int,int>(curr_sum,i));

    }
    if(li == -1)
        cout<<"No such sub array exists"<<endl;
    else
        cout<<"Sum found between index "<<si<<" and "<<li<<endl;


}

void subArraySumInAnyArray(int arr[],int n,int sum)
{
    unordered_map<int,int>um;
    unordered_map<int,int>::iterator it;
    int curr_sum = 0;
    int si=0;
    int li=-1;
    int temp;   
    //um.insert({0,1}) ;
    //cout<<um[0]<<endl;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum == sum)
        {
            si = li+1;    
            li = i;  
        }
        temp = curr_sum - sum;   
        it = um.find(temp);
        if(it != um.end())
        {
            si = it->second + 1;    
            li = i;                
            cout<<"si:"<<si<<" li:"<<li<<endl;
        } 
        um.insert(pair<int,int>(curr_sum,i));            
    }
    if(li == -1)
        cout<<"No such sub array exists"<<endl;
    else
        cout<<"Sum found between index "<<si<<" and "<<li<<endl;

}


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
    // int arr[] = {-3, 2, 3, 1, 6};
    //int arr[] = {9, 45, 10, 190};
    int arr[] = {10, 2 ,-2 ,-20, 10};
    int sum = -10;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // int t,n,sum;
    // cin>>t;
    // while(t--)
    // {
    //     cin>>n;
    //     int arr[n];
    //     for(int i=0;i<n;i++)
    //         cin>>arr[i];
    //     cin>>sum;
    
    //     subArraySumInAnyArray(arr,n,sum);    
    // }

    countSubArraySumInAnyArray(arr,n,sum);

    //subArraySumInPosArray(arr,n,sum);
    //subArraySumInAnyArray(arr,n,sum);
    //zeroSumInSubArray(arr,n);
}