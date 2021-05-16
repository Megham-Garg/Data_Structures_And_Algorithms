#include<bits/stdc++.h>
using namespace std;

bool possibleWord(map<string, bool> &strMap, const string formed){
    if(strMap.find(formed) != strMap.end() && strMap[formed] == true){
        strMap[formed] = false;
        return true;
    }
    else return false;
}
void PrintPossibleWords(vector<string> &vs, vector<vector<char>> &grid, map<string, bool> &strMap, int n, int m, int i, int j, string formed){
    if(i > n-1 || j > m-1 || i < 0 || j < 0 || grid[i][j] == '-') return; // base condition
    char temp = grid[i][j];
    grid[i][j] = '-'; // visited status
    formed.push_back(temp);
    
    if(possibleWord(strMap, formed)) { // if traversed string matches in dictionary push in vector
        vs.push_back(formed);
    }
    
    PrintPossibleWords(vs, grid, strMap, n, m, i+1, j+1, formed); // diagonaly
    PrintPossibleWords(vs, grid, strMap, n, m, i-1, j-1, formed); // diagonaly
    PrintPossibleWords(vs, grid, strMap, n, m, i, j+1, formed); // right
    PrintPossibleWords(vs, grid, strMap, n, m, i+1, j, formed); // down
    PrintPossibleWords(vs, grid, strMap, n, m, i, j-1, formed); // left
    PrintPossibleWords(vs, grid, strMap, n, m, i-1, j, formed); // up
    PrintPossibleWords(vs, grid, strMap, n, m, i-1, j+1, formed); // diagonaly
    PrintPossibleWords(vs, grid, strMap, n, m, i+1, j-1, formed); // diagonaly
    
    if(formed.size() != 0) formed.pop_back();
    grid[i][j] = temp;
    return;
}
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int numWords; cin >> numWords;
	    map<string,bool> strMap;
	    for(int i = 0; i < numWords; i++){
	        string s; cin >> s;
	        strMap[s] = true;
	    }
	    int n,m; cin >> n >> m;
	    vector<vector<char>> grid;
	    for(int i = 0; i < n; i++){
	        grid.push_back(vector<char>(m));
    	    for(int j = 0; j < m; j++) cin >> grid[i][j];
	    }
        vector<string> vs;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) PrintPossibleWords(vs, grid, strMap, n, m, i, j, "");
        
	    if(vs.size() == 0) cout << -1;
	    else sort(vs.begin(), vs.end());
	    
	    for(int i = 0; i < vs.size(); i++) cout << vs[i] << " ";
	    cout << endl;
	}
	return 0;
}