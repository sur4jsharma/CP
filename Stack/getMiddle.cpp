#include<bits/stdc++.h>
using namespace std;

// to move the middle element both direction doublel linked list is required

class Node
{
    public:
        int data;
        Node *prev = NULL;
        Node *next = NULL;
};

class Stack
{
    public:
        Node *top;
        Node *mid;
        int size;
};

Stack *createStack()
{
    Stack *s = new Stack();
    s->size = 0;
    s->mid = NULL;
    s->top = NULL;
    return s;
}

void push(Stack *s,int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    if(s->top)
    {
        s->top->prev = newNode;
    }
    newNode->next = s->top;
    s->top=newNode;
    s->size++;
    // cout<<"size is:"<<s->size<<endl;
    if(!s->mid)
        s->mid = s->top;
    else if(s->size%2 == 1)
        s->mid = s->mid->prev;

}
int pop(Stack *s)
{
    Node *temp = s->top;
    s->top = s->top->next;
    int value = temp->data;
    free(temp);
    s->size--;
    if(s->size % 2 == 0)
        s->mid = s->mid->next;
    return value;
}

int getMid(Stack *s)
{
    return s->mid->data;
}

void deleteMidle(Stack *s)
{
    Node *beforeMid = s->mid->next;
    Node *afterMid = s->mid->prev;
    beforeMid->prev = afterMid;
    afterMid->next = beforeMid;
    Node *temp = s->mid;
    if(s->size % 2 == 0)
        s->mid = afterMid;
    else
        s->mid = beforeMid;
    s->size--;
}

int main()
{
    Stack *s = createStack();
    push(s, 11);
    push(s, 22);
    push(s, 33);
    push(s, 44);
    push(s, 55);
    push(s, 66);
    push(s, 77);
    push(s,88);
    push(s,99);
    push(s,100);
    // int n,value;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>value;
    //     push(s,value);
    // }
    // cout<<pop(s)<<endl;
    // cout<<pop(s)<<endl;
    // cout<<pop(s)<<endl;
    cout<<"middle element is: "<<getMid(s)<<endl;
    cout<<"deleted element is: "<<pop(s)<<endl;
    cout<<"deleted element is: "<<pop(s)<<endl;
    cout<<"middle element is: "<<getMid(s)<<endl;
    deleteMidle(s);
    cout<<"middle element after deletion of mid is: "<<getMid(s)<<endl;
    return 0;
}