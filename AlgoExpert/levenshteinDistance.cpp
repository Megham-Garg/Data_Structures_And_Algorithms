#include<bits/stdc++.h>
using namespace std;

// levenshtein distance
// O(n*m) space and time
int main(){
    string str1 = "yabd", str2 = "abc";
    vector<vector<int>> dp;
    for(auto ch: str1){
        dp.push_back(vector<int>(str2.size()+1));
    }
    dp.push_back(vector<int>(str2.size()+1));

    for(int i = 1; i <= str2.size(); i++) dp[0][i] = 1 + dp[0][i-1];
    for(int i = 1; i <= str1.size(); i++) dp[i][0] = 1 + dp[i-1][0];
    
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            // cout << i << " " << j << "\n";
        }
    }
    
    cout << dp[str1.size()][str2.size()];

    return 0;
}