#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum;
    /*
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>sum;
    */
    int arr[] = { 1, 4, 45, 6, 10, 8 };
    sum = 16;
    n = sizeof(arr)/sizeof(arr[0]);
    int to_find;
    unordered_set<int> us;
    unordered_set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        to_find = sum - arr[i];
        it = us.find(to_find);
        if(it != us.end())
        {
            cout<<"Numbers are: "<<arr[i]<<"\t"<<to_find<<endl;
            break;
        }
        else if(i < n-1)
        {
            us.insert(arr[i]);
        }
        else
        {
            cout<<"Not Found"<<endl;
        }
    }
}