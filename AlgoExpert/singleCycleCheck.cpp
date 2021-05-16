#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
bool singleCycleCheck(vector<int> arr){
    int vis = 1;
    int n = arr.size();
    int cur = arr[0];

    while(vis < n && cur != 0){
        vis ++;
        cur = cur + arr[cur];
        cur = cur % n;
        if(cur < 0) cur = cur + n;
    }

    if(vis == n && cur == 0) return 1;
    return 0;
}
// cur = 0
// vis = 6
// n = 6

int main(){
    vector<int> arr = {1,-1,1,-1};
    cout << "single cycle check: " << singleCycleCheck(arr);
    return 0;
}