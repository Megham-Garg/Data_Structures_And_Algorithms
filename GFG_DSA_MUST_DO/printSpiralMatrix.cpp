#include<iostream>
using namespace std;
#define ll long long;
int main(){
	int testCases = 0; cin >> testCases;
	while(testCases--){
	    int m,n; cin >> m >> n;
	    int mat[m][n]={0};
        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) cin >> mat[i][j];
        int count = m*n;
        int i = 0;
        while(count){
            for(int k = i; k < n; k++){
                cout << mat[i][k] << " ";
                count--;
            }
            for(int k = i+1; k < m; k++){
                cout << mat[k][n-1] << " ";
                count--;
            }
            for(int k = n-2; k >= i && i!=m-1; k--){
                cout << mat[m-1][k] << " ";
                count--;
            }
            for(int k = m-2; k >= i+1 && i!=n-1; k--){
                cout << mat[k][i] << " ";
                count--;
            }i++; m--; n--;
        }cout << endl;
	}
	return 0;
}
