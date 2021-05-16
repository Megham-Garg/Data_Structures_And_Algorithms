#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int p = 1; p <= t; p++){
        int n,q; cin >> n >> q; int door[n-1]={0};
        for(int i = 0; i < n-1; i++) cin >> door[i];
        cout << "Case #" << p << ": ";
        while(q--){
            int a,b; cin >> a >> b;
            if(a==1) {cout << b << " "; continue;}
            else if(a==n) {cout << a-b+1 << " "; continue;}
            int vis[n]={0};
            vis[a-1]=1;
            b--;
            int curRoom = a-1;
            int left = curRoom;
            int right = curRoom;
            while(left > 0 && vis[left]!=0) left--;
            while(right < n && vis[right]!=0) right++;
            while(b){
                int small = INT_MAX;
                bool f1,f2;
                f1 = (left!=curRoom && vis[left]==0 && door[left] < small);
                if(f1) {small = door[left]; curRoom = left;}
                f2 = (right!=curRoom && vis[right]==0 && door[right-1] < small);
                if(f2) {small = door[right-1]; curRoom = right;}
                if(f1 && !f2 && left > 0) left--;
                else if(f2 && right < n) right++;
                vis[curRoom]=1;
                b--;
            }
            cout << curRoom+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
