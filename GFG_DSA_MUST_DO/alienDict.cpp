void dfs(stack<char> &topView, char node, map<char, set<char>> gph, map<char,bool> &vis) {
    vis[node] = true;
    for(auto it = gph[node].begin(); it != gph[node].end(); it++){
        if(!vis[*it]) dfs(topView,*it,gph,vis);
    }
    topView.push(node);
}
string topoSort(map<char, set<char>> gph, int v) {
    stack<char> topView;
    string res;
    map<char,bool> vis;
    for(auto it = gph.begin(); it != gph.end(); it++) vis[it->first] = false;
    for(auto it = gph.begin(); it != gph.end(); it++)
        if(!vis[it->first]) dfs(topView, it->first, gph, vis);
    while(!topView.empty()) {res.push_back(topView.top()); topView.pop();}
    // cout << res;
    return res;
}
string findOrder(string dict[], int n, int k) {
    map<char, set<char>> gph;
    for(int i = 0; i < n-1; i++){
        int limit = min(dict[i].size(),dict[i+1].size());
        for(int k = 0; k < limit; k++){
            if(dict[i][k] != dict[i+1][k]) {gph[dict[i][k]].insert(dict[i+1][k]); break;}
        }
    }
    // for(auto it = gph.begin(); it != gph.end(); it++){
    //     cout << it->first << " : ";
    //     for(auto it1 = gph[it->first].begin(); it1 != gph[it->first].end(); it1++){
    //         cout << *it1 << " ";
    //     }
    //     cout << "\n";
    // }
    return topoSort(gph, k);
}
