#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};


// O(n) Time
// O(log(n)) space
pair<int, int> mps(Node* node){
    if(!node) return make_pair(INT_MIN,INT_MIN);

    pair<int,int> l,r;
    if(node->left) l = mps(node->left);
    if(node->right) r = mps(node->right);
    else if(!node->left) return make_pair(node->data, node->data);

    int MSB = max(node->data, node->data + max(l.first,r.first));
    int MST = max(node->data+l.first+r.first, MSB);
    
    return make_pair(MSB, max(MST, max(l.second, r.second)));
}