#include<bits/stdc++.h>
using namespace std;


// O(buildings*blocks) space and time
int appartmentHunting(vector<char> buildings, unordered_map<int, unordered_set<char>> blocks){
    int myAppartment = -1, minimumDistance = INT_MAX;
    unordered_map<char, vector<int>> distancesFromBlocks;
    int total_blocks = blocks.size();
    for(auto building : buildings){
        distancesFromBlocks[building] = vector<int>(blocks.size(), -1);
        bool flag=0;
        for(int i = total_blocks - 1; i >= 0; i--){

            if(blocks[i].find(building)!=blocks[i].end())
                distancesFromBlocks[building][i] = 0; flag=1;
                
            else if(flag) distancesFromBlocks[building][i] =  distancesFromBlocks[building][i+1]+1;

        }
        for(int i = 1; i < total_blocks; i++){
            if(distancesFromBlocks[building][i]==-1)
                distancesFromBlocks[building][i] =  distancesFromBlocks[building][i-1]+1;
        }
    }

    for(int i = total_blocks - 1; i >= 0; i--){
        int currentDistance = INT_MIN;
        for(auto building: buildings){
            currentDistance = max(distancesFromBlocks[building][i], currentDistance);
        }
        if(minimumDistance > currentDistance){
            minimumDistance = currentDistance;
            myAppartment = i;
        }
    }
    return myAppartment;
}

int main(){
    vector<char> buildings;
    buildings = {'G', 'C', 'T'};
    unordered_map<int, unordered_set<char>> blocks;
    blocks[0] = {'C'};
    blocks[1] = {'G'};
    blocks[2] = {'G', 'C'};
    blocks[3] = {'C'};
    blocks[4] = {'C', 'T'};
    cout << appartmentHunting(buildings, blocks);
    return 0;
}
