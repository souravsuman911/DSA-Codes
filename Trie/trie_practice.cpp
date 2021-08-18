#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    vector<TrieNode*> child;
    bool isEnd;

    TrieNode(){
        isEnd = false;
        child.resize(26);
        for(auto it : child)
            it = NULL;

    }
};

void insertInTrie(TrieNode *root, string key){
    TrieNode *curr = root;
    for(int i = 0; i < key.size(); i ++){
        int index = key[i] - 'a';
        if(curr -> child[index] == NULL)
            curr -> child[index] = new TrieNode();
        curr = curr -> child[index];
    }
    curr -> isEnd = true;
}

bool searchInTrie(TrieNode *root, string key){
    TrieNode *curr = root;
    for(int i = 0; i < key.size(); i ++){
        int index = key[i] - 'a';
        if(curr -> child[index] == NULL)
            return false;
        curr = curr -> child[index];
    }

    return curr -> isEnd;
}

bool isEmpty(TrieNode *root){
    for(auto it : root -> child){
        if(it != NULL)
            return false;
    }

    return true;
}

TrieNode *deleteInTrie(TrieNode *root, string key, int i){
    if(root == NULL)
        return root;

    if(i == key.size()){
        root -> isEnd = false;
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }
        return root; 
    }

    int index = key[i] - 'a';
    root -> child[index] = deleteInTrie(root, key, i + 1);

    if(isEmpty(root) && root -> isEnd == false){
        delete(root);
        root = NULL;
    }

    return root;
}

int main(){

    vector<string> input = {"bad", "bat", "geek", "geeks", "cat", "cut", "zoo"};
    TrieNode *root = new TrieNode();

    for(auto it : input){
        insertInTrie(root, it);
    }

    vector<string> toSearch = {"bad", "geek", "gee", "cater", "geeks"};
    for(auto it : toSearch){
        cout << searchInTrie(root, it) << endl;
    }cout << endl;

    vector<string> toDelete = {"zoo", "geek"};
    for(auto it : toDelete){
        deleteInTrie(root, it, 0);
    }

    for(auto it : toSearch){
        cout << searchInTrie(root, it) << endl;
    }

    return 0;
}