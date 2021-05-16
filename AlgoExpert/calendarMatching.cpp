#include<bits/stdc++.h>
using namespace std;

// let meet slots in calendar 1 be n
// let meet slots in calendar 2 be m
// O(n+m) space and time
pair<int, int> minTime(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return a;
    else if(b.first < a.first) return b;
    else{
        if(a.second < b.second) return a;
    }
    return b;
}

pair<int, int> maxTime(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return b;
    else if(b.first < a.first) return a;
    else{
        if(a.second < b.second) return b;
    }
    return a;
}

int timeDiff(pair<int, int> a, pair<int, int> b){
    return (b.first - a.first)*60 + b.second - a.second;
}

int main(){
    vector<pair<int, int>> meet1,meet2,result;
    int dur = 30;
    pair<pair<int, int>, pair<int, int>> sch1, sch2;
    meet1 = {make_pair(9,0), make_pair(10,30), make_pair(12,0), make_pair(13,0), make_pair(16,0), make_pair(18,0)};
    meet2 = {make_pair(10,0), make_pair(11,30), make_pair(12,30), make_pair(14,30), make_pair(14,30), make_pair(15,0), make_pair(16,0), make_pair(17,0)};
    sch1 = make_pair(make_pair(9,0), make_pair(20,0)); sch2 = make_pair(make_pair(10,0), make_pair(18,30));

    pair<int, int> dayStart = maxTime(sch1.first, sch2.first), dayEnd = minTime(sch1.second, sch2.second);

    if(dayStart == maxTime(dayStart, dayEnd)) cout << "Not possible today\n";
    else{
        vector<pair<int, int>> avail1, avail2;
        pair<int, int> end,a,b;
        for(int i = 2; i < meet1.size(); i+=2){
            a = maxTime(dayStart, meet1[i-1]);
            b = minTime(dayEnd,   meet1[i]);
            if(timeDiff(a,b) < dur) continue;
            avail1.push_back(a);
            avail1.push_back(b);
        }
        end = meet1.back();
        if(timeDiff(end, dayEnd) >= dur){
            avail1.push_back(end);
            avail1.push_back(dayEnd);
        }
        for(int i = 2; i < meet2.size(); i+=2){
            a = maxTime(dayStart, meet2[i-1]);
            b = minTime(dayEnd,   meet2[i]);
            if(timeDiff(a,b) < dur) continue;
            avail2.push_back(a);
            avail2.push_back(b);
        }
        end = meet2.back();
        if(timeDiff(end, dayEnd) >= dur){
            avail2.push_back(end);
            avail2.push_back(dayEnd);
        }
        for(auto ele : avail1){
            cout << ele.first << ":" << ele.second << " ";
        }cout << "\n";
        for(auto ele : avail2){
            cout << ele.first << ":" << ele.second << " ";
        }cout << "\n";

        int i=0, j=0;
        while(j < avail2.size() && i < avail1.size()){
            if(timeDiff(avail1[i+1], avail2[j]) >= 0) i+=2;
            else if(timeDiff(avail1[i], avail2[j+1]) < 0) j+=2;
            else{
                a = maxTime(avail1[i], avail2[j]);
                b = minTime(avail1[i+1], avail2[j+1]);
                if(timeDiff(a,b) >= dur) {
                    result.push_back(a);
                    result.push_back(b);
                }
                if(b == avail2[j+1]) j+=2;
                else i+=2;
            }
        }
        
    }
    for(auto ele : result){
        cout << ele.first << ":" << ele.second << " ";
    }cout << "\n";
    return 0;
}