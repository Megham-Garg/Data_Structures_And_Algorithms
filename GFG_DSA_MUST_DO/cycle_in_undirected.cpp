bool checkAllVis(bool vis[], int n){
    for(int i=0; i < n; i++){
        if(!vis[i]) return false;
    }
    return true;
}
int getFirstUnvis(bool vis[], int n){
    for(int i=0; i < n; i++){
        if(!vis[i]) return i;
    }
    return -1;
}
bool dfs(vector<int> g[], int n, bool vis[], int node, int parent){
    bool f = false;
    vis[node] = true;
    for(auto it = g[node].begin(); it!=g[node].end(); it++){
        if(!vis[*it]) f = dfs(g, n, vis, *it, node) || f;
        else if(*it!=parent) return true;
    }
    return f;
}
bool isCyclic(vector<int> g[], int n){
    bool f = false;
    bool vis[n];
    memset(vis, false, sizeof(vis));
    while(!checkAllVis(vis,n) && f == false){
        int y = getFirstUnvis(vis,n);
        int parent = -1;
        f = dfs(g, n, vis, y, parent);
    }
    return f;
}