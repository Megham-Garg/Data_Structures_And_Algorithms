#include<iostream>
#include<queue>
using namespace std;
struct interval{
    int buy;
    int sell;
};
void stockBS(int a[], int n){
    if(n==1) return;
    int count = 0;
    vector<struct interval> ans(n/2+1);
    int i = 0;
    while(i < n){
        while(i < n-1 && (a[i] >= a[i+1])) i++;
        if(i==n-1) break;
        ans[count].buy = i++;
        
        while(i < n && (a[i] >= a[i-1])) i++;
        ans[count].sell = i-1;
        count++;
    }
    if(count == 0) cout << "No Profit\n";
    else{
        for(ele:ans){
            cout << "(" << ele.buy << " " << ele.sell << ") ";
            count--;
            if(!count) break;
        }
        cout << "\n";
    }
}
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int n; cin >> n;
	    int a[n] = {0};
	    vector<int> ans;
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    stockBS(a,n);
	}
	return 0;
}
