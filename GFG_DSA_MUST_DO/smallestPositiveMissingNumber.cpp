#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n; int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    sort(a, a+n);
	    int ans = -1; int small=-1;
	    for(int i = 0; i < n && ans==-1; i++){
	        if(small==-1 && a[i]>0) small = a[i];
	        if(a[i] > 0 || (i < n-1 && a[i+1] > 0))
	        {
	            if(a[i] <= 0 && i < n-1 && a[i+1] > 1)
    	            ans = 1;
	            else if(a[i] == 0 && i < n-1 && a[i+1] > 1)
    	            ans = 1;
	            else if(a[i] > 0 && i < n-1 && a[i+1]-a[i] > 1)
    	            ans = a[i]+1;
	        }
	    }
	    if(ans==-1 && small==1) ans = a[n-1]+1;
	    else if(ans==-1) ans = 1;
	    cout << ans << '\n';
	}
	return 0;
}
