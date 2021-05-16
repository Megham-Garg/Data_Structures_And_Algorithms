#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n) time
int minJumps(vector<int> arr){
    int n = arr.size()-1;
    if(n < 1) return 0;
    int ans = 0;
    int reach = arr[0];
    int steps = arr[0];
    int cur = 1;
    while(cur < n){
        if(reach < cur+arr[cur]){
            reach = cur+arr[cur];
        }
        steps--;
        if(!steps) {
            ans++;
            steps = reach - cur;
        }
        cur++;
    }
    return ans+1;
}

int main(){
    vector<int> jump = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
    cout << minJumps(jump);
    return 0;
}