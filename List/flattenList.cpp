// to do

Node *flatten(Node *root)
{
   // Your code here
    Node *rootNext=NULL;
    Node *rootBottom;
    if(root)
    {
        rootNext = root->next;
        root->next=NULL;
    }
    rootBottom = root;
    Node *tempCurrRoot,*tempNextRoot;
    Node *tail=rootBottom;
    while(rootNext)
    {
      while(rootBottom && (rootBottom->data < rootNext->data) )
      {
          tail = rootBottom;
          rootBottom = rootBottom->bottom;
      }
        tempCurrRoot = tail->bottom;
        tail->bottom = rootNext;

        // if(tempCurrRoot)
        // {
        //     Node *temp = tempNextRoot;
        //     tempNextRoot = rootNext;
        //     while(tempNextRoot && tempNextRoot->data < tempCurrRoot->data)
        //     {
        //          //       cout<<"while tempNextRoot"<<endl;
        //         temp = tempNextRoot;
        //         tempNextRoot = tempNextRoot->bottom;
        //     }
        //     temp->bottom = tempCurrRoot;
        // }
        rootNext = rootNext->next;
        //tail->bottom->next = NULL;
   }
   return root;
}