Node *mergeList(Node* head1, Node* head2){
    Node *p1;
    Node *p2;
    Node *head;
    
    if(head1 -> data < head2 -> data){
        p1 = head1;
        p2 = head2;
        head = head1;
    }
    else{
        p1 = head2;
        p2 = head1;
        head = head2;
    }
    
    Node *next1, *next2;
    Node *prev;
    
    while(p1 != NULL && p2 != NULL){
        if(p1 -> data <= p2 -> data){
            prev = p1;
            p1 = p1 -> next;
        }
        else{
            next2 = p2 -> next;
            prev -> next = p2;
            prev = p2;
            p2 -> next = p1;
            p2 = next2;
        }
    }
    
    if(p2 != NULL)
        prev -> next = p2;
    
    return head;
}


Node * mergeKLists(Node *arr[], int k)
{
    if(k == 1)
        return arr[0];
        
    Node *head = NULL;
    head = mergeList(arr[0], arr[1]);

    for(int i = 2; i < k; i ++){
        head = mergeList(head, arr[i]);
    }

    return head;
        
}