#include<bits/stdc++.h>
using namespace std;
int main(){
	int t = 0; cin >> t;
	while(t--){
	    int n, k; cin >> k >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    priority_queue<int, vector<int>, greater<int>> maxH;
	    int i = 0;
	    while(i < n){
	        int x; x=a[i++];
	        maxH.push(x);
	        if(maxH.size() < k) {cout << -1 << " ";}
	        else if(maxH.size() == k){cout << maxH.top() << " ";}
	        else{
	            maxH.pop();
	            cout << maxH.top() << " ";
	        }
	    }
	    cout << "\n";
	}
	return 0;
}
