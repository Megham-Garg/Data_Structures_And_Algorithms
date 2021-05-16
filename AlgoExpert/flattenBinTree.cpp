#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    int data;
    Node(int d){
        left = NULL;
        right = NULL;
        data = d;
    }
};

Node* FTHelper(Node* cur, Node* prev){
    if(cur->left) prev = FTHelper(cur->left, prev);
    cur->left = prev;
    if(prev) prev->right = cur;
    prev = cur;
    if(cur->right) prev = FTHelper(cur->right, prev);
    return prev;
}

void flattenTree(Node* root){
    Node* n = FTHelper(root, NULL);
}

// O(n) time
// O(1) space
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    Node* a = root->left;
    a->left = new Node(4);
    a->right = new Node(5);
    a = a->right;
    a->left = new Node(7);
    a->right = new Node(8);
    a = root->right;
    a->left = new Node(6);
    
    flattenTree(root);
    Node* cur = root;
    while(cur && cur->left) cur = cur->left;
    root = cur;
    while(root){
        cout << root->data << " ";
        root = root->right;
    }
    return 0;
}