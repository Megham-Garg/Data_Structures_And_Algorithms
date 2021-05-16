#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compareInterval(pair<int,int> i1, pair<int,int> i2) 
{ 
    return (i1.second < i2.second);
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    pair<int,int> activity[n];
	    for(int i = 0; i < n; i++) cin >> activity[i].first;
	    for(int i = 0; i < n; i++) cin >> activity[i].second;
	    sort(activity, activity+n, compareInterval);
	    int actCount = 0; int prev = 0;
	    for(int i = 0; i < n; i++){
	        if(activity[i].first >= prev) {actCount++; prev = activity[i].second;}
	    }
	    cout << actCount << "\n";
	}
	return 0;
}
