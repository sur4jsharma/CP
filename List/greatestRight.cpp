#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next = NULL;
    struct Node *arbit = NULL;
};

void add(Node **head,Node **tail,int x)
{
    //head will contain 0x1000
    Node *temp = *head;//let address of temp is 0x600 then 0x600 contain is equal to content of 0x1000 i.e 0x0 initially
    Node *newNode = (Node *)malloc(sizeof(Node));// let newNode address is 0x500
    newNode->data = x;
    if(!temp)
    {
        *head = newNode;//now content of 0x1000 will changed from 0x0 to 0x500 for first time.
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


Node *reverseList(Node *head)
{
    Node *newHead;
    if(!head || !head->next)
    {
        return head;   
    }
    newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void printUpdated(Node *head)
{
    Node *temp = head;
    while(temp)
    {
        if(temp->arbit)
            printf("%d ",temp->arbit->data);
        temp=temp->next;
    }
    printf("\n");
}

Node *greatestNodeOnRight(Node *head)
{
    int maxSoFar = INT_MIN;
    Node *revHead = reverseList(head);
    Node *temp = revHead;
    Node *maxNodePtr = NULL;
    while(temp)
    {
        temp->arbit = maxNodePtr;
        if(temp->data > maxSoFar)
        {
            maxSoFar = temp->data;
            maxNodePtr = temp;
        }
        temp = temp->next;
    }
    return reverseList(revHead);
}

void arbitPtrToGreatest(Node *head)
{
    static Node *maxNode;
    if(!head)
    {return;}
    else if(!head->next)
    {
        head->arbit=NULL;
        maxNode = head;
        return;
    }
    else
    {
        arbitPtrToGreatest(head->next);
        head->arbit=maxNode;
        if(head->data > maxNode->data)
            maxNode = head;
    }
}

int main()
{
    int n;
    cin>>n;
    int value;
    Node *head=NULL;// let address of head is 0x1000 hence 0x1000 will contain NULL i.e 0x0
    Node *tail = NULL;
    for(int i=1;i<=n;i++)
    {
        cin>>value;
        add(&head,&tail,value);
    }
    print(head);
    // printUpdated(greatestNodeOnRight(head));
    arbitPtrToGreatest(head);
    printUpdated(head);
    return 0;
}