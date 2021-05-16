// below are the functions implementations of binary tree

void inorder(Node* root, vector<int> &v){
    if(root->left) inorder(root->left, v);
    v.push_back(root->data);
    if(root->right) inorder(root->right, v);
}
Node * bToDLL(Node *root)
{
    Node *temp, *dll;
    vector<int> v; inorder(root, v);
    for(ele : v){
        if(!dll) {dll = newNode(ele); temp = dll;}
        else{
            Node* next = newNode(ele);
            next->left = dll;
            dll->right = next;
            dll = next;
        }
    }
    return temp;
}
