#include<bits/stdc++.h>
using namespace std;

// O(ns) space
// O(nslog(s)) time
vector<vector<string>> groupAnagrams(vector<string> arr){
    unordered_map<string, vector<string>> mp;
    for(auto str: arr){
        string tmp = str;
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(str);
    }
    vector<vector<string>> res;
    for(auto it = mp.begin(); it!=mp.end(); it++){
        res.push_back(it->second);
    }
    return res;
}

int main(){
    return 0;
}