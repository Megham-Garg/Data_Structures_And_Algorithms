#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end){
    while(start < end){
        if(str[start] != str[end]) return false;
        start++; end--;
    }
    return true;
}//O(length(str)) time


int minPartPal(string inp, int start, int end, vector<int>& dp){
    if(start >= end) return 0;
    if(dp[start] != -1) return dp[start];
    int ans = INT_MAX;
    for(int i = start; i < end; i++){
        if(i==start || isPalindrome(inp, start, i)){
            if(dp[i+1] == -1) dp[i+1] = minPartPal(inp, i+1, end, dp);
            ans = min(ans, 1 + dp[i+1]);
        }
    }
    dp[start] = ans;
    return ans;
}
// O(n^3) time
// O(n) space

// O(n^2) time and space approach by precomputing palindromes in 2d array
int main(){
    vector<string> arr = {"noonabbad", "geek", "aaaa", "abcbass", "abbac"};
    int ans;
    for(auto str : arr){
        vector<int> dp(str.size()+1, -1);
        ans = minPartPal(str, 0, str.size(), dp);
        cout << "Minimum partitions reqd. for "<< str << " are : " << ans-1 << endl;
    }
    return 0;
}
