#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    for(int test = 1; test <= t; test++){
        int n; cin >> n;
        int mx=0; string ans = "";
        getline(std::cin, ans);
        ans = "";
        for(int i = 1; i <= n; i++){
            string name="";
            getline(std::cin, name);
            set<char> unch;
            unch.clear();
            for(char ch : name)
                if(ch != ' ') unch.insert(ch);
            if(unch.size() > mx ||
                (unch.size() == mx && ans > name)){
                ans = name;
                mx = unch.size();
            }
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }
}
