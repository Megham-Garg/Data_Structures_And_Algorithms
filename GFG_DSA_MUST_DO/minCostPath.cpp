#include<bits/stdc++.h>
using namespace std;
int dijkstra(vector<vector<int>> grid, int n){
    vector<vector<int>> wt;
    queue<pair<int,int>> ind;
    for(int i = 0; i < n; i++){
        wt.push_back(vector<int>(n));
		for(int j = 0; j < n; j++){
			wt[i][j] = INT_MAX;
		}
	}
	wt[0][0] = grid[0][0];
	ind.push(make_pair(0,0));
    while(!ind.empty()){
        int i = ind.front().first;
        int j = ind.front().second;
        ind.pop();
        if(i+1 > -1 && i+1 < n && j > -1 && j < n && wt[i+1][j] > grid[i+1][j]+wt[i][j]) {ind.push(make_pair(i+1,j)); wt[i+1][j] = grid[i+1][j]+wt[i][j];}
        if(i-1 > -1 && i-1 < n && j > -1 && j < n && wt[i-1][j] > grid[i-1][j]+wt[i][j]) {ind.push(make_pair(i-1,j)); wt[i-1][j] = grid[i-1][j]+wt[i][j];}
        if(i > -1 && i < n && j+1 > -1 && j+1 < n && wt[i][j+1] > grid[i][j+1]+wt[i][j]) {ind.push(make_pair(i,j+1)); wt[i][j+1] = grid[i][j+1]+wt[i][j];}
        if(i > -1 && i < n && j-1 > -1 && j-1 < n && wt[i][j-1] > grid[i][j-1]+wt[i][j]) {ind.push(make_pair(i,j-1)); wt[i][j-1] = grid[i][j-1]+wt[i][j];}
    }
    return wt[n-1][n-1];
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
		int n; cin >> n;
		vector<vector<int>> grid;
		for(int i = 0; i < n; i++){
            grid.push_back(vector<int>(n));
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		int ans = dijkstra(grid, n);
		cout << ans << endl;
	}
	return 0;
}
//sample input
/*
1
5
31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
2
42 93 7 14
*/
