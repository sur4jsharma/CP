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
        //cout<<"current root is:"<<currRoot->data<<endl;

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

void printExtremeNodes(Node* root)
{
    // Your code here
    deque<Node*> dq;
    int data;
    Node *curr;
    dq.push_back(root);
    int count = 0;
    int level = 1;
    while(!dq.empty())
    {
        count = dq.size();
        // cout<<"size of deque is:"<<count<<endl;
        // cout<<"level is:"<<level<<endl;
        if(level % 2 == 0)// current level odd so rightmost
        {
            while(count--)
            {
                // cout<<"rightmost"<<endl;
                curr = dq.front();
                // cout<<"curr is:"<<curr->data<<" and size is:"<<dq.size()<<endl;
                dq.pop_front();
                if(curr->left)
                    dq.push_back(curr->left);
                if(curr->right)
                    dq.push_back(curr->right);
                cout<<curr->data<<" ";
            }
        }
        else// current level is even so leftmost;
        {
            while(count--)
            {
                // cout<<"leftmost"<<endl;
                curr = dq.back();
                // cout<<"current is:"<<curr->data<<" and size is:"<<dq.size()<<endl;
                dq.pop_back();
                if(curr->right)
                    dq.push_front(curr->right);
                if(curr->left)
                    dq.push_front(curr->left);
                cout<<curr->data<<" ";
            }   
        }
        level++;
        // cout<<"extream found"<<endl;
        // cout<<curr->data<<endl;
    }   
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    //treeTraverse(root);
    cout<<endl;
    printExtremeNodes(root);
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31