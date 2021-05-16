#include<bits/stdc++.h>
using namespace std;

int dfs(const vector<vector<int>>& arr, vector<vector<bool>>& visited, int i, int j, int n, int m){
    int len = 1;
    visited[i][j] = 1;
    if(j+1 < m && arr[i][j+1] && !visited[i][j+1]) len+= dfs(arr, visited, i, j+1, n ,m);
    if(i+1 < n && arr[i+1][j] && !visited[i+1][j]) len+= dfs(arr, visited, i+1, j, n ,m);
    if(j-1 > -1 && arr[i][j-1] && !visited[i][j-1]) len+= dfs(arr, visited, i, j-1, n ,m);
    if(i-1 > -1 && arr[i-1][j] && !visited[i-1][j]) len+= dfs(arr, visited, i-1, j, n ,m);
    return len;
}

vector<int> riverSizes(const vector<vector<int>> arr){
    vector<int> res;
    int n = arr.size(), m = arr[0].size();
    if(!n || !m) return res;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!arr[i][j] || visited[i][j]) continue;
            else res.push_back(dfs(arr, visited, i, j, n, m));
        }
    }
    return res;
}

int main(){
    vector<vector<int>> arr;
    arr.push_back({1,0,0,1,0}); 
    arr.push_back({1,1,1,0,0}); 
    arr.push_back({0,0,1,0,1}); 
    arr.push_back({1,0,1,0,1});
    arr.push_back({1,0,1,1,0});
    vector<int> res = riverSizes(arr);
    for(auto len : res) cout << len << " ";
    cout << "\n";
    return 0;
}
//O(n*m) space
//O(n*m) time