#include<iostream>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	for(int i =1 ; i<=testCases ;i++){
	    int n; cin >> n;
	    int arr[n] = {0};
	    int ind = 0;
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	        if(i && arr[i] < arr[i-1]) ind = i-1;
	    }
	    int k,l,r; cin >> k;
	    int ans = -1;
	    if(arr[n-1] > k) {l = ind+1; r = n-1;}
	    else if(arr[n-1] < k) {l = 0; r = ind;}
	    else ans = n-1;
	    int m = (l+r)/2;
	    while(l <= r && ans==-1){
	        if(arr[m] > k) r = m-1;
	        else if(arr[m] < k) l = m + 1;
	        else {ans = m; break;}
	        m = (l+r)/2;
	    } 
	    cout << ans << endl;
	}
	return 0;
}
