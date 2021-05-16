#include<bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n; cin >> n;
	    map<char, int> m;
	    vector<char> s;
	    while(n--){
	        char c;
	        cin >> c;
	        s.push_back(c);
	    }
	    queue<char> q;
	    
	    for(char c : s){
	        m[c]++;
	        if(m[c]<=1) q.push(c);
	        while(!q.empty() && m[q.front()] > 1) q.pop();
	        if(q.empty()) cout << -1 << " ";
	        else cout << q.front() << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
