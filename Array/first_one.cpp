#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int closestPair(int arr[],int n,int num)
{
        int i,j,mid,minDiff=INT_MAX,pair;
        i=0;
        j=n-1;
        pair = arr[(i+j)/2];
        cout<<"first pair is "<<num<<endl;
        cout<<"passed array are:"<<endl;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        while(i<j)
        {
            cout<<"in while"<<endl;
            mid=(i+j)/2;
            cout<<"mid element is "<<arr[mid]<<endl;
            minDiff=abs(arr[mid]+num);
            if(((mid + 1)<=j) && (abs((arr[mid+1] + num)) < minDiff))
            {
                i=mid+1;
                pair = arr[mid+1];
            }
            else if(((mid-1)>=0) && (abs((arr[mid-1] + num)) < minDiff))
            {
                j=mid-1;
                pair = arr[mid -1];
            }
            else
                break;
        }
        cout<<"pair is: "<<pair<<endl;
        return pair;
}

int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
        cout<<"input taken"<<endl;
        sort(arr,arr+n);
        int x1,x2,minDiff=INT_MAX,temp;
        for(int i=0;i<n-1;i++)
        {
                temp = closestPair((arr+i+1),(n-i-1),arr[i]);
                if((temp + arr[i]) < minDiff)
                {
                        x1=arr[i];
                        x2 = temp;
                        minDiff = abs(x1+x2);
                }
                cout<<"Two numbers are:"<<x1<<" "<<x2<<endl;
        }
        
}