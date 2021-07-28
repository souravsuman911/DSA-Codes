/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int countList(ListNode* head){
    ListNode* p = head;
    int count = 0;
    while(p != NULL){
        count ++;
        p = p -> next;
    }
    
    return count;
}
    
ListNode* returnTail(ListNode* head, int k){
    ListNode* p = head;
    while(k --)
        p = p -> next;
        
    return p;
}

ListNode* reverseList(ListNode* head, ListNode* tail){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next;
    
    while(curr != tail){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
ListNode* Solution::solve(ListNode* head, int k) {

    if(head == NULL)
        return NULL;
        
    ListNode* fHead = NULL;
    int count = countList(head);
    if(k >= count)
        return reverseList(head, NULL);
    
    
    ListNode* currHead = head;
    ListNode* prevTail;
    ListNode* nextHead;
    bool flag = true;
    
    while(count > k){
        if(flag == false){
            prevTail -> next = currHead;
            prevTail = returnTail(currHead, k - 1);
            currHead = prevTail -> next;
            flag = true;
            count -= k;
            continue;
        }

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
        flag = false;
    }
    
    if(flag == true)
        prevTail -> next = reverseList(currHead, NULL);
    else
        prevTail -> next = currHead;
    
    return fHead;
}
