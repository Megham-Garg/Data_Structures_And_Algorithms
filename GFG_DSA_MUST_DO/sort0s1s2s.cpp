#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    int a[3]={0};
	    for(int i = 0; i < n; i++){
	        int x; cin >> x;
	        a[x]++;
	    }
	    while(a[0]--) cout << 0 << " ";
	    while(a[1]--) cout << 1 << " ";
	    while(a[2]--) cout << 2 << " ";
	    cout << "\n";
	}
	return 0;
}
