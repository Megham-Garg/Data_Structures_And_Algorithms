#include<bits/stdc++.h>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        int x; cin >> x;
	        ans = ans^x;
	    }
	    cout << ans << endl;
	}
	return 0;
}
// a^a = 0;
// a^0 = a;
