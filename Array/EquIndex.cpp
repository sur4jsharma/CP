#include<iostream>
using namespace std;
int main()
{
    int n,index=-1,sum=0,lsum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sum-=arr[i];
        if(lsum==sum)
        {
            index=i;
            break;
        }
        lsum+=arr[i];
    }
        cout<<"Equlibrium index= "<<index<<endl;
}