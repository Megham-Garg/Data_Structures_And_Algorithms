#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n);
	    int ans = 0;
	    for(int i = 0; i < n; i++) {int x; cin >> x; a[i]=x*x;}
	    sort(a.begin(),a.end());
	    for(int i = n-1; i > 1; i--){
	        int j = 0, k = i-1;
	        while(j < k){
	            if(a[j]+a[k]==a[i]) ans=1;
	            if(a[j]+a[k]>a[i]) k--;
	            else j++;
	            if(ans) break;
	        }
	        if(ans) break;
	    }
	    cout << (ans?"Yes\n":"No\n");
	}
	return 0;
}
