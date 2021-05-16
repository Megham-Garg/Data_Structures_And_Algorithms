#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int getMinDiff(int arr[], int n, int k) 
{ 
	if (n == 1) 
	return 0; 
	sort(arr, arr+n); 
	int ans = arr[n-1] - arr[0]; 
	int small = arr[0] + k; 
	int big = arr[n-1] - k; 
	if (small > big) swap(small, big);
	for (int i = 1; i < n-1; i ++) 
	{ 
		int subtract = arr[i] - k; 
		int add = arr[i] + k;
		if (subtract >= small || add <= big) 
			continue; 
		if (big - subtract <= add - small) 
			small = subtract; 
		else
			big = add; 
	} 

	return min(ans, big - small); 
} 

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> k >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    cout << getMinDiff(a, n, k) << "\n";
	}
	return 0;
}
