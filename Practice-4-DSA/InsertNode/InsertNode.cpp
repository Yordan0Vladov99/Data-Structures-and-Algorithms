SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int _data, int position) {

    SinglyLinkedListNode* pre;
    SinglyLinkedListNode* cur;
    SinglyLinkedListNode* temp=new SinglyLinkedListNode(_data);
    
    cur=head;
    for(int i=0;i<position;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    
    pre->next=temp;
    temp->next=cur;
    return head;
}