#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1001][1001];
int knapsack(int pt[], int wt[], int cap, int n){
    if(cap<=0||n<=0) return 0;
    else if(dp[cap][n]!=-1) return dp[cap][n];
    else if(wt[n-1] > cap) dp[cap][n] = knapsack(pt, wt, cap, n-1);
    else dp[cap][n] = max(knapsack(pt, wt, cap, n-1), pt[n-1] + knapsack(pt, wt, cap-wt[n-1], n-1));
    return dp[cap][n];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n, cap; cin >> n >> cap;
        memset(dp, -1, sizeof(dp[0][0])*1001*1001);
	    int pt[n], wt[n];
	    for(int i = 0; i < n; i++) cin >> pt[i];
	    for(int i = 0; i < n; i++) cin >> wt[i];
	    cout << knapsack(pt, wt, cap, n) << "\n";
	}
	return 0;
}
