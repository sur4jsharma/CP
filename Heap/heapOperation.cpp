#include<bits/stdc++.h>
using namespace std;

void swap(int& x,int& y)
{
    x^=y;
    y^=x;
    x^=y;
}

void heapify(vector<int>& arr,int index)
{
    int n = arr.size();
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
        heapify(arr,max);
    }
}

void build_Max_Heap(vector<int>& arr)
{
    int n = arr.size();
    int leaf_start_from = n/2;
    for(int i=leaf_start_from-1 ; i>-1 ; i--)
    {
        heapify(arr,i);
    }
}

int find_min_maxHeap(vector<int> heap)
{
    int n = heap.size();
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

void insert_into_maxHeap(vector<int>& heap,int data)
{
    heap.push_back(data);
    int n = heap.size();
    int child_index = n-1;
    cout<<"size of heap is:"<<n<<endl;
    cout<<"inserted node index is:"<<child_index<<endl;
    int parent_index = (child_index - 1) / 2;
    while(parent_index > -1 && (heap[parent_index] < heap[child_index]) )
    {
        swap(heap[parent_index],heap[child_index]);
        child_index = parent_index;
        parent_index = (child_index -1)/ 2;
    }
}

void delete_from_maxHeap(vector<int>& heap,int index)
{
    int n = heap.size();
    if(index >= n)
        return;
    swap(heap[index],heap[n-1]);
    heap.pop_back();
    heapify(heap,index);
}

void increse_key(vector<int>& heap,int index)// increse by 10
{
    heap[index] = heap[index] - 10;
    
    int n = heap.size();
    int child_index = index;
    int parent_index = (child_index - 1) / 2;
    while(parent_index > -1 && (heap[parent_index] < heap[child_index]) )
    {
        swap(heap[parent_index],heap[child_index]);
        child_index = parent_index;
        parent_index = (child_index -1)/ 2;
    }

}

void decrese_key(vector<int>& heap,int index) // decrese by 10
{
    heap[index] = heap[index] - 10;
    heapify(heap,index);
}

void printHeap(vector<int> heap)
{
    int n = heap.size();
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
    int in[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(in) / sizeof(in[0]);
    // After max heap of above array: 17 15 13 9 6 5 10 4 8 3 1 
    vector<int> arr;
    for(int i=0;i<n;i++)
        arr.push_back(in[i]);

    //build heap takes O(n)

    build_Max_Heap(arr);
    printHeap(arr);

    // delete from max heap takes O(logn)

    delete_from_maxHeap(arr,4);
    cout<<"After deletion of: "<<arr[4]<<endl;
    printHeap(arr);

    // insert into max heap takes O(logn)

    insert_into_maxHeap(arr,7);
    cout<<"After insertion:"<<endl;
    printHeap(arr);
    insert_into_maxHeap(arr,40);
    cout<<"After insertion:"<<endl;
    printHeap(arr);
    insert_into_maxHeap(arr,27);
    cout<<"After insertion:"<<endl;
    printHeap(arr);
    insert_into_maxHeap(arr,55);
    cout<<"After insertion:"<<endl;
    printHeap(arr);

    // finding minimum from max heap takes O(n)

    cout<<"minimum is: "<<find_min_maxHeap(arr)<<endl;
    return 0;
}