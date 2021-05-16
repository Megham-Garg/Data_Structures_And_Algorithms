#include <bits/stdc++.h>
using namespace std;
int getMinKey(int keys[], int aKeys[], int n){
    int mn = INT_MAX, mnI = -1;
    for(int i = 0; i < n; i++){
        if(mn > keys[i] && aKeys[i]==0){mnI = i; mn = keys[i];}
    }
    return mnI;
}
int getMinAKey(int a[], int b[], int k, int ind, int &ans){
    int x=-1,y=-1;
    if(ind-1 >= 0) x = b[ind-1];
    if(ind+1 < k) y = b[ind+1];
    if(x!=-1 && y!=-1){
        if(x==0 && y==0) return 1;
        else if(x==0){
            if(y>=4){ans++; return 1;}
            else return y+1;
        }
        else if(y==0){
            if(a[ind-1]==a[ind]) return x;
            if(x>=4){ans++; return 1;}
            else return x+1;
        }
        else{
            if(a[ind-1]==a[ind]){
                if(x>y){return x;}
                else {ans++; return x;}
            }
            if(max(x,y) >= 4) {ans++; return 1;}
            else return max(x,y)+1;
        }
    }
    else if(x!=-1){
        if(a[ind-1]==a[ind]) return x;
        if(x>=4) {ans++; return 1;}
        else return x+1;
    }
    else if(y!=-1){
        if(y>=4) {ans++; return 1;}
        else return y+1;
    }
    else return 1;
}
int main(){
    int t; cin >> t;
    for(int p = 1; p <= t; p++){
        int k, ans = 0; cin >> k; int keys[k]={0};
        for(int i = 0; i < k; i++) cin >> keys[i];
        int aKeys[k] = {0};
        int ind = getMinKey(keys, aKeys, k);
        while(ind!=-1){
            aKeys[ind] = getMinAKey(keys, aKeys, k, ind, ans); // assign that index the minimum alien key possible
            ind = getMinKey(keys, aKeys, k); // get index of minimum origin unassigned key
        }
        cout << "Case #" << p << ": " << ans << "\n";
    }
    return 0;
}
