#include<bits/stdc++.h>
using namespace std;
// there are three approaches to solve this
// O(n) space O(n) time
int minRewards(vector<int> score){
    int n = score.size();
    int reward[n]={0};
    set<int> peak;
    int totalRewards = 0;
    for(int i = 0; i < n; i++){
        if(i==n-1 && score[i] < score[i-1]){
            peak.insert(i);
            reward[i] = 1;
        }
        else if(i==0 && score[0] < score[1]){
            peak.insert(i);
            reward[i] = 1;
        }
        else if(score[i] < score[i+1] && score[i] < score[i-1]){
            peak.insert(i);
            reward[i] = 1;
        }
    }
    
    for(auto ind : peak){
        int left = ind-1;
        while(left > 0 and score[left] <= score[left-1]){
            reward[left] = 1 + reward[left+1];
            left--;
        }
        if(left == 0 && peak.find(0)==peak.end()) reward[0] = reward[1]+1;
        else if(left!=0 && score[left] > score[left-1]) reward[left] = max(reward[left], reward[left+1]+1);

        int right = ind+1;
        while(right < n-1 and score[right] <= score[right+1]){
            reward[right] = 1 + reward[right-1];
            right++;
        }
        if(right == n-1 && peak.find(n-1)==peak.end()) reward[n-1] = reward[n-2]+1;
        else if(right!=n-1 && score[right] > score[right+1]) reward[right] = max(reward[right], reward[right-1]+1);
    }
    for(auto ele : reward) {totalRewards+=ele; cout << ele << " ";}
    cout << "\n";
    return totalRewards;
}

// approach 3
// one iteration towards left
// one iteration towards right
// O(n) time O(n) space

int main(){
    vector<int> scores;
    // scores.assign({4,8,4,2,1,3,6,7,91,15,12});
    scores.assign({8,4,2,1,3,6,7,9,5});
    cout << minRewards(scores);
    return 0;
}