/*

Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves, 
its value is equal to the sum of its left subtree's value and its right subtree's value. 
Else return 0.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. 
A leaf node is also considered a Sum Tree.


*/


int checkSum(Node* root, bool &flag){
    if(root == NULL || flag == false)
        return 0;
        
    if(root -> left == NULL && root -> right == NULL) 
        return root -> data;
        
    int val = checkSum(root -> left, flag) + checkSum(root -> right, flag);
    
    if(val != root -> data)
        flag = false;
        
    return root -> data + val;
}

bool isSumTree(Node* root)
{
    bool flag = true;
    checkSum(root, flag);
    
    return flag;
}