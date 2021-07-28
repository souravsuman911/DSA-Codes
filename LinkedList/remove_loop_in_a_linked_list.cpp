void removeLoop(Node* head)
{
    if(head == NULL || head -> next == NULL)
        return;
        
    Node *slow = head -> next;
    Node *fast = head -> next -> next;
    
    while(fast && fast -> next){
        if(slow == fast)
            break;
            
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    if(fast == slow){
        
        slow = head;
        
        // corner case => if head is the start point of the loop
        if(fast == head){
            while(slow -> next != head)
                slow = slow -> next;
                
            slow -> next = NULL;
            return;
        }
        ///////
        
        while(fast -> next != slow -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        
        fast -> next = NULL;
    }
    
}