#include<bits/stdc++.h>
using namespace std;

void sumMaxOfSubArrayK(int arr[],int n,int k)
{
    deque<int> dq;
    deque<int>::iterator it;
    for(int i=0;i<k;i++)
    {
        // Remove indices of those elements that are smaller than current element
        if(dq.empty())
            dq.push_back(i);
        else if(arr[i] > arr[dq.front()])
            dq.push_front(i);
        else if(arr[i] < arr[dq.back()])
            dq.push_back(i);
    }
    //Now largest element is at front of the deque. and smallest is at back;
    int sum = arr[dq.front()] + arr[dq.back()];
    cout<<sum<<" ";
    //Process the remaining elements.

    for(int i=k;i<n;i++)
    {
        
        //Remove all element that are out of the sliding window
        for(it = dq.begin();it!=dq.end();it++)
        {
            if(*it < (i-k+1))
                dq.erase(it--); 
        }
        //remove all element that are smaller than current element
        if(dq.empty())
            dq.push_back(i);
        else if(arr[i] > arr[dq.front()])
        {
            if(dq.size() == 2)
                dq.pop_front();
            dq.push_front(i);
        }
        else if(arr[i] < arr[dq.back()])
        {
            if(dq.size() == 2)
                dq.pop_back();     
            dq.push_back(i);
        }
        sum = arr[dq.front()] + arr[dq.back()];
        cout<<sum<<" ";
    }
}

void maxOfSubArrayK(int arr[],int n,int k)
{
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        // Remove indices of those elements that are smaller than current element
        while(!dq.empty() && (arr[i] > arr[dq.back()]) )
        {
            dq.pop_back();
        }
        
        dq.push_back(i);
    }
    //Now largest element is at front of the deque.
    cout<<arr[dq.front()]<<" ";

    //Process the remaining elements.

    for(int i=k;i<n;i++)
    {
        //Remove all element that are out of the sliding window
        while(!dq.empty() && (dq.front() < (i-k+1)) )
        {
            dq.pop_front();
        }
        //remove all element that are smaller than current element
        while(!dq.empty() && (arr[i] > arr[dq.back()]))
        {
            dq.pop_back();
        }
        dq.push_back(i);
        cout<<arr[dq.front()]<<" ";
    }
}
int main()
{
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int k = 4;
    int n=sizeof(arr)/sizeof(arr[0]);
    maxOfSubArrayK(arr,n,k);
    //cout<<endl;
    //sumMaxOfSubArrayK(arr,n,k);
    cout<<endl;
    return 0;
}