#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> grid, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << grid[i][j] << " ";
		cout << "\n";
	}
}
void bt(vector<vector<int>> &grid, int i, int j, int x, int y, int n, int m, int pathLength, int &ans){
	if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1 || grid[i][j] == 0) return;
    cout << "i: " << i << " j: " << j << " pathLength: " << pathLength << endl;
    printGrid(grid,n,m);
	if(i == x && j == y) {ans = min(ans,pathLength); return;}
	grid[i][j] = -1;
	bt(grid, i, j - 1, x, y, n, m, pathLength + 1, ans);
	bt(grid, i, j + 1, x, y, n, m, pathLength + 1, ans);
	bt(grid, i - 1, j, x, y, n, m, pathLength + 1, ans);
	bt(grid, i + 1, j, x, y, n, m, pathLength + 1, ans);
	grid[i][j] = 1;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
		int n,m,x,y; cin >> n >> m;
		vector<vector<int>> grid;
		for(int i = 0; i < n; i++){
            grid.push_back(vector<int>(m));
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		cin >> x >> y;
		int ans = INT_MAX;
		bt(grid, 0, 0, x, y, n, m, 0, ans);
		if(ans==INT_MAX) ans=-1;
		cout << ans << endl;
	}
	return 0;
}
