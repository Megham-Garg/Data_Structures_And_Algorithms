void preOrder(Node* root, int ht[], int h){
    if(!ht[h]) cout << root->data << " ";
    if(root->left) preOrder(root->left,ht,h+1);
    if(root->right) preOrder(root->right,ht,h+1);
    ht[h] = 1;
}

// A wrapper over leftViewUtil()
void leftView(Node *root){
    if(!root) return;
    int ht[100]={0};
    preOrder(root, ht, 0);
}
