void preOrd(Node * root, int h, int &hmx){
    if(!root->left && !root->right) {hmx = max(h+1,hmx); return;}
    if(root->left) preOrd(root->left, h+1, hmx);
    if(root->right) preOrd(root->right, h+1, hmx);
}

int height(Node* root){
    if(!root) return 0;
    int h = 0; int hmx = 0;
    preOrd(root, h, hmx);
    return hmx;
}
