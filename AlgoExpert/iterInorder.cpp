#include<bits/stdc++.h>
using namespace std;

void cb(int data){ cout << data << " ";}


// O(1) space
// O(n) time
void iterInorder(Node* root){
    Node* cur = root, prev = NULL;
    while (cur != NULL){
        if(cur->left && prev==cur->parent) {
            prev = cur;
            cur = cur->left;
            continue;
        }
        if(prev != cur->right) cb(cur->data);
        if(cur->right && prev != cur->right){
            prev = cur;
            cur = cur->right;
            continue;
        }
        prev = cur;
        cur = cur->parent;
    }   
}