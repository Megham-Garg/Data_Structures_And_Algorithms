#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    map<string, int> freq;
	    for(int i = 0; i < n; i++) {
	        string temp;
	        cin >> temp;
	        freq[temp]++;
	    }
	    string a="";
	    int i = INT_MIN, j = INT_MIN;
	    
	    for(auto u : freq)
	        if(u.second > j ) j=u.second;
	        
	    for(auto u : freq){
	        if(u.second > i && u.second!=j){
	            a= u.first;
	            i=u.second;
	        }
	    }
	    cout << a << "\n";
	}
	return 0;
}
