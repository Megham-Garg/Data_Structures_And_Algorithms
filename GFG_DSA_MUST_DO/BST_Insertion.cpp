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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

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

*/

    Node * insert(Node * root, int data) {
        if(root == NULL)return new Node(data);
        Node* cur = root;
        while(cur){
            if(cur->data > data){
                if(cur->left) cur=cur->left;
                else{
                    cur->left = new Node(data);
                    cur = NULL;
                }
            }
            else{
                if(cur->right) cur=cur->right;
                else{
                    cur->right = new Node(data);
                    cur = NULL;
                }
            }
        }
        return root;
    }

};