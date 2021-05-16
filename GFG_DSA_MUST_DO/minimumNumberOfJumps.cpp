#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int a[n]; for(int i = 0; i < n; i++) cin >> a[i];
	    int jumps[n]; for(int i = 1; i < n; i++) jumps[i] = INT_MAX-1;
	    jumps[0]=0;
	    int from[n]={0};
	    for(int i = 1; i < n; i++)
    	    for(int j = 0; j < i; j++){
    	        if(j+a[j] >= i) {
    	            if(jumps[j]+1 < jumps[i]) from[i] = j;
    	            jumps[i] = min(jumps[j]+1, jumps[i]);
    	        }
    	    }
	   // for(int i = 0; i < n; i++) cout << a[i] << " ";
	   // cout << "\n";
	   // for(int i = 0; i < n; i++) cout << jumps[i] << " ";
	   // cout << "\n";
	   // for(int i = 0; i < n; i++) cout << from[i] << " ";
	   // cout << "\n";
    	if(jumps[n-1]!=INT_MAX-1)cout << jumps[n-1] << "\n";
    	else cout << -1 << "\n";
	}
	return 0;
}
