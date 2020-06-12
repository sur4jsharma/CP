#include<bits/stdc++.h>
using namespace std;
void findDuplicate(int arr[],int n)
{
    int temp;
    int count = 0;
    set<int> s;
    int flag = 1;
    set<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
            count++;
    }
    if(count >1)
        s.insert(0);
    for(int i=0;i<n;i++)
    {
        temp = abs(arr[i]);
        //cout<<"temp is "<<temp<<" arr[temp] "<<arr[temp]<<endl;
        if(i !=n-1 &&  arr[temp] ==-n)
        {
            cout<<"i is "<<i<<" "<<arr[i]<<endl;
            cout<<"temp:"<<temp<<endl;
            s.insert(temp);
            arr[temp]=0;
        }
        else if(temp < n && (arr[temp] < 0)) /* || (!temp && ++count == 2))*/
        {
            // cout<<temp<<" ";
            s.insert(temp);
            cout<<"index: "<<i<<" temp:"<<temp<<endl;
            // arr[temp] = -(n);
        }
        
        if(arr[temp] == 0)
        {
            arr[temp] = -n;
        }
        else
            arr[temp] = -(abs(arr[temp]));
    }
    // cout<<s.size()<<endl;
    if(s.size())
        for(it=s.begin();it!=s.end();it++)
            cout<<(*it)<<" ";
    else
    {
        cout<<"-1";
    }
    
}
int main()
{
    // int arr[] = {2, 3, 1, 2, 3};
    // int n=sizeof(arr)/sizeof(arr[0]);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    findDuplicate(arr,n);
    cout<<endl;
}