#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next = NULL;
};

void add(Node **head,Node **tail,int value)
{
    Node *temp = *head;
    Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    if(!temp)
    {
        *head = newNode;
    }
    else
    {
        (*tail)->next = newNode;
    }
    *tail = newNode;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int firstInLoop(Node *head)
{
    Node *checkNode = (struct Node*)malloc(sizeof(struct Node));
    Node *temp = head;
    Node *curr = head;
    while(curr)
    {
        if(curr->next == checkNode)
            return curr->data;
        temp = curr->next;
        curr->next = checkNode;
        curr = temp;
    }
    return -1;//means no loop
}

int main()
{
    int n = 7;
    // cin>>n;
    Node *head=NULL;
    Node *tail = NULL;
    for(int i=1;i<=n;i++)
    {
        add(&head,&tail,i);
    }
    print(head);
    int pos=-1;
    // cin>>pos;
    if(pos>0)
    {
        Node *temp = head;
        while(--pos && temp->next)
        {
            temp=temp->next;
        }
        tail->next = temp;
    }
    cout<<firstInLoop(head)<<endl;
    return 0;
}