#include <bits/stdc++.h>
using namespace std;

void dfs(map<char, vector<char>> adList, map<char, bool> &ver, char node){
    cout << node << " \n";
    ver[node] = true;
    for(auto it = adList[node].begin(); it!=adList[node].end(); it++){
        if(!ver[*it]) dfs(adList, ver, *it);
    }
}

int main(){
    map<char, vector<char>> adList; // adjacency list for graph
    map<char, bool> ver;            // vertices present in graph and their visited status
    int e;  cin >> e;                         // number of edges
    char start_node;
    for(int i = 0; i < e; i++){
        char u,v; cin >> u >> v;
        if(i==0) start_node = u;
        if(ver.find(u) == ver.end()) ver[u] = false;
        if(ver.find(v) == ver.end()) ver[v] = false;
        if(adList.find(u) == adList.end()) {vector<char> adj; adj.push_back(v); adList[u] = adj;}
        else adList[u].push_back(v);
    }
    // for(auto it = adList.begin(); it!= adList.end(); it++){
    //     cout << it->first << " : ";
    //     for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++) cout << *it2 << " ";
    //     cout << endl;
    // }
    dfs(adList, ver, start_node);
    return 0;
}
