#include<bits/stdc++.h>
using namespace std;
bool poss(vector<vector<int>> &grid, int row, int col, int n){
    bool f = true;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(i == row && j != col && grid[i][j] == 1) {f = false; break;}
        if(i != row && j == col && grid[i][j] == 1) {f = false; break;}
        if(abs(i - row) == abs(j - col) && grid[i][j] == 1) {f = false; break;}
    }
    return f;
}

void printSol(vector<vector<int>> &grid, int n){
    cout << "[";
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(grid[i][j] == 1) cout << j + 1 << " ";
    cout << "] ";
}

void getSol(vector<vector<int>> &grid, int row, int n){
    static bool noSoln;
    if(row == n) return;
    if(row == 0) noSoln = true;
    for(int col = 0; col < n; col++){
        if(poss(grid, row, col, n)){
            grid[row][col] = 1;
            if(row == n-1) {printSol(grid, n); noSoln = false;}
            getSol(grid, row + 1, n);
            grid[row][col] = 0;
        }
    }
    if(row == 0 && noSoln) cout << -1;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    vector<vector<int>> grid;
	    for(int i = 1; i <= n; i++) grid.push_back(vector<int>(n));
	    getSol(grid, 0, n);
	    cout << endl;
	}
	return 0;
}