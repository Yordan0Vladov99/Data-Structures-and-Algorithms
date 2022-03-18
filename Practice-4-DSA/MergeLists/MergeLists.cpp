SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedList New;
    SinglyLinkedListNode* cur1=head1;
    SinglyLinkedListNode* cur2=head2;
    while(cur1!=NULL&&cur2!=NULL)
    {
        if(cur1->data<cur2->data)
        {
            New.insert_node(cur1->data);
            cur1=cur1->next;
        }
        else
        {
            New.insert_node(cur2->data);
            cur2=cur2->next;
        }
    }
    while(cur1!=NULL)
    {
        
            New.insert_node(cur1->data);
            cur1=cur1->next;
        
    }
    while(cur2!=NULL)
    {
        
            New.insert_node(cur2->data);
            cur2=cur2->next;
        
    }
    return New.head;
}