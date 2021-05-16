#include<bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > threeLargest(vector<int> array){
    priority_queue <int, vector<int>, greater<int> > res;
    for(auto num : array){
        if(res.size()<3) res.push(num);
        else if(res.top() < num){
            res.pop();
            res.push(num);
        }
    }
    return res;
}
// O(n) space
// O(1) time

int main(){
    priority_queue <int, vector<int>, greater<int> > ans = threeLargest({141,1,17,-7,-17,18,153,25,45,656,99,10});
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}