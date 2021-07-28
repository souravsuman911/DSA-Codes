// iterative
struct Node* reverseList(struct Node *head)
{
    if(head == NULL)
        return head;
    
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next;
    
    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// recursive
struct Node* reverseList(struct Node *head)
{
    if(head == NULL ||  head -> next == NULL)
        return head;
        
    struct Node *rest = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
    return rest;
}