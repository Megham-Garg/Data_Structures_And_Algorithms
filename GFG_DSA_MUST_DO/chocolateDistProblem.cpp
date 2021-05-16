#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++) cin >> a[i];
	    int k; cin >> k;
	    sort(a.begin(), a.end());
	    int diff = a[k-1]-a[0];
	    for(int i = 1; i < n-k+1; i++){
	        if(a[i+k-1]-a[i] < diff) diff = a[i+k-1]-a[i];
	    }
	    cout << diff << "\n";
	}
	return 0;
}
