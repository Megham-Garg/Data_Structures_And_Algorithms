bool rec(Node* a, Node* b){
    if(a && !b || !a && b) return 0;
    else if(!a && !b) return 1;
    else return (a->data == b->data)&&rec(a->right, b->left)&&rec(a->left, b->right);
}

bool isSymmetric(struct Node* root){
    if(!root) return true;
    return rec(root->left, root->right);
}
