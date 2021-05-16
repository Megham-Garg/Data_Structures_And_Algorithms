#include<iostream>
#include<limits.h>
using namespace std;
#define max(a,b) (a>b)?a:b

int main()
 {
	int t = 0;
	cin >> t;
	while(t--){
        int n;cin>>n;
        int arr[n]={0};
        for(int _ = 0; _ < n; _++) cin>>arr[_];
        
        int x=arr[0];
        int y=arr[0];
        
        for(int i=1; i<n; i++){
            x=max(arr[i]+x,arr[i]);
            y=max(x,y);
        }
        cout<<y<<"\n";
	}
	return 0;
}
