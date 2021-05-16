#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool EQSP(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i = 0; i < n+1; i++)
    for(int j = 0; j < sum+1; j++){
        if(!i) dp[i][j] = 0;
        if(!j) dp[i][j] = 1;
        else if(i && arr[i-1] > j) dp[i][j] = dp[i-1][j];
        else if(i && arr[i-1] <= j) dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];
    }
    return dp[n][sum];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int arr[n], sum=0;
	    for(int i = 0; i < n; i++) {cin >> arr[i]; sum+=arr[i];}
	    if(sum%2) cout << "NO\n";
	    else cout << (EQSP(arr, n, sum/2)?"YES\n":"NO\n");
	}
	return 0;
}
