int appropriate(const vector<int> ar,const bool vis[]){
    int minKey = -1, min = INT_MAX;
    for(int i = 0; i < ar.size(); i++){
        if(min >= ar[i] && vis[i] == false){
            min = ar[i];
            minKey = i;
        }
    }
    return minKey;
}
vector <int> dijkstra(vector<vector<int>> g, int src, int v){
    vector<int> ar;
    for(int i = 0; i < v; i++) ar.push_back(INT_MAX);
    bool vis[v] = {false};
    ar[src] = 0;
    while(1){
        int key = appropriate(ar,vis);
        if(key==-1) break;
        vis[key] = true;
        for(int i=0; i<g[key].size(); i++){
            if(g[key][i]!=0) ar[i] = min(g[key][i]+ar[key],ar[i]);
        }
    }
    return ar;
}
