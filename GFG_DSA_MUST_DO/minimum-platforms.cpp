#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<int> a(n),d(n); int ans = 1;
	    for(int i = 0; i < n; i++) cin >> a[i];
	    for(int i = 0; i < n; i++) cin >> d[i];
	    sort(a.begin(), a.end());
	    sort(d.begin(), d.end());
	    int i = 1, j =0;
	    int need = 1;
	    int cur = 1;
	    while(i < n || j < n){
	        if(d[j] >= a[i] && i < n){
	            i++;
	            cur++;
	        }
	        else if(j < n){
	            j++;
	            cur--;
	        }
	        need = max(need,cur);
	    }
	    cout << need << "\n";
	}
	return 0;
}
