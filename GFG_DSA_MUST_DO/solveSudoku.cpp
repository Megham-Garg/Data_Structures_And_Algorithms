#include<bits/stdc++.h>
using namespace std;

void printGrid(const vector<vector<int>> &grid){
    for(int i = 0; i < 9; i++) for(int j = 0; j < 9; j++) cout << grid[i][j] << " ";
    return;
}
vector<int> getValidChoices(const vector<vector<int>> &grid,const int i,const int j){
    map<int, bool> m;
    for(int num = 1; num < 10; num++) m[num] = false;
    
    for(int in = 0; in < 9; in++) if(grid[in][j] != 0) m[grid[in][j]] = true;
    for(int in = 0; in < 9; in++) if(grid[i][in] != 0) m[grid[i][in]] = true;
    int x,y;
    if(i < 3 && j < 3){x=0;y=0;}
    else if(i < 3 && j < 6 && j > 2){x=0;y=3;}
    else if(i < 3 && j > 5){x=0;y=6;}
    
    else if(j < 3 && i < 6 && i > 2){x=3;y=0;}
    else if(j < 3 && i > 5){x=6;y=0;}
    else if(i < 6 && j < 6 && i > 2 && j > 2){x=3;y=3;}
    else if(i < 6 && j > 5 && i > 2){x=3;y=6;}
    else if(i > 5 && j < 6 && j > 2){x=6;y=3;}
    else if(i > 5 && j > 5){x=6;y=6;}
    
    for(int in = x; in < x+3; in++)
    for(int out = y; out < y+3; out++) if(grid[in][out] != 0) m[grid[in][out]] = true;
    
    vector<int> vc;
    for(int num = 1; num < 10; num++) if(m[num] == false) vc.push_back(num);
    return vc;
}
bool solveGrid(vector<vector<int>> &grid, int i, int j);
void printSoln(vector<vector<int>> &grid){
    solveGrid(grid, 0, 0);
    printGrid(grid);
    return;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    
	    vector<vector<int>> grid;
	    for(int i = 0; i < 9; i++){
	        grid.push_back(vector<int>(9));
	        for(int j = 0; j < 9; j++) {
	            cin >> grid[i][j];
	        }
	    }
	    printSoln(grid);
	}
	return 0;
}

bool solveGrid(vector<vector<int>> &grid, int i, int j){
    if(grid[i][j]!=0){
        if(j < 8) return solveGrid(grid, i, j+1);
        else if(j == 8 && i < 8) return solveGrid(grid, i+1, 0);
        else return true;
    }
    vector<int> vc = getValidChoices(grid,i,j);
    if(vc.size() == 0) return false;
    bool f = false;
    for(int k = 0; k < vc.size() && grid[i][j] == 0; k++){
        grid[i][j] = vc[k];
        if(j < 8) f = solveGrid(grid, i, j+1);
        else if(j == 8 && i < 8) f = solveGrid(grid, i+1, 0);
        else f = solveGrid(grid,8,8);
        if(f == false) grid[i][j] = 0;
        else break;
    }
    return f;
}
