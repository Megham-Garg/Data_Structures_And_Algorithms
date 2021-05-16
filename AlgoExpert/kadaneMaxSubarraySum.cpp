//O(n) time
#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n) time
int kadaneAlgorithm(vector<int> arr){
    if(arr.size() < 1) return 0;
    int maxSum = INT_MIN;
    int prevSum = 0;
    for(auto ele : arr){
        if(ele + prevSum >= ele) prevSum = ele + prevSum;
        else prevSum = ele;
        if(maxSum < prevSum) maxSum = prevSum;
    }
    return maxSum;
}

int main(){
    vector<int> arr = {3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4};
    cout << "max sub-array sum : " << kadaneAlgorithm(arr);
    return 0;
}