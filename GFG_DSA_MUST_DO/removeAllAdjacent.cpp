#include<bits/stdc++.h>
using namespace std;
bool anyDup(string s){
    for(int i = 0; i < s.size(); i++){
        if(i == 0 && s.size() > 1 && s[0]==s[1]) return true;
        if(i == s.size()-1 && i > 0 && s[i-1]==s[i]) return true;
        if(i > 0 && i < s.size()-1 && s[i]==s[i+1]) return true;
        if(i > 0 && i < s.size()-1 && s[i]==s[i-1]) return true;
    }return false;
}
void removeDup(string s,int pos, string &res, int n){
    if(pos < 0 || pos > n) return;
    if(pos==0 && n>=1 && s[pos]!=s[pos+1]) {res=""; res+=s[0]; }
    else if(pos==n-1 && pos>=1 && s[pos]!=s[pos-1]) {res+=s[pos];}
    else if(pos > 0 && pos < n-1 && s[pos]!=s[pos-1] && s[pos]!=s[pos+1]) {res+=s[pos];}
    removeDup(s,pos+1,res,n);
    if(pos==0 && anyDup(res)) {s = res; res = ""; removeDup(s,0,res,s.size());}
}
int main(){
	int t = 0; cin >> t;
	while(t--){
	    string s,res; cin >> s; ; removeDup(s,0,res,s.size());
	    cout << res << endl;
	}
	return 0;
}
