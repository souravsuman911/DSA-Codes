
listnode* insertionSortList(listnode* head) {
    if(head == NULL)
        return NULL;
    
    if(head -> next == NULL)
        return head;
 
    listnode* p = head;
    p = p -> next;
    listnode* prev = head;
    listnode* tprev;
    
 
    while(p != NULL){
        listnode* temp = p -> next;
        if(p -> val < prev -> val){
            listnode* start = head;
            while(start != p && p -> val > start -> val){
                tprev = start;
                start = start -> next;
            }
            if(start == head){
                prev -> next = p -> next;
                p -> next = head;
                head = p;
            }
            else{
                prev -> next = p -> next;
                p -> next = tprev -> next;
                tprev -> next = p;
            }
        }
        else
            prev = p;
        
        p = temp;
    }
 
    return head;
}