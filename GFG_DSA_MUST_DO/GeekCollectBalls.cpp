#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> n >> k;
	    queue<int> a, b;
	    for(int i = 0; i < n; i++) {int x; cin >> x; a.push(x);}
	    for(int i = 0; i < k; i++) {int x; cin >> x; b.push(x);}
	    int ans = 0;
	    int s1=0,s2=0;
	    while(!a.empty() && !b.empty()){
            // cout << s1 << " " << s2 << " " << ans << "\n";
	        if(a.front() > b.front()){
	            s2+=b.front();
	            b.pop();
	        }
	        else if(a.front() < b.front()){
	            s1+=a.front();
	            a.pop();
	        }
	        else{
	            ans += max(s1,s2);
	            s1=0; s2=0;
	            int x = a.front();
	            int count = -1;
	            while(!a.empty()&&a.front()==x) {a.pop(); count++;}
	            while(!b.empty()&&b.front()==x) {b.pop(); count++;}
	            ans+=x*count;
	        }
	    } 
	    while(!a.empty()) {s1+=a.front(); a.pop();}
	    while(!b.empty()) {s2+=b.front(); b.pop();}
	    ans+=max(s1,s2);
	    cout << ans << "\n";
	}
	return 0;
}
