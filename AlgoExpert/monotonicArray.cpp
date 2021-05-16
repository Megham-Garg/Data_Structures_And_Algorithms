#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
bool isMonotonic(vector<int> arr){
    int curSmall = arr[0]; //assume smallest
    int changes = 0;
    int n = arr.size();
    for(int i = 1; i < n; i++){
        if(arr[i] <= curSmall) {
            curSmall = arr[i];
            changes++;
        }
    }
    return (changes == 0 || changes == n-1)?true:false;
}

int main(){
    vector<int> arr;
    arr.assign({-1, -5, -1100, -1100, -1101, -1002, -102});
    cout << isMonotonic(arr) << "\n";
    arr.assign({-1, -5, -1100, -1102});
    cout << isMonotonic(arr) << "\n";
    arr.assign({-1, -5, -1100, -1100, -1101, -1102});
    cout << isMonotonic(arr) << "\n";
    arr.assign({1, 5, 12, 16552});
    cout << isMonotonic(arr) << "\n";
}