#include<bits/stdc++.h>
using namespace std;

void bt(vector<vector<int>> &grid, int i, int j, int x, int y, int n, bool &ans){
	if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1 || grid[i][j] == 0) return;
	if(i == x && j == y) {ans = true; return;}
	grid[i][j] = -1;
	bt(grid, i, j - 1, x, y, n, ans);
	bt(grid, i, j + 1, x, y, n, ans);
	bt(grid, i - 1, j, x, y, n, ans);
	bt(grid, i + 1, j, x, y, n, ans);
	grid[i][j] = 1;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
		int n,si,sj,di,dj; cin >> n;
		vector<vector<int>> grid;
		for(int i = 0; i < n; i++){
            grid.push_back(vector<int>(n));
			for(int j = 0; j < n; j++){
				int x; cin >> x;
				if(x==1){si=i; sj=j; grid[i][j] = 1;}
				if(x==2){di=i; dj=j; grid[i][j] = 1;}
				if(x==3) grid[i][j] = 1;
				if(x==0) grid[i][j] = 0;
			}
		}
		bool ans = false;
		bt(grid, si, sj, di, dj, n, ans);
		cout << ans << endl;
	}
	return 0;
}
