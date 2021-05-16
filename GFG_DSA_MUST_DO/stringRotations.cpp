#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string a,b;
	    cin >> a >> b;
	    bool ans = 0;
	    if(a.size()!=b.size()) ans = 0;
	    else if(a==b) ans = 1;
	    else{
	        int rot = a.size()-1;
	        while(rot--)
	        {
	            a.insert(0,1,a[a.size()-1]);
	            a.pop_back();
	            if(a==b) {ans = 1; break;}
	        }
	    }cout << ans << "\n";
	}
	return 0;
}
