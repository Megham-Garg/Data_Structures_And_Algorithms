#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int arr[n]; for(int i = 0; i < n; i++) cin >> arr[i];
	    int dp[n];
	    for(int i = 0; i < n; i++) dp[i] = arr[i];
	    
	    for(int i = 1; i < n; i++)
	    for(int j = 0; j < i; j++){
	        if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+arr[i]);
	    }
	    int ans = arr[0];
	    for(int i = 1; i < n; i++) if(ans < dp[i]) ans = dp[i];
	    //{cout << dp[i] << " ";}
	    //cout << "\n";
	    cout << ans << "\n";
	}
	return 0;
}
