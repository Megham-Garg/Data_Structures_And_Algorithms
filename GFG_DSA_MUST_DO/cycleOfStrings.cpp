#include<bits/stdc++.h>
using namespace std;
bool allVisited(bool f[], int n){
    for(int i = 0; i < n; i++) if(!f[i]) return false;
    return true;
}
bool useDfs(int n, int node, vector<int> adj[], bool vis[]){
    bool f = false;
    vis[node] = true;
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i){
        if (!vis[*i])
            f = useDfs(n, *i, adj, vis)||f;
        else if(allVisited(vis,n) && *i!=node) {f = true;}
    }
    vis[node] = false;
    return f;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    vector<pair<char,char>> vs;
	    for(int i = 0; i < n; i++){
	        string temp; cin >> temp;
	        vs.push_back(make_pair(temp[0],temp[temp.size()-1]));
	    }
        vector<int> graph[n];
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(vs[i].second == vs[j].first) graph[i].push_back(j);
	        }
	    }
	    bool vis[n] = {false};
	    int ans = useDfs(n,0,graph,vis);
	    if(n==1 && !graph[0].empty()) ans = 1;
	    cout << ans << "\n";
	}
	return 0;
}
/*
sample input
6
1
aa
1
abk
4
ab bc ca sk
3
ab bb aa
3
abc bcd cdf
4
ab bc cd da
*/
