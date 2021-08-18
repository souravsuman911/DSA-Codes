#include<iostream>
#define MAX 10
using namespace std;

struct CQueue{
    int arr[MAX];
    int front;
    int rear;

    CQueue(){
        front = -1;
        rear = -1;
    }
};

bool isFull(CQueue *q){
    if(q -> front == 0 && q -> rear == MAX - 1 || q -> front == q -> rear - 1)
        return true;
    else
        return false;
}

bool isEmpty(CQueue *q){
    if(q -> front == -1)
        return true;
    else
        return false;
}

void push(CQueue *q, int data){
    if(isFull(q)){
        cout << "CQueue Overflow" << endl;
        return;
    }

    if(q -> rear == MAX - 1)
        q -> rear = 0;
    else   
        q -> rear ++;

    q -> arr[q -> rear] = data;

    if(q -> front == -1)
        q -> front = 0;
}

void pop(CQueue *q){
    if(isEmpty(q)){
        cout << "CQueue Underflow" << endl;
        return;
    }

    if(q -> front == q -> rear){
        q -> front = -1;
        q -> rear = -1;
    }
    else if(q -> front == MAX - 1)
        q -> front = 0;
    else
        q -> front ++;
}

int main(){

    return 0;
}