#include<bits/stdc++.h>
using namespace std;


// O(n!*n) space and time
void permutationHelper(string str, vector<string>& perms, int ind){
    if(ind == str.size()-1){
        perms.push_back(str);
        return;
    }
    for(int i = ind; i < str.size(); i++){
        swap(str[i], str[ind]);
        permutationHelper(str, perms, ind+1);
        swap(str[ind], str[i]);
    }
    return;
}
// abc
vector<string> permute(string str){
    vector<string> perm;
    permutationHelper(str, perm, 0);
    return perm;
}

int main(){
    vector<string> p = permute("abc");
    for(auto ele : p) cout << ele << " ";
    return 0;
}