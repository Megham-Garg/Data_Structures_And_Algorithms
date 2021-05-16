bool subsetSum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i = 0; i < n+1; i++)
    for(int j = 0; j < sum+1; j++){
        if(!i) dp[i][j] = 0;
        if(!j) dp[i][j] = 1;
        else if(i && arr[i-1] > j) dp[i][j] = dp[i-1][j];
        else if(i && arr[i-1] <= j) dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];
    }
    return dp[n][sum];
}
