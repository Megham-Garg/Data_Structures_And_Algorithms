#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    string a,b,c="",d="";
	    cin >> a >> b;
	    bool f = false;
	    for(int i = 2; i < a.size(); i++) c+=a[i];
	    c+=a[0]; if(a.size()>1) c+=a[1]; 
	    
	    if(a.size()>2) {d+=a[a.size()-2]; d+=a[a.size()-1];}
	    for(int i = 0; i < a.size()-2; i++) d+=a[i];
	   // cout << a << " "  << b << " "  << c << " " << d;
	    if(a.size()!=b.size()) f=0;
	    else if(c==b || d==b) f=1;
	    cout << f << "\n";
	}
	return 0;
}
