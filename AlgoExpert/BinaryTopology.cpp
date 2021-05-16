#include<bits/stdc++.h>
using namespace std;

// O(n^2) time
// O(n) space
int BinTopNum(int n, unordered_map<int, int>& dp){
    if(dp.find(n) != dp.end()) return dp[n];
    for(int i = 0; i <= n-1; i++){
        if(dp.find(i) == dp.end()) dp[i] = BinTopNum(i, dp);
        if(dp.find(n-i-1) == dp.end()) dp[n-i-1] = BinTopNum(n-i-1, dp);
        dp[n]+=dp[i]*dp[n-i-1];
    }
    return dp[n];
}

int main(){
    unordered_map<int, int> dp;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    dp[3]=5;
    for(int i=0; i < 10; i++){
        cout << "number of binary topologies: " << BinTopNum(i, dp) << "\n";
    }
    return 0;
}
