int maXor(int arr[], int n, int node, int loc, int dp[][1000]){
    if(n == node) return -1;
    if(dp[node][loc]) return dp[node][loc];
    int a = loc^arr[node];
    int b = loc;
    a = max(a, maXor(arr, n, node+1, a, dp));
    b = max(b, maXor(arr, n, node+1, b, dp));
    dp[node][loc] = max(a,b);
    return max(a,b);
}

int maxSubarrayXOR(int arr[], int n)
{
    int dp[n][1000] = {0};
    if(n==1) return arr[0];
    int ans = 0;
    ans = maXor(arr,n,0,0,dp);
    return ans;
}
// uses backtracking + bit magic + dp
