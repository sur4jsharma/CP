#include<bits/stdc++.h>
using namespace std;

// build Min heap for user define data type

struct Node
{
    int data;
    int arr_no;
    int index;
};

class minHeap
{
    
    Node *node;
    int size;
    public:
        minHeap(Node node[],int size);
        void heapify(int pos);
        void changeMin(int data); 
        void swap(Node *n1,Node *n2);
        void traverse();
};

 minHeap::minHeap(Node node[],int size)
{
    this->node = node;
    this->size = size;
    int leaf_start_from = size/2;
    for(int i=leaf_start_from-1;i>-1;i--)
    {
        heapify(i);
    }
}

void minHeap::heapify(int pos)
{
    int min = pos;
    // left index of root = 2*index +1, since root starts from 0;
    //right index of root = 2*index +2
    int l = (pos<<1)+1;
    int r = (pos<<1)+2;

    if( l <size && node[min].data > node[l].data )
        min = l;
    if( r < size && node[min].data > node[r].data)
        min = r;
    if(min < size && min != pos)
    {
        swap(&node[pos],&node[min]);
        heapify(min);
    }
}

void minHeap::changeMin(int data)
{
    node[0].data = data;
    node[0].index = node[0].index+1;
    heapify(0);
}

void minHeap::swap(Node *n1,Node *n2)
{
    Node temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void minHeap::traverse()
{
    for(int i=0;i<size;i++)
    {
        cout<<node[i].data<<" ";
    }
    cout<<endl;
}

int main()
{
    int n,k;
    vector<vector<int>> vov;
    cin>>n>>k;
    int data;
    for(int i=0;i<k;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            cin>>data;
            v.push_back(data);
        }
        vov.push_back(v);
    }
    cout<<"vector filled"<<endl;
    Node *node = (Node *)malloc(k * sizeof(Node));
    for(int i=0;i<k;i++)
    {
        node[i].data = vov[i][0];
        node[i].arr_no = i;
        node[i].index = 0;
    }
    minHeap mh(node,k);
    mh.traverse();
}

//1 11
//1 3 5 4 6 13 10 9 8 15 17
// // After max heap of above array: 17 15 13 9 6 5 10 4 8 3 1
// After min heap:1 3 5 4 6 13 10 9 8 15 17 