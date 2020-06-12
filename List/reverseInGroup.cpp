struct node *reverseList(struct node *head)
{
    struct node *newHead;
    if(!head || !head->next)
    {
        return head;
    }
    newHead = reverseList(head->next);
    head->next->next = head;
    head->next=NULL;
    return newHead;
}
struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
     struct node *dummyNode = (struct node*)malloc(sizeof(struct node));
    struct node *tail = dummyNode;
    int count=0;
    struct node *curr = head;
    struct node *nextPtr=head;
    while(curr)
    {
        count++;
        nextPtr = curr->next;
        if(count==k || !curr->next)
        {
            curr->next=NULL;
            tail->next = reverseList(head);
            tail = head; 
            count = 0;
            head = nextPtr;
        }
        curr = nextPtr;


    }
    return dummyNode->next;


    }
    return dummyNode->next;
}
