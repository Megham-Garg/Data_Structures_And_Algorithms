#include<bits/stdc++.h>
using namespace std;

// O(n) time and space
int waterArea(vector<int> build){
    if(build.size() < 3) return 0;
    vector<int> stored(build.size(), 0);
    int curMax = build[0];
    for(int i = 1; i < build.size()-1; i++){
        if(curMax > build[i]) stored[i] = curMax - build[i];
        else curMax = build[i];
    }
    // for(auto ele : stored) cout << ele << " ";
    // cout << endl;
    curMax = build[build.size()-1];
    for(int i = build.size()-2; i > 0; i--){
        if(curMax > build[i]) stored[i] = min(curMax - build[i], stored[i]);
        else curMax = build[i];
    }
    for(auto ele : stored) cout << ele << " ";
    cout << endl;
    return accumulate(stored.begin(), stored.end(), 0);
}

int main(){
    vector<int> build = {0,8,0,0,5,0,0,10,0,0,1,1,0,3};
    cout << waterArea(build) << endl;
    return 0;
}