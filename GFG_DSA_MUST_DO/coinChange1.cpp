#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> coin(n); for(int i = 0; i < n; i++) cin >> coin[i];
	    int cap; cin >> cap;
	    int dp[cap+1][n+1]={0};
	    for(int i = 0; i <= n; i++) dp[0][i] = 1;
	    
	    for(int i = 1; i < cap+1; i++)
    	    for(int j = 1; j <= n; j++){
    	        if(coin[j-1] <= i)
    	            dp[i][j] = dp[i][j-1]+dp[i-coin[j-1]][j];
    	        else dp[i][j] = dp[i][j-1];
    	    }
    	    cout << dp[cap][n] << "\n";
	}
	return 0;
}
