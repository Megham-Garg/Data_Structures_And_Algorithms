#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int solveDropEgg(int e, int f, int dp[][51]){
    if(f==0||f==1||e==1) return f;
    if(dp[e][f]!=-1) return dp[e][f];
    dp[e][f] = INT_MAX;
    for(int k = 1; k <= f; k++){
        dp[e][f] = min(dp[e][f],
                        max(solveDropEgg(e - 1, k - 1, dp),
                        solveDropEgg(e, f - k, dp))
                        +1);
    }return dp[e][f];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int e, f; cin >> e >> f;
	    int dp[11][51];
	    for(int i = 0; i < 11; i++)
	        for(int j = 0; j < 51; j++)
	            dp[i][j]=-1;
	            
	    cout << solveDropEgg(e, f, dp) << "\n";
	}
	return 0;
}
