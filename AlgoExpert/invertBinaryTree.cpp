void invertBinTree(Node* node){
    if(node->left)  invertBinTree(node->left);
    if(node->right) invertBinTree(node->right);
    if(!(node->left && node->right)) return;
    else if(node->left && node->right){
        Node* temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
    else if(node->left){
        node->right = node->left;
        node->left = NULL;
    }
    else{
        node->left = node->right;
        node->right = NULL;
    }
}

// O(n) time
// O(depth) space