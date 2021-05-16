#include<bits/stdc++.h>
using namespace std;

void giveDen(int n, const int cur[]){
    if(n == 0) return;
    for(int i = 9; i >= 0; i--){
        if(cur[i] <= n){
            cout << cur[i] << " ";
            giveDen(n - cur[i], cur);
            break;
        }
    }
}

int main()
 {
	int t = 0; cin >> t;
	int cur[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	while(t--){
	    long n; cin >> n;
	    giveDen(n, cur);
	    cout << endl;
	}
	return 0;
}
