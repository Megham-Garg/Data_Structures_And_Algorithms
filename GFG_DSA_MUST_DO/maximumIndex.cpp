#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    vector<ll> a(n);
	    for(ll i = 0; i < n; i++) cin >> a[i];
	    ll ans = INT_MIN;
	    for(ll i = 0; i < n; i++)
	    for(ll j = n-1; j >= i; j--){
	        if(a[i] <= a[j]) {ans = max(j-i, ans); break;}
	    }cout << ans << "\n";
	}
	return 0;
}
