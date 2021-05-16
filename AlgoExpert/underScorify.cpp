#include<bits/stdc++.h>
using namespace std;

// O(N*(N+M)) time
// O(N+M) space

vector<pair<int, int>> getLocations(string main, string sub){
    vector<pair<int, int>> ans(0);
    int found = main.find(sub);
    while (found < main.size() && found >= 0){
        ans.push_back(make_pair(found, found + sub.size() - 1));
        found = main.find(sub, found + 1);
    }
    return ans;
}

vector<pair<int, int>> mergeLocations(vector<pair<int, int>> location){
    if(location.size()==0) return location;
    vector<pair<int, int>> ans;
    ans.push_back(location[0]);\
    for(auto ele : location){
        if(ele.first - ans[ans.size()-1].second < 3){
            ans[ans.size()-1].second = ele.second;
        }
        else{
            ans.push_back(ele);
        }
    }
    return ans;
}

string underscorify(string main, string sub){
    string ans = "";
    vector<pair<int, int>> location = getLocations(main, sub);
    location = mergeLocations(location);
    unordered_set<int> underscore;
    for(auto ele : location) {underscore.insert(ele.first); underscore.insert(ele.second+1);}
    int ind = 0;
    while(ind < main.size()){
        if(underscore.find(ind) != underscore.end()){ans.push_back('_');}
        ans.push_back(main[ind++]);
    }
    if(underscore.find(main.size()) != underscore.end()){ans.push_back('_');}
    return ans;
}

int main(){
    cout << underscorify("test this is a testtest to see if testestest worktest", "test");
    return 0;
}