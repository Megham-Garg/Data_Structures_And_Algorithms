#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string s; cin >> s;
	    int n = s.size(); int res = 0; int x = 0, y = n-1;
	    for(int i = 0; i < n; i++){
	        int count = -1;
	        int l = i, r = i;
	        while(l >= 0 && r < n && s[l]==s[r]) {count+=2; l--; r++;}
	        if(res < count) {res=count; x = l+1; y = r-1;}
	        l = i; r = i+1; count = 0;
	        while(l >= 0 && r < n && s[l]==s[r]) {count+=2; l--; r++;}
	        if(res < count) {res=count; x = l+1; y = r-1;}
	    } cout << s.substr(x,res) << "\n";
	}
	return 0;
}
