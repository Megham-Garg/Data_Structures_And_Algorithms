#include<bits/stdc++.h>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    int a[n] = {0};
	    int sum=0;
	    map<int,int> m1;
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	        sum += a[i];
	        m1[sum]++;
	    }
	    int ans = 0;
	    for(auto it = m1.begin(); it!=m1.end(); it++)
	    {
	        if(!it->first) ans+=it->second;
	        int x = it->second;
	        x--;
	        if(x > 0) ans += (x*(x+1))/2;
	    }
	    cout << ans << "\n";
	}
	return 0;
}
