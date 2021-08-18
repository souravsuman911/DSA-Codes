#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int data){
    Node *newp = new Node(data);
    if(root == NULL){
        root = newp;
        return root;
    }

    queue<Node*> q;
    q.push(root);
    

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        if(temp -> left == NULL){
            temp -> left = newp;
            return root;
        }
        else{
            q.push(temp -> left);
        }

        if(temp -> right == NULL){
            temp -> right = newp;
            return root;
        }
        else{
            q.push(temp -> right);
        }
    }

    return root;
}

void inorder(Node *root){
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main(){

    Node *root = NULL;

    for(int i = 0; i < 10; i ++){
        root = insert(root, i + 1);
    }

    inorder(root);
    cout << endl;

    return 0;
}