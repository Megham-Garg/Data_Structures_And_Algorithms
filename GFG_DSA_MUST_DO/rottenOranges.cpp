#include<bits/stdc++.h>
using namespace std;
#define ll long long;
// void printQ(queue<pair<int,int>> q){
//     cout << "\n***\n";
//     while(!q.empty()) {cout << q.front().first << " : " << q.front().second << "\n"; q.pop();}
// }
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
        int r, c; cin >> r >> c; int a[r][c]={0}; int c1 = 0; queue<pair<int,int>> q;
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) { cin >> a[i][j]; if(a[i][j]==1) c1++; if(a[i][j]==2) q.push(make_pair(i,j));}
        int ans = -1;
        while(!q.empty()){
            int turns = q.size();
            // printQ(q);
            while(turns--){
                pair<int, int> node = q.front();
                int i = node.first;
                int j = node.second;
                if(i+1<=r-1 && a[i+1][j]==1){c1--; q.push(make_pair(i+1,j)); a[i+1][j]=2;}
                if(i>0 && a[i-1][j]==1){c1--; q.push(make_pair(i-1,j)); a[i-1][j]=2;}
                if(j+1<=c-1 && a[i][j+1]==1){c1--; q.push(make_pair(i,j+1)); a[i][j+1]=2;}
                if(j>0 && a[i][j-1]==1){c1--; q.push(make_pair(i,j-1)); a[i][j-1]=2;}
                q.pop();
            }
            ans++;
        }
        cout << ((c1!=0)?-1:ans) << "\n";
	}
	return 0;
}
