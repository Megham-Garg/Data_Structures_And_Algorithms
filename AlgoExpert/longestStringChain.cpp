#include <bits/stdc++.h>
using namespace std;

// O(n) space
// O(n*max(stringLength^2)) time
int longestChain(string ele, unordered_map<string, int>& memo, unordered_map<string, string>& next){
    string temp;
    for(int i = 0; i < ele.size(); i++){
        temp = ele;
        temp.erase(i+temp.begin());
        if(memo.find(temp) != memo.end() && memo[temp]==1) {
            memo[temp] = longestChain(temp, memo, next);
        }
        if(memo.find(temp) != memo.end() && memo[ele] < memo[temp]+1) {
            memo[ele] = memo[temp]+1;
            next[ele] = temp;
        }
    }
    return memo[ele];
}

void printChain(unordered_map<string, int>& memo, unordered_map<string, string>& next, int x){
    string c;
    for(auto it = memo.begin(); it != memo.end(); it++) if(it->second == x) {c = it->first; break;}
    while(next.find(c) != next.end()) {cout << c << " "; c = next[c];}
    cout << c;
    return;
}

int main()
{
    vector<string> strSet = {"abde", "abc", "abd", "abcde", "ade", "ae", "labde", "abcdef"};
    
    unordered_map<string, int> memo;
    unordered_map<string, string> next;
    for(auto ele : strSet) memo[ele] = 1;
    
    int maxLengthChain = 1;
    for(auto ele : strSet) if(memo[ele]==1) maxLengthChain = max(longestChain(ele, memo, next), maxLengthChain);
    
    for(auto ele : strSet) if(next.find(ele) != next.end()) cout << ele << " : " << next[ele] << "\n";
    
    cout << "\nmax chain length = " << maxLengthChain << "\n";
    
    printChain(memo, next, maxLengthChain);
    
    return 0;
}
