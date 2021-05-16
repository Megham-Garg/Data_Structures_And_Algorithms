#include<bits/stdc++.h>
using namespace std;

bool twoNumberSum(vector<int> arr, int targetSum){
    set<int> mp;
    for(auto ele : arr){
        if(mp.find(targetSum - ele) != mp.end()) {
            cout << ele << " " << targetSum - ele << endl;
            return true;
        }
        else mp.insert(ele);
    }
    return false;
}
// approach 1
// nested loop
// O(n^2) time and O(1) space

// approach 2
// hash O(n) time and O(n) space

// approach 3
// sort it first
// O(n*log(n)) time and O(1) space
int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(-4);
    arr.push_back(8);
    arr.push_back(11);
    arr.push_back(1);
    arr.push_back(-1);
    arr.push_back(6);
    cout << twoNumberSum(arr, 10);
    return 0;
}