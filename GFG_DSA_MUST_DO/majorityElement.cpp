#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n);
	    map<int, int> mp;
	    int ans=-1;
	    for(int i = 0; i < n; i++) {cin >> a[i]; mp[a[i]]++;}
	    for(auto it = mp.rbegin(); it != mp.rend(); it++){
	        if(it->second > n/2) {ans = it->first; break;}
	    }
	    cout << ans << "\n";
	}
	return 0;
}
