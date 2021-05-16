void insertNode(Node* root, int data){
    Node *cur = root;
    while(cur){
        if(cur->data >= data || cur->bottom==NULL) break;
        cur = cur->bottom;
    }
    if(cur->bottom==NULL && cur->data <= data){
        Node * n = new Node(data);
        cur->bottom = n; return;
    }
    Node * n = new Node(cur->data);
    cur->data = data;
    n->bottom = cur->bottom;
    cur->bottom = n;
}
Node *flatten(Node *root){
    Node* cn; // current next LL
    if(!root->next) return root;
    cn = flatten(root->next); root->next = NULL;
    while(cn){
        insertNode(root, cn->data);
        Node * temp = cn; 
        cn = cn->bottom;
        delete temp; 
    }
    return root;
}
