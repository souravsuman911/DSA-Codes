#include<iostream>
#define MAX 10
using namespace std;

struct Queue{
    int arr[MAX];
    int front;
    int rear;

    Queue(){
        front = -1;
        rear = -1;
    }
};

bool isFull(Queue *q){
    if(q -> rear == MAX - 1)
        return true;
    else
        return false;
}

bool isEmpty(Queue *q){
    if(q -> front == -1)
        return true;
    else
        return false;
}

void push(Queue *q, int data){
    if(isFull(q)){
        cout << "Queue Overflow" << endl;
        return;
    }

    q -> rear ++;
    q -> arr[q -> rear] = data;

    if(q -> front == -1)
        q -> front = 0;
}

void pop(Queue *q){
    if(isEmpty(q)){
        cout << "Queue Underflow" << endl;
        return;
    }

    if(q -> front == q -> rear){
        q -> front = -1;
        q -> rear = -1;
    }
    else
        q -> front ++;
}

int front(Queue *q){
    if(q -> front == -1){
        cout << "Queue is Empty" << endl;
        exit(1);
    }

    return q -> arr[q -> front];
}

int rear(Queue *q){
    if(q -> rear == -1){
        cout << "Queue is Empty" << endl;
        exit(1);
    }   

    return q -> arr[q -> rear];
}



int main(){

    Queue *q = new Queue();

    for(int i = 0; i < 5; i ++)
        push(q, i + 1);
    
    while(!isEmpty(q)){
        cout << front(q) << " " << rear(q) << endl;
        pop(q);
    }

    push(q, 7);
    cout << front(q) << endl;
    pop(q);
    cout << rear(q) << endl;
    push(q, 7);
    cout << front(q) << endl;
    pop(q);



    return 0;
}