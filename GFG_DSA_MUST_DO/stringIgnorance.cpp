#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t; cin.ignore();
	while(t--){
	    string inp; getline(cin, inp);
	    map<char, bool> mp;
	    for(auto ch : inp){
	        if(mp.find(tolower(ch)) == mp.end()) {cout << ch; mp[tolower(ch)] = true;}
	        else{
	            mp[tolower(ch)] = !mp[tolower(ch)];
	            if(mp[tolower(ch)]) cout << ch;
	        }
	    }cout << "\n";
	}
	return 0;
}
