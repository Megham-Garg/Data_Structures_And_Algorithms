#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t = 0; cin >> t;
	while(t--){
	    ll n; cin >> n;
	    ll a[n];
	    ll mx[n];
	    for(ll i = 0; i < n; i++) cin >> a[i];
	    mx[n-1] = a[n-1];
	    mx[0] = a[0]; ll z = 0;
	    for(ll i = n-2; i > 0; i--) mx[i] = max(a[i], mx[i+1]);
	    for(ll i = 1; i < n-1; i++){
	        if( min(max(a[i], mx[i-1]), mx[i]) > a[i])
	        z+=min(max(a[i], mx[i-1]), mx[i]) - a[i];
	        mx[i] = min(max(a[i], mx[i-1]), mx[i]);
	    }
	    cout << z << "\n";
	}
	return 0;
}
