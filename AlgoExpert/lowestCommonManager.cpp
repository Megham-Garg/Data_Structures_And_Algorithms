#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(n) space
char lowestCommonManager(unordered_map<char, vector<char>> adj, char a, char b, char manager){
    if(manager == a || manager == b) return manager;
    if(adj[manager].size() == 0) return ' ';
    bool f1 = false, f2 = false;
    for(auto ch : adj[manager]){
        char temp = lowestCommonManager(adj, a, b, ch);
        // cout << temp << "**" << "\n";
        if(temp == a) f1 = true;
        else if(temp == b) f2 = true;
        else if(temp!=' ') return temp;
        if(f1 && f2) return manager;
    }if(f1) return a;
    if(f2) return b;
    return ' ';
}

int main(){
    unordered_map<char, vector<char>> adj;
    adj['a'] = {'b','c','d','e','f'};
    adj['b'] = {'g','h','i'};
    adj['h'] = {'o','p','q','r'};
    adj['p'] = {'t','u'};
    adj['r'] = {'v'};
    adj['v'] = {'w','x','z'};
    adj['c'] = {'j'};
    adj['x'] = {'z'};
    adj['d'] = {'k','l'};
    adj['f'] = {'m','n'};
    cout << lowestCommonManager(adj, 'l', 'k', 'a');
    return 0;
}