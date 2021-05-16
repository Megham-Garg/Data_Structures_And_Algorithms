#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string s1,s2; cin >> s1 >> s2; ll mp[26]={0}; bool f=0;
	    for(char c : s1) mp[c-'a']++;
	    for(char c : s2) mp[c-'a']--;
	    for(int i = 0; i<= 25; i++) 
	        if(mp[i]!=0) {f=1; cout << "NO\n"; break;}
        if(!f) cout << "YES\n";
	}
	return 0;
}
