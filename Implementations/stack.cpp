#include<iostream>
#define MAX 10
using namespace std;

struct Stack{
    int arr[MAX];
    int top;

    Stack(){
        top = -1;
    }
};

bool isFull(Stack *st){
    if(st -> top == MAX - 1)
        return true;
    else
        return false;
}

bool isEmpty(Stack *st){
    if(st -> top == -1)
        return true;
    else
        return false;
}

void push(Stack *st, int data){
    if(isFull(st)){
        cout << "Stack Overflow" << endl;
        exit(1);
    }

    st -> top ++;
    st -> arr[st -> top] = data;
}

void pop(Stack *st){
    if(isEmpty(st)){
        cout << "Stack Underflow" << endl;
        exit(1);
    }

    st -> top --;
}

int top(Stack *st){
    if(isEmpty(st)){
        cout << "Stack Underflow" << endl;
        exit(1);
    }

    int data = st -> arr[st -> top];
    return data;
}


int main(){

    Stack *st = new Stack();

    for(int i = 0; i < 5; i ++)
        push(st, i + 1);

    while(!isEmpty(st)){
        cout << top(st) << " ";
        pop(st);
    }cout << endl;

    return 0;
}