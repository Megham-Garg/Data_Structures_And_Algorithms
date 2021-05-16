void htUtil(Node* root, int ht, map<Node*, int> &htMP){
    htMP[root] = ht;
    if(root->left) htUtil(root->left, ht+1, htMP);
    if(root->right) htUtil(root->right, ht+1, htMP);
}

void connect(Node *p){
    map<Node*, int> htMP; htUtil(p,0,htMP);
    queue<Node*> q; q.push(p);
    while(!q.empty()){
        Node* cur = q.front(); q.pop();
        if(q.empty()) cur->nextRight = NULL;
        else if(htMP[cur]!=htMP[q.front()]) cur->nextRight = NULL;
        else cur->nextRight = q.front();
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}
