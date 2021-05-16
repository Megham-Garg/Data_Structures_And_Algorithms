#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n; int mn = INT_MAX;
	    vector<string> a(n);
	    for(int i = 0; i < n; i++) {cin >> a[i]; mn = min(int(a[i].size()), mn);}
	    string s = "";
	    for(int i = 0; i < mn; i++){
	        char ch = a[0][i]; bool stat=true;
	        for(auto ele : a){
	            if(ch!=ele[i]) {stat = 0;break;}
	        }
	        if(stat) s+=ch;
	        else break;
	    }
	    if(!s.empty())cout << s << "\n";
	    else cout << -1 << "\n";
	}
	return 0;
}
