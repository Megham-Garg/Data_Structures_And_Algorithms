#include<bits/stdc++.h>
using namespace std;
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n; cin >> n;
	    int pre[61] = {0};
	    int max = INT_MIN;
	    for(int i = 0; i < n; i++){
	        int x; cin >> x;
	        pre[x]++;
	        if(x > max) max = x;
	    }
	    map<int, vector<int>> fin;
	    for(int i = 0; i <= max; i++){
	        if(pre[i]!=0) fin[pre[i]].push_back(i);
	    }
	    for(auto it = fin.rbegin(); it!=fin.rend(); it++){
	        for(auto it1 = it->second.begin(); it1 != it->second.end(); it1++)
	        {
	            for(int i = 0; i < it->first; i++){
	                cout << *it1 << " ";
	            }
	        }
	    }
	    cout << "\n";
	}
	return 0;
}
