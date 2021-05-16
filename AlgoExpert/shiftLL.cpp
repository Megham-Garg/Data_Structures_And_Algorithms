#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// O(n) time
// O(1) space
Node* shiftLLP(int k, Node* root){
    if(!root || !root->next) return root;

    Node* tail = root;
    int n = 1;
    while(tail->next) {n++; tail = tail->next;}

    k%=n;

    if(!k) return root;
    else if(k<0) k+=n;
    
    k=n-k;
    Node* temp = root;
    
    while (k != 1) temp = temp->next;
    
    tail->next = root;
    root = temp->next;
    temp->next = NULL;
    return root;
}