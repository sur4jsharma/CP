#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[],int n)
{
    int k=n-1;
    int limit = n-1;
    list<int> l;
    list<int>::iterator it;    
    for(int i=0;i<n;i++)
    {
        l.push_back(arr[i]);
    }
    while(limit--)
    {
        l.push_front(l.back());
        l.pop_back();
        it = l.begin();
    
        if(k>0)
        {
             advance(it,k);
             cout<<(*it)<<endl;
             l.erase(it);
             cout<<"k is within range\n";
        }
        else
        {
            l.pop_front();
        }
        
        k-=2;
    }
    it = l.begin();
    while(it!=l.end())
    {
        cout<<(*it)<<" ";
        it++;
    }
    
}

int main()
{
    int t,n;
    // cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        rotateArray(arr,n);
        cout<<endl;
    }
}