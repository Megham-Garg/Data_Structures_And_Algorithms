#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int x = 0, y = (n*(n+1))/2;
	    for(int i = 0; i < n-1; i++){
	        int k; cin >> k;
	        x+=k;
	    }
	    cout << y-x << "\n";
	}
	return 0;
}
