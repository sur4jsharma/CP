#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool threaded;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->threaded = 0;
    return newNode;
}

vector<string> getData(string str)
{
    vector<string> data;
    istringstream ss(str);
    for(string s;ss>>s;)
    {
        data.push_back(s);
    }
    return data;
}

Node *buildTree(string str)
{
    if(str.size() == 0 || str[0] == 'N')
        return NULL;

    vector<string> data;
    vector<string>::iterator it;
    queue<Node *> q;
    data = getData(str);

    it = data.begin();
    Node *root = createNode(stoi(*it));
    advance(it,1);
    q.push(root);

    Node *currRoot;
    while(it!=data.end())
    {
        currRoot = q.front();
        q.pop();
        // cout<<"current root is:"<<currRoot->data<<endl;

    // inserting left node
        // cout<<"left:"<<*it<<endl;
        if(*it != "N")
        {
            currRoot->left=createNode(stoi(*it));
            q.push(currRoot->left);
        }
    //inserting right node

        it++;
        if(it!=data.end())
        {
            // cout<<"right:"<<(*it)<<endl;
            if(*it != "N")
            {
                currRoot->right = createNode(stoi(*it));
                q.push(currRoot->right);
            }
            it++;
        }
    }
    return root;
}

void treeTraverse(Node *root)// In order
{
    if(root)
    {
        
        treeTraverse(root->left);
        cout<<root->data<<" ";
        treeTraverse(root->right);
    }
}

Node *leftMost(Node *root)
{
    if(!root)
        return NULL;
    Node *curr = root;
    Node *currRoot = root;
    while(curr->left)
    {
        if(!curr->right)
        {
            curr->left->right = curr;
            curr->threaded = 1;
        }
        curr = curr->left;
    }
    return curr;
}

void inorderThreaded(Node *root)
{
    Node *curr = leftMost(root);
    if()
    while(curr)
    {
        cout<<curr->data<<" ";
        if(curr->threaded)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }

}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    treeTraverse(root);
    cout<<endl;
    cout<<"Inorder using threaded binary tree"<<endl;
    inorderThreaded(root);
    cout<<endl;
    return 0;
}