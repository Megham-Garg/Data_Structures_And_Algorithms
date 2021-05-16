#include<bits/stdc++.h>
using namespace std;


// O(n) time
// O(1) space
void longestPeak(vector<int> arr){
    int n = arr.size();
    if(n<3) return;
    int maxL = 0, maxPeak = -1;
    int leftTail = 0, rightTail = 0, curPeak = -1;
    for(int i = 1; i < n; i++){
        cout << leftTail << " "  << rightTail << " " << arr[curPeak] << "\n";/
        int prev = arr[i-1];
        int cur = arr[i];

        if(cur > prev){
            if(curPeak == -1){leftTail++;}
            else{
                if(maxL < leftTail+1+rightTail){
                    maxPeak = curPeak;
                    maxL = max(maxL, leftTail+1+rightTail);
                }
                leftTail = 1;
                rightTail = 0;
                curPeak = -1;
            }
        }
        else if(cur < prev) {
            if(curPeak==-1 && leftTail) curPeak = i-1;
            rightTail++;
            if(i == n-1 && curPeak!=-1 && maxL < leftTail+1+rightTail){
                maxPeak = curPeak;
                maxL = max(maxL, leftTail+1+rightTail);
            }
        }
        else{
            if(curPeak!=-1 && maxL < leftTail+1+rightTail){
                maxPeak = curPeak;
                maxL = max(maxL, leftTail+1+rightTail);
            }
            leftTail = 0;
            rightTail = 0;
            curPeak = -1;
        }
    }
    std::cout << "max length of peak is: "  << maxL << " at: " << arr[maxPeak] << "\n";
}

int main(){
    vector<int> arr;
    // arr.assign({1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3});
    arr.assign({1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5});
    longestPeak(arr);
    return 0;
}