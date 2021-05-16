#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXSIZE 102
int optimalStrat(int a[], int i, int j, int n, int turn, int dp[][MAXSIZE]){
    if(i==j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    turn = turn ? 0 : 1;
    int x = optimalStrat(a, i+1, j, n, turn, dp);
    int y = optimalStrat(a, i, j-1, n, turn, dp);
    if(turn) dp[i][j] = max(x + a[i], y + a[j]);
    else dp[i][j] = min(x,y);
    return dp[i][j];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
	    
	    int dp[MAXSIZE][MAXSIZE]={0};
	    for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++) dp[i][j] = -1;
	    
	    int ans = optimalStrat(a, 0, n-1, n, 0, dp);
	    
	    cout << ans << "\n";
	}
	return 0;
}
