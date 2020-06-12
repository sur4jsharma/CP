#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,count;
    int ele = -1;
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};
    n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int>m;
    unordered_map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        count = ++(m[arr[i]]);
        if(count > (n/2))
        {
            ele = arr[i];
            break;
        }
    }
    cout<<"Majority element is:"<<ele<<endl;
}