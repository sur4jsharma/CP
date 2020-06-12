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

void treeTraverse(Node *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
}

int getHeight(Node *root,int& dmtr)
{
    if(root)
    {
        cout<<"root is:"<<root->data<<endl;
        int hl=getHeight(root->left,dmtr);
        int hr=getHeight(root->right,dmtr);
        cout<<"current diameter is:"<<(hl+hr)<<endl;
        dmtr = max(dmtr,(hl+hr));
        cout<<"Diameter is:"<<dmtr<<endl;
        return 1+max(hl,hr);
    }
    return 0;
}

int getDiameter(Node *root)
{
    int dmtr = 0;
    int height = getHeight(root,dmtr);
    return dmtr+1;
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    treeTraverse(root);
    cout<<endl;
    cout<<"Diametr of Tree is: "<<getDiameter(root)<<endl;;
    return 0;
}