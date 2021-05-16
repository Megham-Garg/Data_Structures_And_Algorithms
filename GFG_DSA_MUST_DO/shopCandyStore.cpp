#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> n >> k;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    sort(a.begin(), a.end());
	    int mn=0; int mx=0;
	    int x = n/(k+1);
	    if(n%(k+1)) x++;
	    for(int i = 0; i < x; i++) mn+=a[i];
	    for(int i = n-1; i >= n-x; i--) mx+=a[i];
	    cout << mn << " " << mx << "\n";
	}
	return 0;
}
