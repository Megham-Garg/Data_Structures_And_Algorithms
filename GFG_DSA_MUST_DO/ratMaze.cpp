#include<bits/stdc++.h>
using namespace std;
#define MAX 5

bool solveMaze(int m[MAX][MAX],const int n, const int i, const int j, vector<string> &vs){
    static string s;
    if((i >= n || j >= n || i < 0 || j < 0) || (m[i][j] == 0 || m[i][j] == -1)) return false;
    else if(i == n-1 && j == n-1) {vs.push_back(s); return true;}
    m[i][j] = -1;
    bool f1,f2,f3,f4;
    
    s.push_back('D');
    f2 = solveMaze(m, n, i+1, j, vs); // down
    s.pop_back();
    
    s.push_back('L');
    f4 = solveMaze(m, n, i, j-1, vs); // left
    s.pop_back();
    
    s.push_back('R');
    f1 = solveMaze(m, n, i, j+1, vs); // right
    s.pop_back();
    
    s.push_back('U');
    f3 = solveMaze(m, n, i-1, j, vs); // up
    s.pop_back();
    
    m[i][j] = 1;
    return f1||f2||f3||f4;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> vs;
    solveMaze(m, n, 0, 0, vs);
    sort(vs.begin(), vs.end());
    return vs;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[MAX][MAX];
        for(int i = 0; i < n; i++)
        for(int i1 = 0; i1 < n; i1++) cin >> arr[i][i1];
        vector<string> vs = printPath(arr, n);
        if(vs.empty()) cout << -1 << endl;
        else for(auto it = vs.begin(); it != vs.end(); it++) cout << *it << " "; cout << endl;
    }
}