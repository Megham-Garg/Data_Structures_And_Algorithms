#include<bits/stdc++.h>
using namespace std;

// [12, 3, 1, 2, -6, 5, -8, 6]
// 8
void threeNumberSum(vector<int> arr, int targetSum){
    // need to handle duplicated in this approach by maintaining a set of ordered triplets
    // O(n^2) time
    // O(n^2) space
    unordered_map<int, vector<pair<int, int>>> mp;
    int n = arr.size();

    for(int i = 0; i < n-1; i++)
    for(int j = i + 1; j < n; j++)
        mp[arr[i] + arr[j]].push_back(make_pair(min(arr[i],arr[j]), max(arr[i],arr[j])));
    
    for(auto ele : arr){
        int x = targetSum - ele;
        if(mp.find(x)!=mp.end()){
            for(auto pr : mp[x])
                if(pr.first != ele && pr.second != ele)
                    cout << ele << " " << pr.first << " " << pr.second<< endl;
        }
    }
}
// approach 1
// nested loop
// O(n^3) time and O(1) space

// approach 2
// hash O(n*n*log(n)) time and O(n*n) space

// approach 3
// sort

void threeNumberSumSpecial(vector<int> arr, int targetSum){
    // O(n^2) time
    // O(n) space for storing triplets
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int cur = 0;
    while (cur < n-2){
        int left = cur+1, right = n-1;
        while(left < right){
            if(arr[left]+arr[right]+arr[cur] < targetSum) left++;
            else if(arr[left]+arr[right]+arr[cur] > targetSum) right--;
            else cout << arr[cur] << " " << arr[left++] << " " << arr[right--] << endl;
        }
        cur++;
    }
}

int main(){
    vector<int> arr;
    arr.push_back(12);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(-6);
    arr.push_back(5);
    arr.push_back(-8);
    arr.push_back(6);
    // [12, 3, 1, 2, -6, 5, -8, 6]
    threeNumberSumSpecial(arr, 0);
    return 0;
}