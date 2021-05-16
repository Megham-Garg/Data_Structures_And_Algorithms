#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    string input; cin >> input;
	    int mp[26]={0};
	    for(auto ch : input) mp[ch-'a']++;
	    char ans = 'A';
	    for(auto ch : input) if(mp[ch-'a']==1) {ans = ch; break;}
	    if(ans!='A') cout << ans;
	    else cout << -1;
	    cout << "\n";
	}
	return 0;
}
