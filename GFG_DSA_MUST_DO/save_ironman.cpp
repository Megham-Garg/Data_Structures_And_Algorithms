#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	cin.ignore();
	while(t--){
	    string s; getline(cin, s);
	    string input = "";
	    for(auto ch : s) if(isalnum(ch)) input += tolower(ch);
	    string tempS = "";
	    int temp = input.length()/2;
	    while(temp--){
	        tempS+=input[input.length()-1];
	        input.pop_back();
	    }
	    if(input.length() != tempS.length()) input.pop_back();
	    if(input == tempS) cout << "YES\n";
	    else cout << "NO\n";
	}
	return 0;
}
