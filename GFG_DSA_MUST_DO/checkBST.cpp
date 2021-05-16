int inOrder(Node* root, int mn,int mx){
    if(!root) return 1;
    if(root->data < mn|| root->data > mx) return 0;
    return
        inOrder(root->left, mn, root->data-1)&&
        inOrder(root->right, root->data+1, mx);
}

bool isBST(Node* root) {
    return inOrder(root, INT_MIN, INT_MAX);
}
