#include <iostream>
#include<queue>
#include<map>
using namespace std;
struct Node {
	char data;
	Node *left;
	Node *right;
};
void topView(Node* root)
{
    if(!root) return;
    map<char,int> m;
    map<int,char> n;
    queue<Node*> q;
    int hd=0;
    q.push(root);
    m[root->data]=0;
    n[0]=root->data;
    while(!q.empty())
    {
        hd = m[root->data];
        if(root->left){
            m[root->left->data]=hd-1;
            if(n.count(hd-1)==0) n[hd-1]=root->left->data;
            q.push(root->left);
        }
        if(root->right){
            m[root->right->data]=hd+1;
            if(n.count(hd+1)==0) n[hd+1]=root->right->data;
            q.push(root->right);
        }
        q.pop();
        root=q.front();
    }
    
    for (map<int,char>::iterator it=n.begin(); it!=n.end(); ++it)
        cout << it->second << ' ';
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