#include<bits/stdc++.h>
using namespace std;

int waysChangeHelper(vector<int> coins, int target, int end, map<pair<int,int>, int> &memo){
    int ans = 0;
    if(end == -1) ans = 0;
    else if(target == 0) ans = 1;
    else if(coins[end] > target) {
        pair<int, int> temp = make_pair(end-1, target);
        if(memo.find(temp) != memo.end())
            ans = memo[temp];
        else
        {
            memo[temp] = waysChangeHelper(coins, target, end-1, memo);
            ans = memo[temp];
        }
    }
    else{
        while(target>0){
            pair<int, int> temp = make_pair(end-1, target);
            if(memo.find(temp) != memo.end())
                ans += memo[temp];
            else{
                memo[temp] = waysChangeHelper(coins, target, end-1, memo);
                ans += memo[temp];
            }
            target -= coins[end];
        }
        if(target==0) ans+=1;
    }
    pair<int, int> pr = make_pair(end, target);
    memo[pr] = ans;
    return ans;
}

int waysChange(vector<int> coins, int target){
    map<pair<int, int>, int> memo;
    return waysChangeHelper(coins, target, coins.size()-1, memo);
}

int main(){
    vector<int> coins = {1,5,10,25};
    cout << waysChange(coins, 10);
    return 0;
}