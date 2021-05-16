#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b){
    int i=1,j=1;
    if(a/10!=0)i=2;
    if(a/100!=0)i=3;
    if(a/1000!=0)i=4;
    
    if(b/10!=0)j=2;
    if(b/100!=0)j=3;
    if(b/1000!=0)j=4;
    int x,y;
    x = a*pow(10,j)+b;
    y = b*pow(10,i)+a;
    if(x < y) return true;
    else return false;
}
int main(){
	int testCases = 0; cin >> testCases;
	map<pair<int,int>, bool> dp;
	while(testCases--){
	    int n; cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];
	    for(int i = 0; i < n; i++){
    	    for(int j = i+1; j < n; j++){
    	        bool f;
    	        if(dp.find(make_pair(a[i],a[j]))==dp.end()) dp[make_pair(a[i],a[j])] = compare(a[i],a[j]);
    	        f = dp[make_pair(a[i],a[j])];
    	        if(f){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
    	        }
    	    }
	    }
	    string s="";
	    for(int i = 0; i < n; i++) s+=to_string(a[i]);
	    cout << s << "\n";
	}
	return 0;
}
