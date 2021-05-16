#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string inp, op=""; cin >> inp; int n = inp.size();
	    int j = n-1;
	    for(int i = n-1; i >= 0; i--){
	        if(inp[i]=='.') {
	            if(i+1 < n) op+=inp.substr(i+1, j-i);
	            op+='.';
	            j=i-1;
	        }
	    }
	    if(inp[0]!='.'){op+=inp.substr(0, j+1);}
	    cout << op << "\n";
	}
	return 0;
}
