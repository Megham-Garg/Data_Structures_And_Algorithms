#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t; cin>>t;
	for(int j = 1; j <= t; j++){
	    ll n; cin >> n;
	    vector<ll> arr(n);
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    
	    ll result = 2;
	    ll cur = 2;
	    ll diff = arr[1] - arr[0];
	    
	    
	    for(int i = 2; i < n; i++){
	        if(diff != arr[i]-arr[i-1]){
	            result = max(result, cur);
	            cur = 2;
	            diff = arr[i]-arr[i-1];
	        }
	        else{
	            cur++;
	        }
	    }
	    result = max(result,cur);
	    cout << "Case #" << j << ": " <<result << "\n";
	}
	return 0;
}