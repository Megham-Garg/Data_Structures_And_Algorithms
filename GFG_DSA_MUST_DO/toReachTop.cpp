#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int dp[n+1];
	    dp[0]=0; dp[1] = 1;
	    if(n>1) dp[2]=2;
	    if(n>2) dp[3]=4;
	    for(int i = 4; i <= n; i++){
	        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	    }
	    cout << dp[n] << "\n";
	}
	return 0;
}
