#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string a,b; cin >> a >> b;
	    int mp[26]={0};
	    for(auto ch : a) mp[ch-'a']++;
	    for(auto ch : b) if(mp[ch-'a']) mp[ch-'a']=-1;
	    string ans = "";
	    for(auto ch : a) if(mp[ch-'a']!=-1) ans+=ch;
	    for(auto ch : b) if(mp[ch-'a']!=-1) ans+=ch;
	    if(ans.length()) cout << ans;
	    else cout << -1;
	    cout << "\n";
	}
	return 0;
}
