#include <bits/stdc++.h> // Include every standard library 
using namespace std;

// worst case O(n^3)

// O(n^2) time
// O(n^2) space
set<vector<int>> fourNumberSum(vector<int> arr, int targetSum){
    map<int, vector<pair<int, int>>> mp;
    
    for(int i = 0; i < arr.size()-1; i++)
    for(int j = i+1; j < arr.size(); j++)
        mp[arr[i]+arr[j]].push_back(make_pair(arr[i], arr[j]));
    
    set<vector<int>> result;
    
    for(int i = 0; i < arr.size()-1; i++)
        for(int j = i+1; j < arr.size(); j++){
            if(mp.find(targetSum - arr[i] - arr[j]) != mp.end()){
                for(auto pr : mp[targetSum - arr[i] - arr[j]]){
                    if(arr[i] == pr.first || arr[i]== pr.second) continue;
                    if(arr[j] == pr.first || arr[j]== pr.second) continue;
                    vector<int> quad;
                    quad.assign({arr[i], arr[j], pr.first, pr.second});
                    sort(quad.begin(), quad.end());
                    result.insert(quad);
                }
            }
        }

    return result;
}

// O(n^2) time
// O(n^2) space
void fourNumberSum2(vector<int> arr, int targetSum){
    map<int, vector<pair<int, int>>> mp;
    // 7, 6, 4, -1, 1, 2
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            if(mp.find(targetSum - arr[i] - arr[j])!=mp.end()){
                for(auto pr : mp[targetSum - arr[i] - arr[j]]){
                    
                    cout << arr[i] << " " << arr[j] << " " << pr.first << " " << pr.second;
                    cout << "\n";
                }
            }
        }
        
        for(int j = 0; j < i; j++) mp[arr[i] + arr[j]].push_back(make_pair(arr[i], arr[j]));
    }
}

int main(){
    vector<int> arr;
    arr.assign({7,6,4,-1,1,2});
    // set<vector<int>> res = fourNumberSum(arr, 16);
    fourNumberSum2(arr, 16);
    // for(auto quad : res){
    //     for(auto ele : quad){
    //         cout << ele << " ";
    //     }
    //     cout << "\n";
    // }
}