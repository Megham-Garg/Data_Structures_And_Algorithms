#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
	    int dp[n]; for(int i = 0; i < n; i++) dp[i]=1;
	    
	    for(int i = 1; i <= n-1; i++)
	    for(int j = 0; j <= i-1; j++){
	        if(arr[i] > arr[j]) dp[i] = max(dp[i],dp[j]+1);
	    }
	    
	    int ans = 1;
	    for(int i = 0; i <= n-1; i++) if(ans < dp[i]) ans = dp[i];
	    cout << ans << "\n";
	}
	return 0;
}   
