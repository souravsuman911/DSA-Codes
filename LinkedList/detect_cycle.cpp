bool detectLoop(Node* head)
{
    if(head == NULL)
        return false;
    
    Node *h = head -> next;
    Node *t = head;
    
    while(h != t){
        if(h == NULL || h -> next == NULL)
            return false;
            
        h = h -> next -> next;
        t = t -> next;
    }
    
    return true;
}