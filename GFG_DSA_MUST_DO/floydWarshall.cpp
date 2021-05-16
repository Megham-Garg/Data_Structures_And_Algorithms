#include<bits/stdc++.h>
using namespace std;
#define INF 10000000

void floydWarshall(vector<int> grid[], int n){
    int inter[n][n][n] = {INF};
    for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++){
            if(j==0 || k==0 || j==k) inter[0][j][k] = grid[j][k];
            else{
                inter[0][j][k] = min(grid[j][k], grid[j][0]+grid[0][k]);
            }
        }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++){
            if(j==i || k==i || j==k) inter[i][j][k] = inter[i-1][j][k];
            else{
                inter[i][j][k] = min(inter[i-1][j][k], inter[i-1][j][i]+inter[i-1][i][k]);
            }
        }
    }
    for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
	        if(inter[n-1][i][j]!=INF) cout << inter[n-1][i][j] << " ";
	        else cout << "INF" << " ";
	    }
	    cout << "\n";
    }
}
	    
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    vector<int> grid[n];
	    for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++){
	        int x; cin >> x;
	        grid[i].push_back(x);
	    }
	    floydWarshall(grid, n);
	}
	return 0;
}
/*
1
4
0 3 inf 7
8 0 2 inf
5 inf 0 1
2 inf inf 0
*/
