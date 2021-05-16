#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int data;
};

// O(n) time
// O(1) space
Node* rearrange(Node* root, int k){
    if(!root || !root->next) return root;
    
    Node* kNode = root;
    Node* kPrev = kNode;
    while(kNode && kNode->data != k) {
        kPrev = kNode;
        kNode = kNode->next;
    }
    if(!kNode) return root;
        
    Node* cur = root;
    Node* prev = cur;
    Node* temp = cur;
    while(cur){
        if(cur->data < k){
            temp = cur->next;
            prev->next = cur->next;
            cur->next = kNode;
            if(kNode == kPrev){
                root = cur;
            }kPrev = cur;
            cur = temp;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
    return root;
}