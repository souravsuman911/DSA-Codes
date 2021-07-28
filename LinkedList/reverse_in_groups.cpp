struct node *reverse (struct node *head, int k)
{ 
    node *prev = NULL;
    node *curr = head;
    node *next;
    int count = 0;
    
    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count ++;
    }
    
    if(curr != NULL)
        head -> next = reverse(next, k);
        
    return prev;
}

// my good method
struct node *reverse (struct node *head, int k)
    { 
        node* p = head;
        node* t;
        node* temp; 
        
        while(p != NULL){
            
            node *h = p;
            int grp = k;
            
            while(grp -- && p != NULL)
                p = p -> next;
            
                
            t = p;
            if(h == head)
                head = revGroup(h, t);
            else
                temp -> next = revGroup(h, t);
            
            temp = h;  
        }
        
        return head;
    }

// my long structured method
int countList(node* head){
    node* p = head;
    int count = 0;
    while(p != NULL){
        count ++;
        p = p -> next;
    }
    
    return count;
}

node* returnTail(node* head, int k){
    node* p = head;
    while(k --)
        p = p -> next;
        
    return p;
}

node* reverseList(node* head, node* tail){
    node* prev = NULL;
    node* curr = head;
    node* next;
    
    while(curr != tail){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
struct node *reverse (struct node *head, int k)
{ 
    if(head == NULL)
        return NULL;
        
    node* fHead = NULL;
    int count = countList(head);
    if(k >= count)
        return reverseList(head, NULL);
    
    
    node* currHead = head;
    node* prevTail;
    node* nextHead;
    
    while(count > k){
        nextHead = returnTail(currHead, k);
        
        if(currHead == head){
            prevTail = head;
            fHead = reverseList(currHead, returnTail(currHead, k));
        }
        else{
            prevTail -> next = reverseList(currHead, returnTail(currHead, k));
            prevTail = currHead;
        }
        
        currHead = nextHead;
        count -= k;
    }
    prevTail -> next = reverseList(currHead, NULL);
    
    return fHead;
}