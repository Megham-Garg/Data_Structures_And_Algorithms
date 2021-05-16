#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    while(n--){
        int x; cin >> x;
        if(minh.empty() && maxh.empty()) maxh.push(x);
        else if(minh.size() > maxh.size()){
            if(x > minh.top()){ maxh.push(minh.top()); minh.pop(); minh.push(x); }
            else { maxh.push(x); }
        }
        else if(maxh.size() > minh.size()){
            if(x < maxh.top()){ minh.push(maxh.top()); maxh.pop(); maxh.push(x); }
            else { minh.push(x); }
        }
        else{
            if(minh.top() > x) maxh.push(x);
            else minh.push(x);
        }
        
        if(maxh.size() == minh.size()) cout << (maxh.top()+minh.top())/2 << "\n";
        else if(maxh.size() > minh.size()) cout << maxh.top() << "\n";
        else cout << minh.top() << "\n";
    }
	return 0;
}
