#include<bits/stdc++.h>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n; cin >> n;
	    int a[n]={0};
	    for(int i = 0; i < n; i++) cin >> a[i];
	    int mn[n]={0}, mx[n]={0}, curMn = INT_MAX, curMx = INT_MIN;
	    for(int i = n-1; i >= 0; i--){
	        curMn = min(a[i], curMn);
	        mn[i] = curMn;
	    }
	    int f  = 0;
	    for(int i = 0; i < n; i++){
	        curMx = max(a[i], curMx);
	        if(curMx == a[i] && a[i] == mn[i] && i!=0 && i!=n-1) {f=i; break;}
	    }
	    if(f==0) cout << -1 << endl;
	    else cout << a[f] << endl;
	}
	return 0;
}
