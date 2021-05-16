void preOrderUtil(Node* node, map<Node*, int> &mp, int hd){
    mp[node] = hd;
    if(node->left) preOrderUtil(node->left, mp, hd-1);
    if(node->right) preOrderUtil(node->right, mp, hd+1);
}

vector<int> verticalOrder(Node *root)
{
    if(!root) return vector<int>(0);
    vector<int> res;
    map<Node*, int> hdMP;
    preOrderUtil(root, hdMP, 0);
    queue<Node*> q; q.push(root);
    map<int, vector<int>> level;
    while(!q.empty()){
        level[hdMP[q.front()]].push_back(q.front()->data);
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right) q.push(q.front()->right);
        q.pop();
    }
    for(auto it=level.begin(); it!=level.end(); it++){
        for(auto ele:it->second) res.push_back(ele);
    }
    return res;
}
