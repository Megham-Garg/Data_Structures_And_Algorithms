#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n,k; cin >> n >> k;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    for(int i = 0; i < n; i+=k){
	        int x = i;
	        int y = (x+k-1 < n-1)?x+k-1:n-1;
	        while(x < y) {swap(a+x, a+y); x++; y--;}
	    }
	    
	    for(int i = 0; i < n; i++) cout << a[i] << " ";
	    cout << "\n";
	}
	return 0;
}
