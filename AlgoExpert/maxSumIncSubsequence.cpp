#include<bits/stdc++.h>
using namespace std;

vector<int> maxSumIncSubsequence(vector<int> arr){
    if(arr.size() == 0) return vector<int>(0);
    vector<int> maxSumAtIndex(arr.size(), INT_MIN);
    vector<int> sequence(arr.size(), -1);
    vector<int> result;
    int seq_ind = 0;

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && maxSumAtIndex[j]+arr[i] > maxSumAtIndex[i]){
                maxSumAtIndex[i] = maxSumAtIndex[j] + arr[i];
                sequence[i] = j;
            }
        }
        if(maxSumAtIndex[i] == INT_MIN) {
            maxSumAtIndex[i] = arr[i];
        }
        if(maxSumAtIndex[seq_ind] < maxSumAtIndex[i]) seq_ind = i;
    }

    while(seq_ind >= 0){
        result.push_back(seq_ind);
        seq_ind = sequence[seq_ind];
    }
    return result;// *max_element(maxSumAtIndex.begin(), maxSumAtIndex.end());
}

int main(){
    vector<int> arr = {8,12,2,3,15,5,7};
    //                -1  0 -1 2 1 3 5
    vector<int> seq = maxSumIncSubsequence(arr);
    for(auto pos: seq){
        cout << pos << " ";
    }cout << "\n";
    return 0;
}