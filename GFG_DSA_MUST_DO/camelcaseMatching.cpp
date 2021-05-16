#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int match(string s2, string s1) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return i; 
    } 
    return -1; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    int n; cin >> n;
	    vector<string> arr(n), inputs(n), res;
	    for(int i = 0; i < n; i++){
	        string temp; cin >> temp;
	        inputs[i] = temp;
	        arr[i]="";
	        for(auto ch : temp) if(int(ch) < 97) arr[i]+=ch;
	    }string patt; cin >> patt;
	    for(int i = 0; i < n; i++)
	        if(match(arr[i], patt)!=-1) res.push_back(inputs[i]);
	    for(auto str : res) cout << str << " ";
	    if(res.empty()) cout << "No match found";
	    cout << "\n";
	}
	return 0;
}
