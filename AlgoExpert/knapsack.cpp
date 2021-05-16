#include<bits/stdc++.h>
using namespace std;

// O(items*cap) time and space
int main(){
    vector<int> weight={2,3,6,7}, value={1,4,5,6};
    int cap=10, items = 4;
    vector<vector<int>> dp(items+1, vector<int>(cap+1, 0));

    for(int i = 1; i < items+1; i++){
        for(int j = 1; j < cap+1; j++){
            if(weight[i-1] <= j && value[i-1]+dp[i-1][j-weight[i-1]] > dp[i-1][j])
                dp[i][j] = value[i-1]+dp[i-1][j-weight[i-1]];
            else if(dp[i-1][j]) dp[i][j]=dp[i-1][j];
        }
    }
    
    for(auto vec: dp){
        for(auto val : vec) cout << val << " ";
        cout << "\n";
    }

    cout << "Max Value our knapsack can hold is: " << dp[items][cap] << endl;
    cout << "items added are: ";

    int i = items, j = cap;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i-1][j]){
            cout << "[" << weight[i-1] << ", " << value[i-1] << "] ";
            j -= weight[i-1];
        }i--;
    }

    return 0;
}