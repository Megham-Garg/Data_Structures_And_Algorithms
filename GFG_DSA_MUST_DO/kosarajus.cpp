#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], bool vis[], stack<int> &ft, int node, int pass){
    if(vis[node]) return;
    vis[node] = true;
    for(auto it = adj[node].begin(); it != adj[node].end(); it++)
        if(!vis[*it]) dfsFT(adj, vis, ft, *it, pass);
    if(pass == 1) ft.push(node);
}
int anyUnvisited(bool vis[], int v){
    for(int i = 0; i < v; i++) if(!vis[i]) return i;
    return -1;
}
int kosaraju(int v, vector<int> adj[]){
    bool vis[v] = {false};
    stack<int> ft; // finish time
    while(anyUnvisited(vis, v) != -1){
        dfs(adj, vis, ft, anyUnvisited(vis, v), 1);
    }
	vector<int> revAdj[v];
    for(int i = 0; i < v; i++){
        for(auto it = adj[i].begin(); it != adj[i].end(); it++){
            revAdj[*it].push_back(i);
        }
    }
    vis[v] = {false};
    int ans = 0;
    while(!ft.empty()){
        if(!vis[ft.top()]){
            ans++;
            dfs(revAdj, vis, ft, ft.top(), 2);
        }
        ft.pop();
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<int> adj[n];
        while(m--){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << kosaraju(n,adj) << endl;
    }
    return 0;
}
