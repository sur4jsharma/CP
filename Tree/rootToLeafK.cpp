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

void treeTraverse(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
}

// d means distance of node from root, h means distance from leaf
int deleteNodeWithinK(Node *root,int k)
{
    if(!root)
        return 0;
    int l = deleteNodeWithinK(root->left,k-1);
    int r = deleteNodeWithinK(root->right,k-1);
    int height = 1+max(l,r);
    if(height < k)
    {
        root->left = NULL;
        root->right = NULL;
        root->data = -1;
    }
    else
    {
        if(root->left && (root->left->data == -1))
            root->left = NULL;
        else if(root->right && (root->right->data == -1))
            root->right = NULL;;
    }
    
    return height;
}

void deleteNodeLessThank(Node *root,int k)
{
    int height = deleteNodeWithinK(root,k);
    if(height < k)
    {
        root = NULL;
    }
}


int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    treeTraverse(root);
    cout<<endl;
    deleteNodeLessThank(root,4);
    // cout<<"size of tree:"<<<<endl;
    treeTraverse(root);
    cout<<endl;
    return 0;
}