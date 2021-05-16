#include<bits/stdc++.h>
using namespace std;

// O(1) space
// O(n^2) time
pair<int, int> longestPalSubstring(string str){
    int start = -1;
    int end = -1;
    for(int i = 0; i < str.size(); i++){
        int tempStart = i;
        int tempEnd = i;
        while(tempStart > -1 && tempEnd < str.size() && str[tempStart] == str[tempEnd]){
            tempStart--;
            tempEnd++;
        }
        if(tempEnd-1-tempStart > end-start+1) {start=tempStart+1; end=tempEnd-1;}
        if(i == str.size() || str[i] != str[i+1]) continue;
        tempStart = i;
        tempEnd = i+1;
        while(tempStart > -1 && tempEnd < str.size() && str[tempStart] == str[tempEnd]){
            tempStart--;
            tempEnd++;
        }
        if(tempEnd-1-tempStart > end-start+1) {start=tempStart+1; end=tempEnd-1;}
    }
    return make_pair(start, end);
}

int main(){
    pair<int, int> pr = longestPalSubstring("abaxyzzyxf");
    cout << pr.first << " " << pr.second;
    return 0;
}