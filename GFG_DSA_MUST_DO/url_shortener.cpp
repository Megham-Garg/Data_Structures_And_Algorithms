#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int original = n;
	    string mp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	    stack<char> coded;
	    while(n){
	        coded.push(mp[n%62]);
	        n/=62;
	    }
	    while(!coded.empty())
	    {cout << coded.top(); coded.pop();}
	    cout << "\n" << original << "\n";
	}
	return 0;
}
