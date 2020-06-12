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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *buildTournamentTree(int arr[],int n)
{
    int pos = 0;
    int i;
    int min,max;
    vector<Node*> v;
    for(int i=0;i<n;i++)
    {
        v.push_back(createNode(arr[i]));
    }
    i = 0;
    int count = 50;
    while(n>1 && i<n)
    {
        min = i;
        if((i+1) <n)
        {
            i++;
            if(v[i]->data < v[min]->data)
            {
                min = i;
            }
            Node *root = createNode(v[min]->data);
            root->left = v[i-1];
            root->right = v[i];
            i++;
            v[pos++] = root;
        }
        else
        {
            v[pos++] = v[i];
            i++;
        }
        if( (pos) == (n+1)/2)
        {
            for(int i=0;i<pos;i++)
                cout<<v[i]->data<<" ";
            cout<<endl;
            n=pos;
            pos=0;
            i=0;
        }
    }
    return v[0];
}

void levelOrder(Node* root)
{
  //Your code here
  queue<Node*> q;
  q.push(root);
  Node *curr;
  int count;
  while(!q.empty())
  {
      count = q.size();
    while(count--)
    {
        curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    cout<<endl;
  }
}

void getSecondMin(Node *root,int& sec_min,int min)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        return;
    cout<<"root is:"<<root->data<<endl;
    cout<<"left is:"<<root->left->data<<endl;
    cout<<"right is:"<<root->right->data<<endl;
    cout<<"second minimum is:"<<sec_min<<endl;
    if(root->right->data > root->data)
    {
        
        if(root->right->data < sec_min && (root->right->data != min) )
            sec_min = root->right->data;
        getSecondMin(root->left,sec_min,min);
    }
    else if(root->left->data > root->data)
    {
        if(root->left->data < sec_min && (root->left->data != min) )
            sec_min = root->left->data;
        getSecondMin(root->right,sec_min,min);
    }
}


int main()
 {
	//code
	int t,n;
	// cin>>t;
    t=1;
	while(t--)
	{
        int data;
        unordered_set<int> s;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>data;
            s.insert(data);
        }//findMinMin(arr,n);
        int arr[s.size()];
        int i=0;
        unordered_set<int>::iterator it;
        for(it = s.begin();it!=s.end();it++)
            arr[i++] = (*it);
        // Using Tournament Tree

        Node *root = NULL;
        int min = INT_MAX;
        int sec_min = INT_MAX;
        if(n>1)
        {
            root = buildTournamentTree(arr,s.size());
            min = root->data;
            getSecondMin(root,sec_min,min);
        }
        levelOrder(root);
        if(min==INT_MAX || sec_min==INT_MAX)
            cout<<"-1"<<endl;
        else
        {
            cout<<min<<" "<<sec_min<<endl;
        }
	}
	    return 0;
}
// 15
// 988 857 744 492 228 229 366 860 937 433 552 438 276 408 475

// 40
// 970 536 153 622 394 791 290 110 632 674 265 736 549 296 878 314 834 199 950 356 156 794 469 157 961 934 824 287 172 359 678 141 246 182 762 991 324 51 101 955

// 80
// 586 302 812 976 896 970 811 987 557 213 258 318 487 758 236 242 4 73 150 193 451 481 841 19 398 56 12 205 816 441 185 401 94 348 728 989 318 538 975 874 102 584 191 588 342 778 829 697 202 331 889 4 811 81 23 560 137 386 765 304 178 301 56 271 648 783 259 965 673 586 838 774 169 380 362 862 510 190 558 711