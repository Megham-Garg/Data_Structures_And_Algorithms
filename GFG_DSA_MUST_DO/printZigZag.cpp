#include<iostream>
using namespace std;
int main()
 {
	int testCases = 0;
	cin >> testCases;
	for(int i =1 ; i<=testCases ;i++)
	{
	    int s;cin>>s;
	    int a[s]={0};
	    for(int j=0;j<s;j++) cin>>a[j];
	    
	    for(int j=0;j<s-1;j++){
	        if(s==1 || s==0) break;
	        
	        if(j%2==0 && a[j+1]<a[j]){
	            int t=a[j+1];
	            a[j+1]=a[j];
	            a[j]=t;
	        }
	        else if(j%2==1 && a[j+1]>a[j]){
	            int t=a[j+1];
	            a[j+1]=a[j];
	            a[j]=t;
	        }
	    }
	    for(int j=0;j<s;j++) cout<<a[j]<<" ";
	    cout<<endl;
	}
	return 0;
}
