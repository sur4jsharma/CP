#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *buildPerfectBST(int arr[],int n)// n>=1 and arr is level order traversal of BST
{
    int i=0;
    Node *root = new Node(arr[i++]);
    queue<Node*> q;
    q.push(root);
    Node *curr;
    while(i<n)
    {
        curr = q.front();
        q.pop();
        curr->left = new Node(arr[i++]);
        q.push(curr->left);
        if(i<n)
        {
            curr->right = new Node(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

void inOrder(Node *root)
{
    if(root)
    { 
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void fillVector(Node *root,vector<int>& v)
{
    if(root)
    { 
        fillVector(root->left,v);
        v.push_back(root->data);
        fillVector(root->right,v);
    }
}

void BSTtoHeap(Node *root,vector<int>& v,int& i)//geeks for geeks approach(better)
{
    if(root)
    {
        BSTtoHeap(root->left,v,i);
        BSTtoHeap(root->right,v,i);
        root->data = v[i++];
    }
}

Node *bstToHeap(vector<int>& v,int st,int en)//My approach
{
    if(st == en)
    {
        return new Node(v[st]);
    }
    if(st<en)
    {
        Node *root = new Node(v[en]);
        int mid = (st+en)/2;
        
        root->left = bstToHeap(v,st,mid-1);
        root->right = bstToHeap(v,mid,en-1);
        return root;
    }
    else
        return NULL;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Node *root = buildPerfectBST(arr,n);
    cout<<endl;
    inOrder(root);//After Build BST
    cout<<endl;
    vector<int> v;
    fillVector(root,v);
    int i=0;
    BSTtoHeap(root,v,i);//Method 1
    inOrder(root);//After BST to Max Heap
    cout<<endl;

    Node *rootHeap = bstToHeap(v,0,n-1);// Method 2
    inOrder(rootHeap);
    cout<<endl;

    //extra not related to this question
    // priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater< pair< int,pair<int,int> > > > pq;
    // pq.push(make_pair(10,make_pair(1,2)));
    // pq.push(make_pair(5,make_pair(1,2)));

    // pair<int,pair<int,int>> p;
    // p = pq.top();
    // cout<<p.first<<endl;

}

// 7
// 4 2 6 1 3 5 7