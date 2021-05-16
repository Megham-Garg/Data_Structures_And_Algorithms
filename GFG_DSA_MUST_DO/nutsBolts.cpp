#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
    char arr[] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
	while(t--){
	    int n; cin >> n;
	    map<char, bool> mp;
	    char ch;
	    
	    for(auto ele : arr) mp[ele] = false;
	    
	    for(int i = 0; i < n; i++){
	        cin >> ch; mp[ch] = true;
	    }
	    
	    for(int i = 0; i < n; i++) cin >> ch;
	    
	    for(auto ele : arr)  if(mp[ele] == true) cout << ele << " ";
	    cout << "\n";
	    
	    for(auto ele : arr) if(mp[ele] == true) cout << ele << " ";
	    cout << "\n";
	}
	return 0;
}
