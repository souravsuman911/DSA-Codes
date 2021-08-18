#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;

    Node(int data){
        this -> data = data;
        prev = NULL;
        next = NULL;
    }
};

Node* insertAtHead(Node *head, int data){
    Node *newp = new Node(data);
    if(newp == NULL){
        cout << "Memory Unavailable" << endl;
        exit(1);
    }

    if(head == NULL){
        head = newp;
        return head;
    }
    else{
        head -> prev = newp;
        newp -> next = head;
        head = newp;
        return head;
    }
}

void traverse(Node *head){
    if(head == NULL){
        cout << "List is Empty" << endl;
        return;
    }

    Node *curr = head;
    while(curr != NULL){
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}


int main(){

    Node *head = NULL;

    for(int i = 0; i < 10; i ++){
        head = insertAtHead(head, i + 1);
    }

    traverse(head);



    return 0;
}