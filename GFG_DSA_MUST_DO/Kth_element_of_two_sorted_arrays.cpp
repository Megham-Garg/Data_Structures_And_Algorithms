#include<iostream>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n,m,k; cin >> n >> m >> k;
	    int a[n] = {0},b[m] = {0};
	    int final[k] = {0};
	    for(int i = 0; i < n; i++) cin >> a[i];
	    for(int i = 0; i < m; i++) cin >> b[i];
	    int i = 0, j = 0, pos = 0;
	    while(i < n && j < m){
	        if(pos == k) break;
	        if(a[i] < b[j]) final[pos++] = a[i++];
	        else final[pos++] = b[j++];
	    }
	    while(pos!=k && i < n) final[pos++] = a[i++];
	    while(pos!=k && j < m) final[pos++] = b[j++];
	    cout << final[k-1] << endl;
	}
	return 0;
}
