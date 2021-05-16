#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        std::vector<int> arr; for(int i = 1; i <= n; i++) arr.push_back(-i);
        arr[0] = 1;
        int sum = 1, i = 1; k--;
        while(k && i < n){
            if(i == n-1) {arr[i]*=-1; k--; break;}
            else if(sum - arr[i] > - arr[i+1]) {sum+=arr[i]; i++;}
            else {sum+=-arr[i]; arr[i]*=-1; i++; k--;}
        }
        i = n-1;
        while(k && i >= 0){
            if(arr[i] < 0) {k--; arr[i]*=-1;}
            i--;
        }
        for(auto i : arr) cout << i << " ";
        cout << endl;
    }
	return 0;
}
