int utilHt(Node* root, int ht){
    if(!root) return 0;
    else return max(1+utilHt(root->left, ht+1),1+utilHt(root->right, ht+1));
}

int diameter(Node* root) {
    if(!root) return 0;
    int a = diameter(root->left);
    int b = diameter(root->right);
    int c = 1+utilHt(root->left, 0)+utilHt(root->right, 0);
    return max(max(a,b),c);
}
