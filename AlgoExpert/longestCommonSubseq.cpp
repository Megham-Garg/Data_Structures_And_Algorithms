#include<bits/stdc++.h>
using namespace std;

// O(nm) space
// O(nm) time
int main(){
    string a="zxvvyzw";
    string b="xkykzpw";
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    for(auto i : dp){
        for(auto j : i) cout << j << " ";
        cout << "\n";
    }

    int i = a.size(), j = b.size();
    while (i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else {cout << a[i-1]; i--; j--;}
    }
    
    return 0;
}