#include<iostream>
using namespace std;
int getChar(string str, char c){
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == c) continue;
        if(i == 0 || i == str.size()-1) return i;
        else if(str[i-1]!=str[i+1]) return i;
    }
    return -1;
}
int main(){
	int testCases = 0;
	cin >> testCases;
	while(testCases--){
	    string str; cin >> str;
	    bool f = true;
	    if(str.size()<2) {cout << 1 << "\n"; continue;}
	    for(int i = 0; i < str.size()-1 && f; i++){
	        if(str[i] ==  str[i+1]){
	            int ind = getChar(str, str[i]);
	            if(ind == -1) {f = 0; break;}
	            str.insert(i+1,1,str[ind]);
	            if(i > ind) str.erase(str.begin()+ind);
	            else if(i < ind) str.erase(str.begin()+ind+1);
	           // cout << "\n-" << str << "-\n";
	        }
	    }
	    cout << f << "\n";
	}
	return 0;
}
