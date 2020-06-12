#include<bits/stdc++.h>
using namespace std;

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
    newNode->left=NULL;
    newNode->right=NULL;
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
        if(it!=data.end() && *it!= "N")
        {
            // cout<<"right:"<<(*it)<<endl;
            currRoot->right = createNode(stoi(*it));
            q.push(currRoot->right);
            it++;
        }
    }
    return root;
}

void treeTraverse(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
}

void incrChild(Node *root)
 {
     if(!root)
        return;
     if(root->left)
     {
        if(root->right)
        {
            root->left->data = root->data - root->right->data;
        }
        else
            root->left->data = root->data;
        incrChild(root->left);
    }
    else if(root->right)
    {
        root->right->data = root->data;
        incrChild(root->right);
    }
        
 }
 
int sumTree(Node *root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->data;
    int l = sumTree(root->left);
    int r = sumTree(root->right);
    if(l+r > root->data)
        root->data = l+r;
    else
        incrChild(root);
    return root->data;
}
Node* buildChildrenTree(Node* root)
{
    sumTree(root);   
    return root;
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    // treeTraverse(root);
    // cout<<endl;
    Node *temp = buildChildrenTree(root);
    treeTraverse(root);
    // cout<<"Product of sum of leaves at level is: "<<sum<<endl;
    return 0;
}

// 2 7 5 N N N 9