#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BST{
    Node* root;
public:
    BST(int data){
        root = new Node;
        root->data = data;
        root->right = NULL;
        root->left = NULL;
    }
    void insert(int data){
        Node* cur = root;
        Node* node = new Node();
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        while (cur){
            if(cur->data > data && cur->left) cur = cur->left;
            else if(cur->data > data){
                cur->left = node;
                return;
            }
            else if(cur->data <= data && cur->right) cur = cur->right;
            else if(cur->data <= data){
                cur->right = node;
                return;
            }
        }
        return;
    }
    void remove(int data){
        Node* cur = root;
        Node* parent = cur;
        while (cur){
            if(cur->data > data && cur->left) {parent = cur; cur = cur->left;}
            else if(cur->data < data && cur->right) {parent = cur; cur = cur->right;}
            else if(cur->data = data) break;
            else {parent = NULL; break;}
        }
        if(parent == NULL) cout << "Node not present in BST\n";
        else{
            int minVal = INT_MAX;
            if(cur->left && !cur->right && parent==root) root = root->left;
            else if(cur->left && !cur->right){
                if(parent->left == cur) parent->left = cur->left;
                else parent->right = cur->left;
            }
            if(cur->right && !cur->left && parent==root) root = root->right;
            else if(cur->right && !cur->left){
                if(parent->left == cur) parent->left = cur->right;
                else parent->left = cur->right;
            }
            else if(cur->left && cur->right){
                if(!cur->right->left){
                    cur->data = cur->right->data;
                    cur->right = NULL;
                }
                else{
                    Node* mn = cur->right;
                    while(mn->left && mn->left->left){mn = mn->left;}
                    cur->data = mn->left->data;
                    if(!mn->left->right) mn->left = NULL;
                    else{
                        mn->left = mn->left->right;
                    }
                }
            }
            else{
                if(parent->left == cur) parent->left = NULL;
                else parent->right = NULL;
            }
        }
        return;
    }
    // O(log(n)) time
    // O(1) space
    bool search(int target){
        Node* cur = root;
        while(cur){
            if(cur->data == target) return true;
            else if(cur->data > target && cur->left) cur = cur->left;
            else if(cur->data < target && cur->right) cur = cur->right;
            else break;
        }
        return false;
    }
    Node* getRoot() {return root;}
};

// O(n) time
// O(depth) space call stack
bool validateBST(Node* cur, int l, int r){
    if(cur->data < l || cur->data > r) return false;
    bool res = true;
    if(cur->left) res = validateBST(cur->left, l, cur->data-1);
    if(cur->right) res = res && validateBST(cur->right, cur->data, r);
    return res;
}

int main(){
    BST b1(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(2);
    b1.insert(5);
    b1.insert(13);
    b1.insert(1);
    b1.insert(14);
    b1.insert(22);
    cout << validateBST(b1.getRoot(), -2, 500) << "\n";
    return 0;
}