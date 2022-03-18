SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {

    if(head->next==NULL)
    {
        return head;
    }
    SinglyLinkedListNode *curr;
    SinglyLinkedListNode *prev;
    curr=head;
   if(position==0)
    {
        head=head->next;
        return head;
    }
    for(int i=1;i<=position;i++)
    {
        prev=curr;
        curr=curr->next;
        if(curr->next==NULL)
        {
return head;
        }
    }
    prev->next=curr->next;
return head;
}