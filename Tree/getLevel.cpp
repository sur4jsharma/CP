#include<bits/stdc++.h>
using namespace std;
int dmtr=0;
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
        cout<<"current root is:"<<currRoot->data<<endl;

    // inserting left node
        cout<<"left:"<<*it<<endl;
        if(*it != "N")
        {
            currRoot->left=createNode(stoi(*it));
            q.push(currRoot->left);
        }
    //inserting right node

        it++;
        if(it!=data.end())
        {
            cout<<"right:"<<(*it)<<endl;
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


int getLevel(Node *root,int data,int& lvl)
{
    if(root)
    {
        if(root->data == data)
            return 1;
        bool isInLeft = getLevel(root->left,data,lvl);
        bool isInRight = getLevel(root->right,data,lvl);
        if(isInLeft || isInRight)
        {
            lvl++;
            return 1;
        }
    }
    return 0;
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

int main()
{
    string str;
    int data;
    getline(cin,str);
    cin>>data;
    Node *root = buildTree(str);
    // treeTraverse(root);
    cout<<endl;
    int lvl=1;
    int temp=getLevel(root,data,lvl);
    cout<<"Level of: "<<data<<" is:"<<lvl<<endl;;
    return 0;
}