#include<bits/stdc++.h>
using namespace std;

void usingInsertionSort(int arr[],int n)// takes O(n*K) time
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i-1;
        while(j>-1 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        j++;
        arr[j] = temp;
    }
}

void usingMinHeap(int arr[],int n, int k) // each element is at atmost logk depth hence O(n*logk)
{

//build min heap of first K+1 element because if (k+1)th is smaller that root if we insert only k element
// and before inserting (k+1)th element if we remove root then root will not be smallest;
    priority_queue<int , vector<int>, greater<int>> pq(arr,arr+k+1);
// add remaining element in heap
    int temp;
    int index = 0; 
    //cout<<pq.size()<<endl;
    for(int i = k+1;i<n;i++)
    {
        arr[index++] = pq.top(); //delete root root always gives min element store in into array
        pq.pop();
        pq.push(arr[i]);
    }
    while(pq.empty() == 0)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    //usingInsertionSort(arr,n);
    usingMinHeap(arr,n,3);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}