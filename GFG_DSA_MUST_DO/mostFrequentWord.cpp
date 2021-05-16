#include<bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    map<string, pair<int,int>> mp;
	    int i = 0;
	    while(i < n){
	        string inp; cin >> inp;
	        if(mp.find(inp) == mp.end()) {mp[inp].second = i; mp[inp].first = 1;}
	        else mp[inp].first += 1;
	        i++;
	    }
	    int max_occ = INT_MIN, index = INT_MIN;
	    string res="";
	    for(auto it = mp.begin(); it != mp.end(); it++){
	        if(it->second.first > max_occ) {
	            max_occ = it->second.first;
	            index = it->second.second;
	            res = it->first;
	        }
	        if(it->second.first == max_occ 
	               && index < it->second.second) {
	            index = it->second.second;
	            res = it->first;
	        }
	    }cout << res << "\n";
	}
	return 0;
}
