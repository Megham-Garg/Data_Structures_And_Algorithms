#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int m,n; cin >> m >> n;
	    bool arr[m][n] = {0};
	    bool mpr[m] = {0}, mpc[n] = {0};
	    for(int i = 0; i < m; i++)
	    for(int j = 0; j < n; j++) {
	        cin >> arr[i][j];
	        if(arr[i][j]){
	            mpr[i]=1;
	            mpc[j]=1;
	        }
	    }
	    for(int i = 0; i < m; i++)
    	    for(int j = 0; j < n; j++)
    	        if(mpr[i] || mpc[j]) arr[i][j]=1;
	    
	    for(int i = 0; i < m; i++){
    	    for(int j = 0; j < n; j++){
    	        cout << arr[i][j] << " ";
    	    }
    	    cout << "\n";
	    }
	}
	return 0;
}
