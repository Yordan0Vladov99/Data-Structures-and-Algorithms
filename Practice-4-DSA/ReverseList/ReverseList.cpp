SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) 
{
    SinglyLinkedListNode* prev;
    SinglyLinkedListNode* curr;
    SinglyLinkedListNode* temp;
    
    prev=NULL;
    temp=head;
    curr=head;
    
    while(curr!=NULL)
    {
        temp=temp->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    return head;

}