#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* getSuccessor(Node* root){
    Node* curr = root -> right;
    while(curr != NULL && curr -> left != NULL)
        curr = curr -> left;
    return curr;
}

Node* getPredecessor(Node* root){
    Node* curr = root -> left;
    while(curr != NULL && curr -> right != NULL)
        curr = curr -> right;

    return curr;
}

Node* insertNode(Node* root, int item){
    Node* newp = new Node(item);

    if(root == NULL){
        root = newp;
        return root;
    }

    if(root -> data < item)
        root -> right = insertNode(root -> right, item);
    else
        root -> left = insertNode(root -> left, item);

    return root;
}

Node* deleteNode(Node* root, int item){
    if(root == NULL){
        cout << "tree is empty" << endl;
        return NULL;
    }

    if(root -> data < item)
        root -> right = deleteNode(root -> right, item);
    else if(root -> data > item)
        root -> left = deleteNode(root -> left, item);
    else{
        if(root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        else{
            Node* succ = getSuccessor(root);
            root -> data = succ -> data;
            root -> right = deleteNode(root -> right, succ -> data);
        }
    }

    return root;
}

void traversal(Node* root){
    if(root == NULL)
        return;

    traversal(root -> left);
    cout << root -> data << " ";
    traversal(root -> right);
}

int main(){

    struct Node* root = NULL;
    vector<int> arr;
    int item = 1;
    while(true){
        cin >> item;
        if(item == 0)
            break;
        arr.push_back(item);
    }
    
    for(int i = 0; i < arr.size(); i ++)
        root = insertNode(root, arr[i]);

    traversal(root);
    cout << endl;

    deleteNode(root, 4);

    traversal(root);
    cout << endl;

    return 0;
}

// 1 2 3 4 5 6 7 8 0
// 7 5 9 4 6 8 10 0
// 2 1 9 4 10 3 7 5 8 6 0