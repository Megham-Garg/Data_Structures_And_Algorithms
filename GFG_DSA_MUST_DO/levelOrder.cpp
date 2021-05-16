#include <iostream>
#include<queue>
using namespace std;
struct Node {
	char data;
	Node *left;
	Node *right;
};
void LevelOrder(Node* root)
{
    if(!root){return;}
    queue<Node*> q1;
    queue<char> q2;
    q1.push(root);
    while(!q1.empty())
    {
        Node* current = q1.front();
        q2.push(current->data);
        if(current->left)q1.push(current->left);
        if(current->right)q1.push(current->right);
        q1.pop();
    }
    while(!q2.empty())
    {
        cout<<q2.front()<<endl;
        q2.pop();
    }
}
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}
int main() {
	/*Code To Test the logic
	  Creating an example tree
	                    M
			   / \
			  B   Q
			 / \   \
			A   C   Z
        */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z'); 
	root = Insert(root,'A'); root = Insert(root,'C');
	LevelOrder(root);
}