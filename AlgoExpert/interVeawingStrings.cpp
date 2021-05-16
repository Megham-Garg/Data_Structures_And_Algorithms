#include<bits/stdc++.h>
using namespace std;

// aaa 
// aaaf
// aaafaaa

// with dp
// time O(n*m)
// space O(n*m)

// without dp
// time O(2^(n+m))
// space O(n+m)

bool interVeawingStringsHelper(string a, string b, string c, int cur_a, int cur_b, int cur_c, map<pair<int, int>, bool> &dp){
    pair<int, int> pr; pr.first = cur_a; pr.second = cur_b;
    if(dp.find(pr) != dp.end()) return dp[pr];
    
    bool res = false;
    if(a.size() == cur_a && b.size() == cur_b) res = true;
    else if(cur_a  == a.size()){
        if(b.substr(cur_b) == c.substr(cur_c)) res = true;
        else res = false;
    }
    else if(cur_b  == b.size()){
        if(a.substr(cur_a) == c.substr(cur_c)) res = true;
        else res = false;
    }
    else{
        if(c[cur_c] != a[cur_a] && c[cur_c] != b[cur_b]) res = false;
        else{
            res = res || interVeawingStringsHelper(a,b,c,cur_a+1,cur_b,cur_c+1,dp);
            res = res || interVeawingStringsHelper(a,b,c,cur_a,cur_b+1, cur_c+1,dp);
        }
    }
    dp[pr] = res;
    return dp[pr];
}

bool interVeawingStrings(string a, string b, string c){
    if(c.size()!=a.size()+b.size()) return false;
    else if(a==c && b.size()==0) return true;
    else if(b==c && a.size()==0) return true;
    else if(a.size()==0 || b.size()==0) return false;
    map<pair<int, int>, bool> dp;
    return interVeawingStringsHelper(a, b, c, 0, 0, 0, dp);
}

int main(){
    clock_t st;
	st = clock();
    bool f = interVeawingStrings("aaa", "aaaf", "aaafaaa");
    clock_t et;
	et = clock();
    cout << "Interveawing status: " << (f?"True":"False") << "\nprogram ended in " << et-st << endl;
    return 0;
}