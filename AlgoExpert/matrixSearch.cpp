#include<bits/stdc++.h>
using namespace std;

pair<int, int> matrixSearch(vector<vector<int>> matrix, int target){
    int n = matrix.size()-1;
    int m = matrix[0].size()-1;
    int i = 0,j = m;
    while(j>-1 && i<n+1){
        if(matrix[i][j] == target)  return make_pair(i,j);
        else if(matrix[i][j] < target) {i++;}
        else{j--;}
    }
    return make_pair(-1,-1);
}
// O(1) space
// O(n+m) time

int main(){
    return 0;
}