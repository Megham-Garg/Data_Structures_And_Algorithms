#include<bits/stdc++.h>
using namespace std;

void LIS_v1(vector<int>, int);
void LIS_v2(vector<int>, int);

int main(){
    vector<int> arr = {5,7,-24,12,10,2,3,12,5,6,35};
    LIS_v1(arr, arr.size());
    cout << "***********************\n";
    LIS_v2(arr, arr.size());
    return 0;
}

// O(n) space
// O(n^2) time
void LIS_v1(vector<int> arr, int n){
    if(!n) return;
    if(n == 1) {cout << "longest increasing subsequence : " << arr[0]; return;}
    vector<int> length(n,1);
    vector<int> prev(n,-1);
    int ind = 0;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j > -1; j--){
            if(arr[i] > arr[j] && length[i] < length[j] + 1) {
                length[i] = 1 + length[j];
                prev[i] = j;
            }
        }
        if(length[ind] < length[i]) ind = i;
    }

    cout << "length of max inc subseq is: " << length[ind] << "\n";
    
    while(ind!=-1){
        cout << arr[ind] << " ";
        ind = prev[ind];
    }cout << endl;
    return;
}

// O(n) space
// O(nlogn) time
// maxL 2
// IWL = -1 0 1
// prev= -1 0 -1 -1 -1 -1
// 1 0 -24
// 0
// -1
int lower_bound(int i, int j, int target, vector<int> arr, vector<int> IWL){
    int mid = (i+j)/2;
    int ans = -1;
    while(i <= j){
        if(arr[IWL[mid]] < target) {ans = mid; i = mid+1;}
        else {j = mid-1;}
        mid = (i+j)/2;
    }return ans;
}

void LIS_v2(vector<int> arr, int n){
    if(!n) return;
    if(n == 1) {cout << "longest increasing subsequence : " << arr[0]; return;}
    vector<int> IWL = {-1,0};
    vector<int> prev(n,-1);
    int maxL = 1, ind = 0;

    // 5,7,-24,12,10,2,3,12,5,6,35
    for(int i = 1; i < n; i++){
        ind = lower_bound(1, IWL.size()-1, arr[i], arr, IWL);
        if(ind == -1) IWL[1] = i;
        else if(ind == IWL.size()-1) IWL.push_back(i);
        else IWL[ind+1] = i;
        if(ind!=-1) prev[i] = IWL[ind];
        maxL = IWL.size()-1;
    }
    
    cout << "length of max inc subseq is: " << maxL << "\n";
    
    ind = IWL[maxL];
    while(ind!=-1){
        cout << arr[ind] << " ";
        ind = prev[ind];
    }
    return;
}