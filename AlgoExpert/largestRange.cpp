#include<bits/stdc++.h>
using namespace std;

// there is O(1) space and O(nlogn) time approach
// by sorting the array first

// O(n) space
// O(n) time
pair<int, int> largestRange(vector<int> arr){
    unordered_map<int, bool> mp;
    pair<int, int> res;
    res.first = INT_MAX;
    res.second = INT_MAX;
    for(auto ele : arr){
        mp[ele] = true;
    }
    for(auto ele : arr){
        if(!mp[ele]) continue;
        int start = ele;
        int end = ele;
        while(mp[start]){
            mp[start] = false;
            start--;
        }start++;
        mp[ele] = true;
        while(mp[end]){
            mp[end] = false;
            end++;
        }end--;
        if(end - start > res.second - res.first){
            res.first = start;
            res.second = end;
        }
    }
    return res;
}

int main(){
    vector<int> arr;
    arr.assign({1,11,3,0,15,5,2,4,10,7,12,6});
    pair<int, int> pr = largestRange(arr);
    cout << pr.first << " " << pr.second;
    return 0;
}