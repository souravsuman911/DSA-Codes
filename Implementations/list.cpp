#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int data){
        this -> data = data;
        next = NULL; 
    }
};

Node *insertAtHead(Node *head, int data){
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
        newp -> next = head;
        head = newp;
        return head;
    }
}

Node *insertAtEnd(Node *head, int data){
    Node *newp = new Node(data);

    if(newp == NULL){
        cout << "Memory Unavilable" << endl;
        exit(1);
    }

    if(head == NULL){
        head = newp;
        return head;
    }
    else{
        Node *curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }

        curr -> next = newp;
        return head;
    }
}

Node *deleteAfterGiven(Node *head, int data){
    if(head == NULL){
        cout << "List is Empty" << endl;
        return head; 
    }

    Node *curr = head;
    while(curr != NULL && curr -> data != data)
        curr = curr -> next;

    if(curr == NULL){
        cout << "DataItem not Found" << endl;
        return head;
    }
    else{
        Node *temp = curr -> next;
        if(curr -> next != NULL)
            curr -> next = curr -> next -> next;
        else
            curr -> next = NULL;

        delete(temp);
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

    for(int i = 10; i < 20; i ++){
        head = insertAtEnd(head, i + 1);
    }

    traverse(head);

    deleteAfterGiven(head, 10);

    traverse(head);

    return 0;
}