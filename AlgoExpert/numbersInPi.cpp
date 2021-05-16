#include<bits/stdc++.h>
using namespace std;

// O(n) space
// O(n^3) time due to substr else O(n^2)

int numbersInPi(string num, const unordered_set<string>& hash, unordered_map<string, int>& dp){
    // if already computed return partitions
    if(dp.find(num)!=dp.end()) return dp[num];

    // if this part present in hash return 1
    if(hash.find(num) != hash.end()){
        dp[num] = 1;
        return dp[num];
    }

    dp[num] = INT_MAX;
    string sub;

    for(int i = 1; i <= num.size(); i++){
        sub = num.substr(0,i);
        if(hash.find(sub) != hash.end()) {
            if(dp.find(sub)==dp.end()) dp[sub] = 1 + numbersInPi(num.substr(i, num.size()), hash, dp);
            dp[num] = min(dp[sub], dp[num]);
        }
    }
    return dp[num];
}


int main(){
    int num = "3141592";
    unordered_set<string> hash;
    unordered_map<string, int> dp;
    hash.insert("3141");
    hash.insert("5");
    hash.insert("9");
    hash.insert("2");
    hash.insert("31");
    hash.insert("42");
    hash.insert("4159");
    cout << "minimum spaces needed are: " << numbersInPi(num, hash, dp) - 1;
    return 0;
}