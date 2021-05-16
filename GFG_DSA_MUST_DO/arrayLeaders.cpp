#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n); int cmx=INT_MIN;
	    for(int i = 0; i < n; i++) cin >> a[i];
	    stack<int> ans;
	    for(int i = n-1; i >= 0; i--){
	        cmx = max(cmx, a[i]);
	        if(a[i]==cmx) ans.push(cmx);
	    }
	    while(!ans.empty()){
	    cout << ans.top() << " "; ans.pop();}
	    cout << "\n";
	}
	return 0;
}
