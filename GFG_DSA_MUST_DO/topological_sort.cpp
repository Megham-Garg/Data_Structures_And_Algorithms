void dfs(stack<int> &topView, int node, vector<int> adj[], bool vis[]) {
    vis[node] = true;
    for(auto it = adj[node].begin();it != adj[node].end();it++){
        if(!vis[*it]) dfs(topView,*it,adj,vis);
    }
    topView.push(node);
}

vector<int> topoSort(int v, vector<int> adj[]) {
    stack<int> topView;
    vector<int> res;
    bool vis[v] = {false};
    for(int i = 0; i < v; i++) if(!vis[i]) dfs(topView,i,adj,vis);
    while(!topView.empty()) {res.push_back(topView.top()); topView.pop();}
    return res;
}
