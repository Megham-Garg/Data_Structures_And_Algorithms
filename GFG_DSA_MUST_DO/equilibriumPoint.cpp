#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n),sa(n); // sum after
	    for(int i = 0; i < n; i++) cin >> a[i];
	    int cs=0;
	    for(int i = n-1; i >= 0; i--){
            sa[i]=cs;
            cs+=a[i];
	    }
	    cs=0; bool exists = false;
	    for(int i = 0; i < n; i++){
	        if(cs==sa[i]) {exists=1; cout << i+1 << "\n"; break;}
	        cs+=a[i];
	    }
	    if(!exists) cout << -1 << "\n";
	}
	return 0;
}
