#include<bits/stdc++.h>
using namespace std;

// O(min(n,m)) space n:len(str) m:no. of unique letters in str
// O(n) time
pair<int, int> longestSubstringNoDuplicate(string str){
    pair<int, int> res = make_pair(-1,-1);
    if(str.size()==0) return res;
    unordered_map<char, int> memo;
    int start = 0;
    int end = 0;
    for(end; end < str.size(); end++){
        if(memo.find(str[end])!=memo.end() && memo[str[end]]!=-1){
            if(res.second - res.first + 1 <= end - start){
                res.first = start;
                res.second = end - 1;
            }
            while(start <= memo[str[end]]) memo[str[start++]]=-1;
        }
        memo[str[end]] = end;
    }
    if(res.second - res.first + 1 <= end - start){
        res.first = start;
        res.second = end - 1;
    }
    return res;
}

int main(){
    string str = "clementisacap";
    pair<int, int> res = longestSubstringNoDuplicate(str);
    cout << res.first << " " << res.second << " " << str.substr(res.first, res.second-res.first+1) << "\n";
    return 0;
}