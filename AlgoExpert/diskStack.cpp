#include<bits/stdc++.h>
using namespace std;

struct disk{
    int w;
    int d;
    int h;
    disk(int w1, int d1, int h1) : w(w1), d(d1), h(h1) {}
};

bool sort_key(const disk& d1, const disk& d2){
    return (d1.h < d2.h);
}

bool larger(const disk& d1, const disk& d2){
    // returns true if d2 > d1
    return ((d1.w < d2.w) && (d1.d < d2.d) && (d1.h < d2.h));
}

// O(n) space
// O(n^2) time
int maxStackHeight(vector<disk> arr, int n){
    if(!n) return 0;
    int maxH = arr[0].h;
    unordered_map<int, int> isStacked;
    isStacked[0] = arr[0].h;

    for(int i = 1; i < n; i++){
        int curH = 0;
        for(int j = 0; j < i; j++){
            if(isStacked[j]!=-1 && larger(arr[j], arr[i])) {
                curH = max(curH, isStacked[j]);
                isStacked[j] = -1;
            }
        }
        
        isStacked[i] = arr[i].h + curH;
        maxH = max(isStacked[i], maxH);
    }
    return maxH;
}

int main(){
    vector<disk> arr = {disk(2,2,1), disk(2,1,2), disk(3,2,3), disk(2,3,4), disk(4,4,6), disk(2,2,8)};
    sort(arr.begin(), arr.end(), sort_key);
    cout << "max stack height is: " << maxStackHeight(arr, arr.size()) << endl;
    return 0;
}