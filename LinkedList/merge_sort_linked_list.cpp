Node *findMid(Node* head){
    if(head == NULL || head -> next == NULL)
        return head;
        
    Node *slow = head;
    Node *fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    return slow;
}

Node* merge(Node *head1, Node *head2){
    Node *merged = new Node(-1);
    Node *temp = merged;
    
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data < head2 -> data){
            temp -> next = head1;
            head1 = head1 -> next;
        }
        else{
            temp -> next = head2;
            head2 = head2 -> next;
        }
        temp = temp -> next;
    }
    
    while(head1 != NULL){
        temp -> next = head1;
        head1 = head1 -> next;
        temp = temp -> next;
    }
    
    while(head2 != NULL){
        temp -> next = head2;
        head2 = head2 -> next;
        temp = temp -> next;
    }
    
    return merged -> next;
}

Node* mergeSort(Node* head) {
    if(head -> next == NULL )
        return head;
        
    Node *mid = findMid(head);
    
    Node *head2 = mid -> next;
    mid -> next = NULL;
    
    Node *new_head1 = mergeSort(head);
    Node *new_head2 = mergeSort(head2);
    
    Node *final_head = merge(new_head1, new_head2);
    
    return final_head;
}