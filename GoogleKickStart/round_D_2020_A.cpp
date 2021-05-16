#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int p = 1; p <= t; p++){
        int n; cin >> n;
        int v[n]={0};
        for(int i = 0; i < n; i++) cin >> v[i];
        int count = 0;
        int cur = INT_MIN;
        for(int i = 0; i < n; i++){
            bool f = false;
            if(i==0 && 1 < n && v[1] < v[0]) f = true;
            else{
                if(v[i] > cur &&
                (i == n-1 || (i < n-1 && v[i] > v[i+1]) ) ) f = true;
            }
            cur = max(cur,v[i]);
            if(f) count++;
        }
        cout << "Case #" << p << ": " << count << "\n";
    }
    return 0;
}
