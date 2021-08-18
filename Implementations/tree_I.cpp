#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* createNode(int data){
    Node* newp = new Node();
    if(newp == NULL){
        cout << "Memory Error";
        exit(1);
    }

    newp -> data = data;
    newp -> left = NULL;
    newp -> right = NULL;

    return newp;
}

Node* insertNode(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp -> left != NULL)
            q.push(temp -> left);
        else{
            temp -> left = createNode(data);
            return root;
        }
        
        if(temp -> right != NULL)
            q.push(temp -> right);
        else{
            temp -> right = createNode(data);
            return root;
        }
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main(){

    Node* root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);

    cout << "Inorder traversal" << endl;
    inorder(root);
    cout << endl;

    root = insertNode(root, 4);

    cout << "Inorder traversal" << endl;
    inorder(root);
    cout << endl;

    return 0;
}