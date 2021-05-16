#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n) time
pair<int, int> subArraySort(vector<int> arr){
    pair<int, int> result;
    result.first = INT_MAX;
    result.second = -1;
    
    int curMax = arr[0];
    int minCh = INT_MAX;
    int n = arr.size();
    int ind = 1;
    while(ind < n){
        int cur = arr[ind];

        if(cur >= curMax) curMax = cur;
        else{
            result.second = ind;
            if(cur < minCh){
                minCh = cur;
                int start = min(result.first-1, ind-1);
                while(arr[start] > cur && start > 0) start--;
                result.first = (start)?(start + 1):0;
            }
        }
        ind++;
    }
    return result;
}

int main(){
    vector<int> arr;
    // arr.assign({1,2,4,7,10,11,7,12,6,7,16,18,19});
    arr.assign({1,2,4,10,5,7,-1,17,100});
    pair<int, int> res = subArraySort(arr);
    cout << res.first << " " << res.second << "\n";
    sort(arr.begin()+res.first, arr.begin()+res.second+1);
    for(auto ele : arr) cout << ele << " ";
    return 0;
}