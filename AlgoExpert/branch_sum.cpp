#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

vector<int> branch_sum(Node* root){
    vector<int> ans;
    preOrder(root, &ans, 0);
    return ans;
}

void preOrder(Node* node, vector<int>* arr, int sum){
    if(!node->left && !node->right){
        arr->push_back(sum+node->val);
        return;
    }
    if(node->left) preOrder(node->left, arr, sum+node->val);
    if(node->right) preOrder(node->right, arr, sum+node->val);
    return;
}

int main(){
    return 0;
}
// O(n) space for ans array
// O(logn) for stack space
// O(n) time