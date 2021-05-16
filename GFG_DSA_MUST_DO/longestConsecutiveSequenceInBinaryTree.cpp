void lc(Node* node, int currentLength, int &ans, int prev){
    if(!node) return;
    if(node->data == prev+1){
        currentLength++;
        ans = max(ans, currentLength);
    }
    else{
        currentLength=1;
    }
    lc(node->left, currentLength, ans, node->data);
    lc(node->right, currentLength, ans, node->data);
}

int longestConsecutive(Node* root){
    int ans = 0;
    lc(root, 0, ans, root->data-1);
    if(ans==1) return -1;
    return ans;
}
