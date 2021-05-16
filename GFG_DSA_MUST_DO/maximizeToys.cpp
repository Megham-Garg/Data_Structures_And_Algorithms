#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> n >> k;
	    vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];
	    sort(a.begin(),a.end());
	    int i = 0; int ans = 0;
	    while(k && i < n){
	        if(a[i] <= k){ans++; k-=a[i];}
	        else break;
	        i++;
	    }
	    cout << ans << "\n";
	}
	return 0;
}
