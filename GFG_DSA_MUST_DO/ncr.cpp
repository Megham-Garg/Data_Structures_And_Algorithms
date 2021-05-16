#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 1000000007

ll dp[1001][801] = {0};

ll ncr(int n, int r){
    if(n==r || !r) return 1;
    if(n < r) return 0;
    if(dp[n][r]) return dp[n][r];
    dp[n][r] = (ncr(n-1,r-1)%max + ncr(n-1,r)%max) % max;
    return dp[n][r];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,r; cin >> n >> r;
	    cout << ncr(n,r) << "\n";
	}
	return 0;
}
