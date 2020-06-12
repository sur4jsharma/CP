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

int MultSumLeaves(Node *root)
{
    int mult = 1;
    int sum,count;
    queue<Node*> q;
    q.push(root);
    Node *curr;
    while(!q.empty())
    {
        count = q.size();
        sum = 0;
        while(count--)
        {
            curr = q.front();
            q.pop();
            if(!curr->left && !curr->right)
            {
                sum+=curr->data;
                // cout<<"sum is:"<<sum<<endl;
                // cout<<"leaf is: "<<curr->data<<endl;
            }
            else
            {
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }// all node of this level is explored
        if(sum)
            mult = mult * sum;
        // cout<<"product of sum is:"<<mult<<endl;
    }
    return mult;
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    // treeTraverse(root);
    cout<<endl;
    int sum = MultSumLeaves(root);
    cout<<"Product of sum of leaves at level is: "<<sum<<endl;
    return 0;
}

// 2 7 5 N N N 9