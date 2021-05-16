#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    Node * lca(Node *root, int v1,int v2) {
        if(root==NULL) return NULL;
        if(root->data==v1 || root->data==v2) return root;
        Node * left = lca(root->left, v1, v2);
        Node * right = lca(root->right, v1, v2);
        if(left!=NULL && right!=NULL) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }

}; //End of Solution