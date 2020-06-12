#include<bits/stdc++.h>
using namespace std;
#define m 6
#define n 6
struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void treeTraverse(Node *root)// pre order
{
    if(root)
    {
        cout<<root->data<<" ";
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
}



Node *buildTree(vector< pair<vector<int>,int> >& vov)
{
    vector<int> v;
    Node *root = NULL;
    int parent,child;
    int svov = vov.size();
    Node *node[svov];

    for(int l=0;l<svov;l++)
        node[l] = NULL;

    int sv;
    for(int i=0;i<svov;i++)
    {
        v = vov[i].first;
        sv = v.size();
        if(sv>0)
        {   
            if(!node[i])
                node[i] = createNode(i);
            parent = v[0];
            do
            {
                child = parent;
                parent = vov[child].second;
            }while(parent!=-1 && parent!=i);

            if(!node[child])
                node[child] = createNode(child);
            node[i]->left = node[child];
            vov[child].second = i;//parent is set.

            if(sv>1)// setting right child
            {
                int k = 1;
                parent = v[k];
                while(!node[i]->right && k<sv && parent!=-1)
                {
                    parent = v[k++];
                    do
                    {
                        child = parent;
                        parent = vov[child].second;
                    }while(parent!=-1 && parent!=i);
                }
                    if(!node[child])
                        node[child]= createNode(child);
                    node[i]->right = node[child];
                    vov[child].second = i;//parent is set.
            }
            if(vov[i].second == -1)
                root = node[i];
        }
    }
    return root;
}

Node *fillVector(int mat[m][n])
{
    vector< pair<vector<int>,int> > vov;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            if(mat[i][j] == 1)
                temp.push_back(j);
        }
        vov.push_back(make_pair(temp,-1));
    }
    return buildTree(vov);
}

int main()
{
    int mat[m][n] = {
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 1, 1, 0 }, 
        { 1, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1, 0 } 
    }; 
    Node *root = fillVector(mat);
    cout<<"Tree has been build"<<endl;
    treeTraverse(root);
    cout<<endl;
}
