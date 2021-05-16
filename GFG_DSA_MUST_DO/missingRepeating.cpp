#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n+1);
	    for(int i = 1; i <= n; i++){
	        int x; cin >> x;
	        if(!a[x]) a[x] = 1;
	        else a[x] = 2;
	    }
	    int x=0,y=0;
	    for(int i = 1; i <= n; i++){
	        if(!a[i] && !x) x = i;
	        else if(a[i]==2 && !y) y = i;
	        else if(x && y) break;
	    }
	    cout << y << " " << x << "\n";
	}
	return 0;
}
