#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(n) space
vector<int> zigZag(vector<vector<int>> grid){
    vector<int> res;
    res.push_back(grid[0][0]);
    int n=grid.size(), m=grid[0].size();
    cout << n << " " << m << "\n";
    int x=1, y=0;
    int d1=-1,d2=1;
    while(true){
        cout << x << ":" << y << endl;
        res.push_back(grid[x][y]);
        x+=d1;
        y+=d2;
        while(x >0 && y > 0 && x < n-1 && y < m-1){
            res.push_back(grid[x][y]);
            x+=d1;
            y+=d2;
        }
        res.push_back(grid[x][y]);
        
        if(y!=m-1 && (x==0 || x==n-1)){
            y++;
        }
        else if(x!=n-1 && (y==0 || y==m-1)){
            x++;
        }
        
        d1*=-1;
        d2*=-1;
        if(x==n-1 && y==m-1) {res.push_back(grid[x][y]); break;}
    }
    return res;
}

int main(){
    vector<vector<int>> grid;
    grid.push_back({1, 3, 4, 10});
    grid.push_back({2, 5, 9, 11});
    grid.push_back({6, 8, 12, 15});
    grid.push_back({7, 13, 14, 16});
    grid.push_back({17, 18, 19, 20});
    vector<int> res = zigZag(grid);
    for(auto ele : res) cout << ele << " ";
    cout << "\n";
    return 0;
}