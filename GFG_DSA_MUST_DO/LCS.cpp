#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,m; cin >> n >> m;
	    string a,b; cin >> a >> b;
        n = int(a.size())+1;
        m = int(b.size())+1;
	    int dp[n][m];
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < m; j++) dp[i][j]=0;
	        
	    for(int i = 1; i < n; i++)
	        for(int j = 1; j < m; j++){
	            if(a[i-1] == b[j-1]) dp[i][j]=1+dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    cout << dp[n-1][m-1] << "\n";
	}
	return 0;
}
