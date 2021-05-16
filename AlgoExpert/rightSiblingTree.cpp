#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(depth) space
void helperRightSiblingTree(Node* cur, Node* parent){
    Node* temp = NULL;
    if(cur->right) temp = cur->right;

    if(parent){ 
        if(parent->left && cur == parent->left){
            cur->right = parent->right;
        }
        else if(parent->right){
            cur->right = parent->right->left;
        }
    }
    
    if(cur->left) helperRightSiblingTree(cur->left, cur);
    if(temp) helperRightSiblingTree(temp, cur);
    return;
}

void rightSiblingTree(Node* root){
    helperRightSiblingTree(root, NULL);
}