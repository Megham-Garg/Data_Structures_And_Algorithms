#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,s; cin >> n >> s;
	    ll res=0;
	    if((n*9 < s) || (n>1 && !s)) cout << -1 << "\n";
	    else{
	        for(int i = 0; i < s/9; i++) {cout << '9'; n--;}
	        s = s%9;
	        if(s) {cout << s; n--;}
    	    while(n--) cout << '0';
    	    cout <<"\n";
	    }
	}
	return 0;
}
