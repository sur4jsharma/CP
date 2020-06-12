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
  
int countNodes(Node *root)
{
    if(root)
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    return 0;
}
 
int checkEqualHalf(Node *root,int edges,int& flag)
{
    if(!root)
        return 0;
    int lc = checkEqualHalf(root->left,edges,flag);
    int rc = checkEqualHalf(root->right,edges,flag);
    // cout<<"root is:"<<root->data<<endl;
    // cout<<"nodes in left is:"<<lc<<endl;
    // cout<<"nodes in right is:"<<rc<<endl;
    if( (lc + rc) == (edges -1)/2 )
        flag = 1;
    return lc+rc+1;
}

int solve(Node* root)
{
    int edges = countNodes(root) - 1;
    cout<<"total edges is:"<<edges<<endl;
    if(edges%2 == 0)
        return 0;
    int flag = 0;
    checkEqualHalf(root,edges,flag);
    return flag;
}

int main()
{
    string str;
    getline(cin,str);
    Node *root = buildTree(str);
    // treeTraverse(root);
    cout<<endl;
    bool ispartitioned = solve(root);
    cout<<"is tree can be partitioned:"<<ispartitioned<<endl;
    return 0;
}

// 25 1 7 -6 -9 5 -3 -4 -3 9 9 -9 3 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 5 10 10 N N 2 3
// 5 1 6 3 N 7 4