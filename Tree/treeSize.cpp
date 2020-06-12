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

int getSize(Node* node) //iterative
{
    queue<Node *> q;
    int count = 0;
    if(!node)
        return 0;
    q.push(node);
    Node *currRoot;
    while(!q.empty())
    {
        currRoot = q.front();
        q.pop();
        count++;
        if(currRoot->left)
            q.push(currRoot->left);
        if(currRoot->right)
            q.push(currRoot->right);
    }
    return count;
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    treeTraverse(root);
    cout<<endl;
    cout<<"size of tree:"<<getSize(root)<<endl;
    return 0;
}