#include<bits/stdc++.h>
using namespace std;


// O(2^n*n) space
// O(2^n*n) time
// [1,2,3]
void powerSet_v2(vector<int> arr, vector<vector<int>>& ps){
    if(arr.size()==0) return;
    for(int i = 0; i < arr.size(); i++){
        vector<int> temp;
        int end = ps.size();
        for(int j = 0; j < end; j++) {
            temp = ps[j];
            temp.push_back(arr[i]);
            ps.push_back(temp);
        }
    }
    return;
}

int main(){
    vector<vector<int>> ps;
    ps.push_back(vector<int>(0));
    powerSet_v2({1,2,3}, ps);
    // visual
    for(auto ele : ps) {
        cout << "** ";
        for(auto num : ele) {cout << num << " ";}
        cout << "**\n";
    }
    return 0;
}