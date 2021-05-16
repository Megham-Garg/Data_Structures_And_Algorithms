#include<bits/stdc++.h>
using namespace std;

// O(n^2) space and time
bool sameBSTs(vector<int> a1, vector<int> a2){
    if(a1==a2) return true;
    else if(a1.size()!=a2.size()) return false;
    else if(a1[0] != a2[0]) return false;

    vector<int> b1,b2;
    for(int i = 1; i < a1.size(); i++){
        int ele = a1[i];
        if(ele < a1[0]) b1.push_back(ele);
        else b2.push_back(ele);
    }

    vector<int> c1,c2;
    for(int i = 1; i < a2.size(); i++){
        int ele = a2[i];
        if(ele < a2[0]) c1.push_back(ele);
        else c2.push_back(ele);
    }
    for(auto ele : b1) cout << ele << " ";
    cout << "\n";
    for(auto ele : b2) cout << ele << " ";
    cout << "\n";
    for(auto ele : c1) cout << ele << " ";
    cout << "\n";
    for(auto ele : c2) cout << ele << " ";
    cout << "\n";

    if(c1.empty()&&b1.empty()) return sameBSTs(b2, c2);
    else if(c2.empty()&&b2.empty()) return sameBSTs(b1, c1);
    else return sameBSTs(b1, c1) && sameBSTs(b2, c2);
}

bool helpersameBSTsv2(vector<int> a, vector<int> b, int i, int j, int l, int r){
    cout << i << " " << j << " " << l << " " << r << " \n";
    int tar1 = i+1, tar2 = j+1;
    while(!(a[tar1] > l && a[tar1] < a[i]) && tar1 < a.size()) tar1++;
    while(!(b[tar2] > l && b[tar2] < b[j]) && tar2 < b.size()) tar2++;
    bool flag1 = 0;
    if(tar1 < a.size() && tar2 < b.size() && a[tar1] == b[tar2]) flag1 = helpersameBSTsv2(a,b,tar1,tar2,l,a[i]);
    else if(tar1 == a.size() && tar2 == b.size()) flag1 = 1;

    tar1 = i+1, tar2 = j+1;
    while(!(a[tar1] >= a[i] && a[tar1] < r) && tar1 < a.size()) tar1++;
    while(!(b[tar2] >= b[j] && b[tar2] < r) && tar2 < b.size()) tar2++;
    bool flag2 = 0;
    if(tar1 < a.size() && tar2 < b.size() && a[tar1] == b[tar2]) flag2 = helpersameBSTsv2(a,b,tar1,tar2,a[i],r);
    else if(tar1 == a.size() && tar2 == b.size()) flag2 = 1;
    
    return flag1 && flag2;
}

bool sameBSTsv2(vector<int> a, vector<int> b){
    if(a.size()!=b.size()) return 0;
    else if(a == b) return 1;
    return helpersameBSTsv2(a,b,0,0,INT_MIN,INT_MAX);
}

int main(){
    vector<int> a1 = {10,15,8,12,94,81,5,2,11};
    vector<int> a2 = {10,8,5,15,2,12,11,94,81};
    cout << (sameBSTsv2(a1, a2)?"Both are same":"something wrong!!");
}