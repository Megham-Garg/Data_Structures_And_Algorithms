int traverse(Node* root, int &ans){
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    int lsum = traverse(root->left, ans);
    int rsum = traverse(root->right, ans);
    if(root->left && root->right) ans = max(ans,lsum+rsum+root->data);
    if(root->left && !root->right) return lsum+root->data;
    if(root->right && !root->left) return rsum+root->data;
    if(root->left && root->right) return max(lsum+root->data, rsum+root->data);
}

int maxPathSum(Node* root){
    if(!root) return 0;
    int ans = INT_MIN;
    traverse(root, ans);
    return ans;
}
