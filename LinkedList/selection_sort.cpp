node *i = head;
node *j;
node *minm;

while(i != NULL && i -> next != NULL){
    j = i -> next;
    minm = i;
    while(j != NULL){
        if(j -> data < minm -> data)
            minm = j;
        j = j -> next;
    }
    swap(i -> data, minm -> data);
    i = i -> next;
}