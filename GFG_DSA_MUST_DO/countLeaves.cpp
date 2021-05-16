int counLeaf(Node* root, int &count){
    if(!root->left && !root->right) count++;
    if(root->left) counLeaf(root->left, count);
    if(root->right) counLeaf(root->right, count);
}
int countLeaves(Node* root)
{
    int a = 0;
    counLeaf(root, a); return a;
}
