#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

// O(log(n)) time
// O(log(n)) space
int findClosestInBSTRec(Node* node, int target){
    if(!node) return INT_MAX;
    if(node->data == target) return target;
    Node* next = NULL;

    if(node->left && node->data > target) next = node->left;
    else if(node->right && node->data < target) next = node->right;
    else return node->data;
    
    int fut = findClosestInBST(next, target);
    return (abs(node->data - target) < abs(fut - target))?node->data:fut;
}

// O(log(n)) time
// O(1) space
int findClosestInBSTIter(Node* node, int target){
    int res = INT_MAX;
    while(node){
        if(node->data == target) return node->data;
        else if(abs(node->data-target) < abs(res-target)) res = node->data;
        
        if(node->left && node->data > target) node = node->left;
        else if(node->right && node->data < target) node = node->right;
    }
    return res;
}

int main(){
    return 0;
}