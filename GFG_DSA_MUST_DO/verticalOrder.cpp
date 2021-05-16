#include <iostream>
#include<queue>
#include<map>
using namespace std;
struct Node {
	char data;
	Node *left;
	Node *right;
};
void verticalOrder(Node* root)
{
    if(!root) return;
    map<char,int> m;
    queue<Node*> q;
    int hd=0;
    q.push(root);
    m[root->data]=0;
    while(!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        hd = m[cur->data];
        if(cur->left){
            m[cur->left->data]=hd-1;
            q.push(cur->left);
        }
        if(cur->right){
            m[cur->right->data]=hd+1;
            q.push(cur->right);
        }
    }
    for (map<char,int>::iterator it=m.begin(); it!=m.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    cout << endl; 
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
	//Print Nodes in Level Order. 
	verticalOrder(root);
}