Node *reverseList(Node* head){
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node *compute(Node *head)
{
    head = reverseList(head);

    int maxm = INT_MIN;
    Node *curr = head, *next;
    Node *prev;
    
    while(curr != NULL){
        if(curr -> data >= maxm){
            maxm = curr -> data;
            prev = curr;
            curr = curr -> next;
        }
        else{
            next = curr -> next;
            prev -> next = curr -> next;
            curr = next;
        }
    }
    
    head = reverseList(head);
    
    return head;
}
