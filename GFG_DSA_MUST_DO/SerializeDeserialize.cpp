void serialize(Node *root,vector<int> &A){
    if(!root) return;
    queue<Node*> q; q.push(root);
    Node* dummy = new Node(0);
    while(!q.empty()){
        Node* cur = q.front(); q.pop();
        A.push_back(cur->data);
        if(cur->left) q.push(cur->left);
        else if(cur->data) q.push(dummy);
        if(cur->right) q.push(cur->right);
        else if(cur->data) q.push(dummy);
    }
    return;
}

Node * deSerialize(vector<int> &A)
{
    Node* root = new Node(A[0]);
    int cur = 0, ind = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        if(A[ind]==0) {ind++; continue;}
        Node *l,*r;
        if(A[2*cur+1]) l = new Node(A[2*cur+1]);
        else{l = NULL;}
        if(A[2*cur+2]) r = new Node(A[2*cur+2]);
        else{r = NULL;}
        Node* temp = q.front(); q.pop();
        temp->left = l;
        temp->right = r;
        if(l) q.push(l);
        if(r) q.push(r);
        cur++;
    }
    A.clear();
    return root;
}
