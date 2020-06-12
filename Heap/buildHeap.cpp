#include<bits/stdc++.h>
using namespace std;

void swap(int& x,int& y)
{
    x^=y;
    y^=x;
    x^=y;
}

void heapify(int arr[],int n,int index)
{
    int max = index;
    // left index of root = 2*index +1, since root starts from 0;
    //right index of root = 2*index +2
    int l = (index<<1)+1;
    int r = (index<<1)+2;

    if( l <n && arr[max] < arr[l] )
        max = l;
    if( r < n && arr[max] < arr[r])
        max = r;
    if(max < n && max != index)
    {
        swap(arr[index],arr[max]);
        heapify(arr,n,max);
    }
}

void build_Max_Heap(int arr[],int n)
{
    int leaf_start_from = n/2;
    for(int i=leaf_start_from-1 ; i>-1 ; i--)
    {
        heapify(arr,n,i);
    }
}

int find_min_maxHeap(int heap[],int n)
{
    // one of the leaf node will be minimum
    int leaf_start_from = n/2;
    int min = INT_MAX;
    for(int i=leaf_start_from;i<n;i++)
    {
        if(heap[i] < min)
            min = heap[i];
    }
    return min;
}

void insert_into_maxHeap(int heap[],int n,int data)
{

}

void delete_from_maxHeap(int heap[],int& n,int index)
{
    if(index >= n)
        return;
    swap(heap[index],heap[n-1]);
    n = n-1;
    heapify(heap,n,index);
}

void printHeap(int heap[],int n)
{
    for(int i=0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<endl;
}

int main()
{
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    // After max heap of above array: 17 15 13 9 6 5 10 4 8 3 1 
    build_Max_Heap(arr,n);
    printHeap(arr,n);
    cout<<"minimum is: "<<find_min_maxHeap(arr,n)<<endl;
    return 0;
}