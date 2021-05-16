#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(string &str, int a, int b){
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}
vector<string> op;
void printPerm(string input, int pos, string cur){
    if(pos == input.size()) {op.push_back(cur); return;}
    for(int ptr = pos; ptr < input.size(); ptr++){
        cur+=input[ptr];
        swap(input, ptr, pos);
        printPerm(input, pos+1, cur);
        cur.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 0; cin >> t;
	while(t--){
	    op.clear();
	    string input; cin >> input;
	    printPerm(input, 0, "");
	    sort(op.begin(), op.end());
	    for(auto perm : op) cout << perm << " ";
	    cout << "\n";
	}
	return 0;
}
