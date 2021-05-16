int utilHt(Node* root, int ht){
    if(!root) return 0;
    else return max(1+utilHt(root->left, ht+1),1+utilHt(root->right, ht+1));
}
bool isBalanced(Node *root){
    if(!root) return true;
    bool f;
    f = (abs( utilHt(root->left, 0) - utilHt(root->right,0) ) <= 1);
    f = f&&isBalanced(root->left);
    f = f&&isBalanced(root->right);
    return f;
}
