#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string s; cin >> s;
	    int n = s.size(); set<char> ch; int res= 0;
	    int i = 0, j = 0;
	    while(j < n){
	        if(ch.find(s[j])==ch.end()) {
	            ch.insert(s[j]); j++;
	            res = max(int(ch.size()), res);
	        }
	        else {
	            ch.erase(s[i]);
	            i++;
	        }
	    }cout << res << "\n";
	}
	return 0;
}
