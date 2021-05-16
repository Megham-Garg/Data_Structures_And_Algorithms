#include<bits/stdc++.h>
using namespace std;

// O(nm) time for n*m grid
// O(1) space

void spiralTraverse(vector<vector<int>> grid){
    int x = 0, y = 0;
    int n = grid.size();
    int m = grid[0].size();

    // 0 5
    while(x < n && y < m){
        // right
        for(int i = x; i < m; i++)
            cout << grid[x][i] << " ";
        
        // down
        for(int i = y+1; i < n; i++)
            cout << grid[i][m-1] << " ";
        
        // left
        for(int i = m-2; i >= x; i--)
            cout << grid[n-1][i] << " ";

        // up
        for(int i = n-2; i >= x+1; i--)
            cout << grid[i][y] << " ";
        
        x++; y++;
        n--; m--;
    }
}

int main(){
    vector<vector<int>> grid;
    // 5 X 4
    grid.push_back({ 1,  2,  3, 4});
    grid.push_back({14, 15, 16, 5});
    grid.push_back({13, 20, 17, 6});
    grid.push_back({12, 19, 18, 7});
    grid.push_back({11, 10,  9, 8});
    spiralTraverse(grid);
    return 0;
}