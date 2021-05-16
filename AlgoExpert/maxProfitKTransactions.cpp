#include<bits/stdc++.h>
using namespace std;

// O(n^2*k) time
// O(nk) space
// void maxProfit(vector<int> arr, int k){
//     vector<vector<int>> dp(k+1, vector<int>(arr.size(), 0));
    
//     for(int i = 1; i <= k; i++){
//         for(int j = 1; j < arr.size(); j++){
//             if(j > 1) dp[i-1][j-1] = max(-arr[j-1]+dp[i-1][j-1], dp[i-1][j-2]);
//             else dp[i-1][j-1] = -arr[j-1]+dp[i-1][j-1];
//             dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + arr[j]);
//         }
//     }
    
//     for(int i = 0; i <= k; i++){
//         for(int j = 0; j < arr.size(); j++){
//             cout << dp[i][j] << " ";
//         }cout << endl;
//     }
//     cout << "max profit will be: " << dp[k][arr.size()-1];
// }

// O(n*k) time
// O(nk) space -> O(n) possible by storing only cur and prev row
void maxProfit(vector<int> arr, int k){
    vector<vector<int>> dp(k+1, vector<int>(arr.size(), 0));
    
    for(int i = 1; i <= k; i++){
        for(int j = 1; j < arr.size(); j++){
            if(j > 1) dp[i-1][j-1] = max(-arr[j-1]+dp[i-1][j-1], dp[i-1][j-2]);
            else dp[i-1][j-1] = -arr[j-1]+dp[i-1][j-1];
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + arr[j]);
        }
    }
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < arr.size(); j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    cout << "max profit will be: " << dp[k][arr.size()-1];
}

int main(){
    int k = 2;
    vector<int> price = {5,11,3,50,60,90};
    maxProfit(price, k);
    return 0;
}