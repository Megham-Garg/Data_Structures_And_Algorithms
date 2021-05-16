#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string s; cin >> s;
	    int num = 0; int n = s.size();
	    for(int i = 0; i < n; i++){
	        if(s[i]=='I' && i+1 < n && s[i+1]=='V'){ num+=4;i++;}
	        else if(s[i]=='I' && i+1 < n && s[i+1]=='X'){ num+=9;i++;}
	        else if(s[i]=='X' && i+1 < n && s[i+1]=='C'){ num+=90;i++;}
	        else if(s[i]=='X' && i+1 < n && s[i+1]=='L'){ num+=40;i++;}
	        else if(s[i]=='C' && i+1 < n && s[i+1]=='M') {num+=900;i++;}
	        else if(s[i]=='C' && i+1 < n && s[i+1]=='D') {num+=400;i++;}
	        else if(s[i] == 'I') num+=1;
	        else if(s[i] == 'V') num+=5;
	        else if(s[i] == 'X') num+=10;
	        else if(s[i] == 'L') num+=50;
	        else if(s[i] == 'C') num+=100;
	        else if(s[i] == 'D') num+=500;
	        else if(s[i] == 'M') num+=1000;
	    } cout << num << "\n";
	}
	return 0;
}
