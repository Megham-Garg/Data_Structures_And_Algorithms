#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compareInterval(pair<pair<int,int>,int> i1, pair<pair<int,int>,int> i2) 
{ 
    return ((i1.first).second < (i2.first).second);
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    pair<pair<int,int>,int> activity[n];
	    for(int i = 0; i < n; i++) cin >> (activity[i].first).first;
	    for(int i = 0; i < n; i++){
	        cin >> (activity[i].first).second;
	        activity[i].second = i;
	    }
	    sort(activity, activity+n, compareInterval);
	    int prev = 0;
	    for(int i = 0; i < n; i++){
	        if((activity[i].first).first >= prev) {
	            cout << activity[i].second + 1 << " ";
	            prev = (activity[i].first).second;
	        }
	    }cout << "\n";
	}
	return 0;
}
