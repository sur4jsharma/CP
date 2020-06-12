#include<bits/stdc++.h>
using namespace std;

int findPos(int arr[],int key)
{
    int pos = -1;
    int i=1;
    int size = 10000;
    int low,high;
    int count = 0;
    if(arr[0] == key)
        return 0;
    while(size--)
    {
        count++;
        cout<<arr[i]<<" ";
        if(arr[i] == key)
        {
            cout<<"number of searches:"<<count<<endl;
            return i;
        }
        if(arr[i] > key)
        {
            low = i>>2;
            high = i;
            break;
        }
         i<<=1;
    }
    for(i=low;i<high;i++)
    {
        count++;
        if(arr[i] == key)
        {
            pos = i;
            break;
        }
    }
    cout<<endl;
            cout<<"number of searches:"<<count<<endl;

    return pos;
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170,180,190,200,210,220,230,240};
    cout<<findPos(arr,230)<<endl;
}