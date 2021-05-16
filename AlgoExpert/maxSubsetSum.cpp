#include<bits/stdc++.h>
using namespace std;

int maxSubsetSum(vector<int> arr){
    int n = arr.size();
    if(!n) return INT_MIN;
    int a = arr[0];
    if(n<2) return a;
    int b = max(arr[0], arr[1]), temp;
    if(n == 2) return b;
    for(int j = 2; j < n; j++){
        temp = b;
        b = max(a+arr[j], b);
        a = temp;
    }
    return b;
}

int main (){
    vector<int> test = {7,10,12,7,9,14};
    cout << maxSubsetSum(test);
}